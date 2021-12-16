/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:04:33 by gjailbir          #+#    #+#             */
/*   Updated: 2021/12/16 17:05:54 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

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

#endif
