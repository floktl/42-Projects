/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:41:13 by fkeitel           #+#    #+#             */
/*   Updated: 2024/05/18 23:53:53 by flo              ###   ########.fr       */
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
//	private	libraries
# include "libft/libft.h"

/* -------------------------------- VARIABLES ------------------------------- */

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
	char				**arguments;
	int					args_num;
	char				*cmd_brch;
	struct s_parse_tree	*parent_pipe;
	struct s_parse_tree	*child_pipe;
	int					output;
	int					pipes_num;
	int					exit_status;
	t_env				**env;
}	t_tree;

/*
---------------------------------- FUNCTIONS -----------------------------------
*/
//-------------------------------- builtins ------------------------------------

//builtin_handler.c
void	handle_builtins(t_tree *tree, t_env **env_lst);
//echo.c
void	ft_echo(t_tree *tree);
//pwd.c
void	ft_pwd(void);
//cd.c
void	ft_chdir(t_tree *tree, t_env **env_lst);
//----------------------------- clean functions --------------------------------

//	clean.c
void	free_tree(t_tree *parse_tree);
void	ft_free(char **split, int words);
void	free_env_list(t_env **env_list);

//---------------------------- command functions -------------------------------

//	command.c

//------------------------------ util functions --------------------------------

//	lst_utils.c
t_env	**init_env_list(char **envp);
void	lstadd_back_env(t_env **lst, t_env *new);
t_env	*init_node(char *envp);

//----------------------------- error functions --------------------------------

//	error.c
int		pipes_error(char *errorstr, t_tree *tree, char **array);
//--------------------------- execution functions ------------------------------

//	execute.c
void	execute_command(t_tree *tree);
char	**create_env_array(t_env *env_lst);

//----------------------------- helper functions -------------------------------

//	helper_1.c
void	remove_char(char *str, char char_to_remove, int start, int *end);
void	ft_treeadd_back(t_tree **lst, t_tree *new, t_tree **parent);
int		alloc_string(char **s, int result_len);

//---------------------------- parsing functions -------------------------------

//	flag_checker.c
//int		count_flags(const char *str, int start, char c);
//int		check_for_flag(t_tree *tree, char *cmd_str, int start);
//	parsing.c
void	initiliaze_command_tree(t_tree *tree, int i);
int		parse_command(char **command, t_tree **tree);
//	process_arg_str.c
char	*ft_fgets(void);
int		adapt_and_count_arguments(t_tree *tree, char *command_str);
int		split_command(t_tree *tree, char *command_str);
int		build_command_tree(t_tree **tree, char *command_str);
//	quote_check.c
int		check_for_quotes_and_slash(char *command_str);
int		check_for_open_quotes(char letter, int *s_quote, int *d_quote);
int		det_and_rem_quotes_first_word(char *command_str);
int		quote_checker(char *arg, int j);
//	replace_variable.c
int		expander(char **args, t_env **env_lst, int exit_status);
//	split_pipes.c
void	count_pipes(char const *s, char pipe, int *pipe_num);
int		quote_check(const char *s, int *pipe_len, char pipe, int *i);
int		assign_pipes(char const *s, char pipe, char **split, int pipes);
char	**split_pipes(char const *s, char c, int *pipe_num);

//---------------------------- signal functions -------------------------------

//	signal.c
void	signal_handler(int sig);

//---------------------------- debugging functions ----------------------------

void	print_parse_tree(const t_tree *tree);
void	print_2d_array(char **array);

//------------------------------------- end -----------------------------------
#endif
