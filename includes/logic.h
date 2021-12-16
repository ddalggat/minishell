/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:04:48 by gjailbir          #+#    #+#             */
/*   Updated: 2021/12/16 17:06:09 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGIC_H
# define LOGIC_H

# include "includes.h"

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

#endif
