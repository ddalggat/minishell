/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:47:19 by nluya             #+#    #+#             */
/*   Updated: 2021/12/16 21:42:01 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_validate_pipes(char *str)
{
	bool	b_pipe;
	bool	b_words;

	b_pipe = false;
	while (*str && g_status == 0)
	{
		if (*str == '|' && !b_words)
			ft_raise_error_n(ERR_PIPE, 258);
		if (*str == '|')
		{
			b_pipe = true;
			b_words = false;
		}
		else if (!ft_strchr(" \t\v", *str))
			b_words = true;
		if (ft_strchr("'\"", *str))
			str += ft_skip_gap(str);
		str++;
	}
	if ((b_pipe && !b_words) && g_status == 0)
		ft_raise_error_n(ERR_NEWL, 258);
}

char	*ft_parser_quotes(t_shell *shell, const char *s, size_t *i)
{
	t_list	*chars;
	char	quote;
	char	*quote_str;

	chars = NULL;
	quote = s[(*i)++];
	while (s[*i] && s[*i] != quote)
	{
		if (s[*i] == '$' && quote == '\"')
			ft_lstadd_back(&chars, ft_lstnew(ft_parser_vars(shell, s, i)));
		else
			ft_lstadd_back(&chars, ft_lstnew(ft_substr(s, (*i)++, 1)));
	}
	if (s[*i])
		(*i)++;
	quote_str = ft_lst_to_str(chars);
	ft_lstclear(&chars, free);
	return (quote_str);
}

void	ft_parser_cmd(t_shell *shell, const char *str, size_t *i)
{
	t_list	*chars;
	bool	is_redirect;

	chars = NULL;
	is_redirect = false;
	if (str[*i] == '<' || str[*i] == '>')
	{
		is_redirect = true;
		ft_lstadd_back(&chars, ft_lstnew(ft_substr(str, (*i)++, 1)));
		if (str[*i - 1] == str[*i])
			ft_lstadd_back(&chars, ft_lstnew(ft_substr(str, (*i)++, 1)));
		while (ft_strchr(" \t\v", str[*i]))
			(*i)++;
	}
	while (str[*i] && !ft_strchr(" <>|\n", str[*i]))
	{
		if (str[*i] == '$')
			ft_envadd_back(&chars, ft_parser_vars(shell, str, i));
		else if (ft_strchr("'\"", str[*i]))
			ft_lstadd_back(&chars, ft_lstnew(ft_parser_quotes(shell, str, i)));
		else
			ft_lstadd_back(&chars, ft_lstnew(ft_substr(str, (*i)++, 1)));
	}
	ft_add_keyword(shell, &chars, is_redirect);
}

void	ft_parser_cmds(t_shell *shell, const char *str)
{
	size_t	i;

	i = 0;
	shell->cmd = ft_allocate_cmd();
	while (str[i] && !g_status)
	{
		if (str[i] == '|')
		{
			ft_cmd_add_back(&shell->cmds, shell->cmd);
			shell->cmd = ft_allocate_cmd();
			i++;
		}
		else if (!ft_strchr(" \t\v", str[i]) && str[i] != '|')
			ft_parser_cmd(shell, str, &i);
		else
			i++;
	}
	ft_cmd_add_back(&shell->cmds, shell->cmd);
}

int	ft_parser(t_shell *shell, char *str)
{
	char	*key_val;

	ft_validate_pipes(str);
	if (g_status != 0)
		return (1);
	ft_parser_cmds(shell, str);
	if (!g_status && shell->cmd && shell->cmd->lst)
	{
		key_val = ft_strjoin("_=", shell->cmd->lst->content);
		ft_update_el_env(shell, key_val);
		free(key_val);
	}
	return (g_status);
}
