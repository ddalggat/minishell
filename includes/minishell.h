/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:04:53 by gjailbir          #+#    #+#             */
/*   Updated: 2021/12/16 17:10:09 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <dirent.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include "../libft/libft.h"


# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define SIL   "\x1B[37m"
# define RESET "\x1B[0m"

# define BUIL_CMD   "cd:echo:env:exit:pwd:unset:export:help"

# define ERR_PIPE	"shell: Syntax error near unexpected token '|'"
# define ERR_NEWL	"shell: Syntax error near newline"
# define ERR_MLC    "shell: Cannot allocate memory"
# define ERR_TKN	"shell: syntax error near unexpected token "

int		g_status;

typedef struct s_cmd
{
	char			**arg;
	t_list			*lst;
	t_list			*redirects;
	int				pipe_fd[2];
	int				std_in;
	int				std_out;
	pid_t			pid;
	bool			is_fork;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
	char	*ps;
	t_list	*env;
	t_cmd	*cmd;
	t_cmd	*cmds;
	int		old_in;
	int		old_out;
	int		cmd_status;
	char	**arr_env;
	char	**buil_cmd;
}	t_shell;

//BUILTINS
int		ft_pwd(void);
int		ft_echo(char **str);
int		ft_env(t_shell *shell);
int		ft_help(t_shell *shell, int i);
int		ft_exit(char **argv, t_shell *msh);
int		ft_cd(char **argv, t_shell *shell);
int		ft_unset(char **argv, t_shell *shell);
int		ft_export(char **argv, t_shell *shell);
int		ft_export_error(char *exp);
void	print_export(char **env);
void	ft_sort_env(t_shell *shell, int len_env);
int		ft_chdir_error(char *dir);
int		ft_set_new_pwd(t_shell *shell);
int		ft_set_new_oldpwd(char *pwd_old, t_shell *shell);

//LOGIC
int		is_builtin(t_shell *shell, char *name);
int		ft_gen_next_path(char **argv, char **paths, char *name, int *z);
void	ft_signal_main(void);
void	ft_signal_pipes(int sig);
void	ft_signal_in_child(void);
void	ft_signal_run_pipes(void);
void	ft_dup_cmd_io(t_cmd *cmd);
void	ft_run_pipes(t_shell *shell);
void	ft_copy_std_io(t_shell *shell);
void	ft_restore_std_io(t_shell *shell);
void	ft_run_builtin(t_shell *shell, t_cmd *cmd, char *name);

//PARSER
int		ft_loop(t_shell *shell);
int		ft_skip_gap(const char *str);
int		ft_parser(t_shell *shell, char *str);
int		ft_get_redirects(t_cmd *cmd, bool is_fork);
void	ft_init_ps(t_shell *shell);
void	ft_init(t_shell *shell, char *envp[]);
char	*ft_get_key(bool digit, char *s, size_t *i);
char	*ft_get_el_env(t_shell *shell, const char *key);
char	*ft_parser_dollar(t_shell *shell, const char *s, size_t *i);

//MINISHELL
int		rl_set_signals(void);
int		ft_print_errno(void);
int		ft_split_len(char **arr);
char	*ft_lst_to_str(t_list *lst);
char	**ft_get_paths(t_shell *shell);
char	**ft_lst_to_array(t_list *lst);
void	*ft_allocate(size_t size);
void	ft_split_free(char **arr);
void	ft_cmd_add_back(t_cmd **lst, t_cmd *new);
void	ft_raise_error_n(char *error_msg, int code);
void	rl_replace_line(const char *buffer, int val);
void	ft_envadd_back(t_list	**chars, char *env_val);
void	ft_raise_error(char *error_msg, char *errno_msg);
void	ft_delete_el_env(t_shell *shell, const char *key);
void	ft_update_el_env(t_shell *shell, const char *keyval);
void	ft_critical_error(char *msg, char *errno_msg, int err);
void	ft_add_keyword(t_shell *shell, t_list **chars, bool is_redirect);
t_cmd	*ft_allocate_cmd(void);
size_t	ft_keylen(const char *keyval);
t_list	*ft_lstpop_find(t_list **lst, const char *key);
t_list	*ft_lstfind(t_list *lst, const char *key);

#endif
