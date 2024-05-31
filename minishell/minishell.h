/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:41:13 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/31 22:21:28 by fkeitel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
-------------------------------- INITIAL SETUP ---------------------------------
 */

//	header file
#ifndef MINISHELL_H
# define MINISHELL_H

/* ------------------------------- DEFINITIONS ------------------------------ */

# define MAX_COMMAND_LENGTH 1024
# define MAX_ARGS 64
# define MAX_HISTORY 100

//	type list
# define EXEC 1
# define REDIR 2
//	command list
# define REDIR_IN 1
# define REDIR_OUT 2
# define DELIM 3
# define REDIR_OUT_AP 4
# define HERE_DOC 5
//	instructions
# define ECHO 1
# define CD 2
# define PWD 3
# define EXPORT 4
# define UNSET 5
# define ENV 6
# define EXIT 7

/* -------------------------------- LIBRARIES ------------------------------- */

//	public libraries
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <sys/stat.h>
//	private	libraries
# include "libft/libft.h"

/* -------------------------------- STRUCTS --------------------------------- */

//	linked list for a env copy
typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

//	main struct, if there is a pipe, it will be in child_pipe
typedef struct s_parse_tree
{
	int					type;
	int					command;
	char				*here_doc;
	char				**args;
	int					*arrow_quote;
	int					args_num;
	char				*cmd_brch;
	struct s_parse_tree	*parent_pipe;
	struct s_parse_tree	*child_pipe;
	int					output;
	int					pipes_num;
	int					exit_status;
	int					signal_exit;
	int					stdinput;
	int					stdoutput;
	int					out_fd;
	int					in_fd;
	t_env				**env;
}	t_tree;

/*
---------------------------------- FUNCTIONS -----------------------------------
*/
//-------------------------------- builtins ------------------------------------

//builtin_handler.c
int		handle_builtins(t_tree *tree, t_env **env_lst, int *exec_exit);
void	update_exit(t_tree *tree, int exec_exit);
//echo.c
void	ft_echo(t_tree *tree);
//pwd.c
void	ft_pwd(t_tree *tree);
//cd.c
void	ft_chdir(t_tree *tree, t_env **env_lst);
//env.c
void	print_env(t_tree *tree);
//unset.c
void	ft_unset(t_tree *tree, char	*env);
//export.c
void	export(t_tree *tree, char *new_env);
void	export_env(t_tree *tree);
int		name_check(char *tmp, t_tree *tree);
int		export_err(char *name, t_tree *tree);

//----------------------------- clean functions --------------------------------

//	clean.c
void	free_tree(t_tree *parse_tree);
void	ft_free(char **split, int words);
void	free_env_list(t_env **env_list);
void	print_list(t_env *env_list);
void	free_parent_tree(t_tree **parse_tree);

//---------------------------- redirect functions ------------------------------

//	here_doc.c
int		skip_here(int *i, char *str, char *here_doc);
char	*create_str(char *str, char *here_doc);
char	*create_heredoc(char **str, char *cmd_str, t_tree *tree);
char	*handle_heredoc(char *cmd_str, t_tree *tree);
//	append.c
char	*handle_append(char *cmdstr, t_tree *tree);
int		validate_outfile(char *outfile, t_tree *tree);
//	trunc.c
char	*handle_trunc(char *cmdstr, t_tree *tree);
//	infile.c
char	*handle_infile(char *cmd_str, t_tree *tree);
char	*empty_str(void);

//------------------------------ util functions --------------------------------

//	lst_utils.c
t_env	**init_env_list(char **envp);
void	lstadd_back_env(t_env **lst, t_env *new);
t_env	*init_node(char *envp);

//----------------------------- error functions --------------------------------

//	error.c
int		pipes_error(char *errorstr, t_tree *tree, char **array);
int		print_str_return_exit(char *str, int exit_code, t_tree *tree);
//--------------------------- execution functions ------------------------------

//	execute.c
void	execute_command(t_tree *tree);
char	**create_env_array(t_env *env_lst);
char	*ft_getenv(t_env *env_lst, char *name);
void	open_close_fds(t_tree *tree);
//	get_path_functions.c
char	*ft_getenv(t_env *env_lst, char *name);
char	**get_paths(t_env **env_lst);
char	*get_cmdpath(char *cmd, t_env **env_lst, t_tree *tree);
int		join_name_value(t_env *env_node, char **env_array, int i);
void	absolute_path(t_tree *tmp, char **env_array);

//----------------------------- helper functions -------------------------------

//	helper_1.c
void	remove_char(char *str, char char_to_remove, int start, int *end);
void	ft_treeadd_back(t_tree **lst, t_tree *new, t_tree **parent);
int		alloc_string(char **s, int result_len);
int		create_var_and_rep_str(char **var, char	**replace, char *arg, int j);
int		join_name_value(t_env *env_node, char **env_array, int i);

//---------------------------- parsing functions -------------------------------

//	parse_redirects.c
void	red_counter(t_tree *tree, int z, int counter);
int		check_for_redirections(t_tree *tree, char ***args, int i, int j);
int		update_args(char ***args);
//	redirec_helper.c
int		update_args(char ***args);
//	parsing.c
int		init_tree(t_tree *tree, char **pipes, int ex_st, int i);
int		parse_command(char **command, t_tree **tree);
//	process_arg_str.c
char	*ft_fgets(void);
int		adapt_and_count_arguments(t_tree *tree, char **command_str, int *ex_st);
int		split_command(t_tree *tree, char **command_str, int ex_st);
int		build_command_tree(t_tree **tree, char *cmd_str, char **pipes, int i);
char	**handle_redirects(char **args, t_tree *tree);
//	quote_check.c
int		check_for_quotes_and_slash(char *command_str);
int		check_for_open_quotes(char letter, int *s_quote, int *d_quote);
int		det_and_rem_quotes_first_word(char *command_str);
int		both_quote_checker(char *arg, int j);
int		quote_checker(char *arg, int j);
int		remove_quotes(char **args, int i);
//	replace_variable.c
int		expander(char **args, t_env **env, int ex_st);
//	split_pipes.c
void	count_pipes(char const *s, char pipe, int *pipe_num);
int		quote_check(const char *s, int *pipe_len, char pipe, int *i);
int		assign_pipes(char const *s, char pipe, char **split, int pipes);
char	**split_with_quotes(char **s, char c, int *pipe_num);

//---------------------------- signal functions -------------------------------

//	signal.c
void	signal_handle(int signo);
void	signal_handler(int sig);

//---------------------------- debugging functions ----------------------------

void	print_parse_tree(const t_tree *tree);
void	print_2d_array(char **array);

//------------------------------------- end -----------------------------------
#endif
