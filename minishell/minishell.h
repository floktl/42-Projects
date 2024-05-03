/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkeitel <fkeitel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:41:13 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/28 11:33:27 by fkeitel          ###   ########.fr       */
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
# define BACKCMD 3
//	command list
# define REDIR_IN 1
# define REDIR_OUT 2
# define DELIM 3
# define REDIR_OUT_AP 4
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
//	private	libraries
# include "libft/libft.h"

/* -------------------------------- VARIABLES ------------------------------- */

/* -------------------------------- STRUCTS --------------------------------- */

//	maybe not necessary
typedef struct s_command
{
	int					type;
	int					flag;
	int					order;
	struct s_command	*next;

}	t_cmd;

//	main struct, if there is a pipe, it will be in child_pipe
typedef struct s_parse_tree
{
	int					type; //type of command EXEC, REDIR, BACKCMD, ...? see # defines above
	int					command;	//	Keywords for our own commands, see # defines above
	// external commands
	char				**flags;	// this we dont need, we can handle them as argumuments
	char				**arguments; // all arguments from the command string
	int					args_num; 	//	like argc
	char				*cmd_brch;	//	string for the exec function
	// env
	struct s_parse_tree	*parent_pipe;	// NUll if there is no parent
	struct s_parse_tree	*child_pipe;	// NULL if there is no children
	int					output;			// output we dont need right?
	int					pipes_num;		// number of pipes, starting with one
	t_cmd				*parsed_command;// see above, maybe unnecessary
}	t_tree;

/*
---------------------------------- FUNCTIONS -----------------------------------
*/

//----------------------------- clean functions --------------------------------

//	clean.c
void	free_tree(t_tree *parse_tree);
void	ft_free(char **split, int words);

//---------------------------- command functions -------------------------------

//	command.c

//----------------------------- error functions --------------------------------

//	error.c
int		pipes_error(char *errorstr, t_tree *tree, char **array);
//--------------------------- execution functions ------------------------------

//	execute.c
void	execute_command(t_tree *tree);

//----------------------------- helper functions -------------------------------

//	helper_1.c
void	remove_char(char *str, char char_to_remove, int start, int *end);
void	ft_treeadd_back(t_tree **lst, t_tree *new, t_tree **parent);

//---------------------------- parsing functions -------------------------------

//	flag_checker.c
int		count_flags(const char *str, int start, char c);
int		check_for_flag(t_tree *tree, char *cmd_str, int start);
//	parsing.c
void	initiliaze_command_tree(t_tree *tree, int i);
t_tree	*parse_command(char *command);
//	process_arg_str.c
char	*ft_fgets(void);
int		adapt_and_count_arguments(t_tree *tree, char *command_str);
int		split_command(t_tree *tree, char *command_str);
int		build_command_tree(t_tree **tree, char *command_str);
//	quote_check.c
int		check_for_quotes(char *command_str);
int		check_for_open_quotes(char letter, int *s_quote, int *d_quote);
int		det_and_rem_quotes_first_word(char *command_str);
//	split_pipes.c
void	count_pipes(char const *s, char pipe, int *pipe_num);
int		quote_check(char c, int *pipe_len, char pipe, int *i);
int		assign_pipes(char const *s, char pipe, char **split, int pipes);
char	**split_pipes(char const *s, char c, int *pipe_num);

//---------------------------- signal functions -------------------------------

//	signal.c
void	handle_signal(int signo);

//---------------------------- debugging functions ----------------------------

void	print_parse_tree(const t_tree *tree);
void	print_2d_array(char **array);

//------------------------------------- end -----------------------------------
#endif
