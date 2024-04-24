/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo <flo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:41:13 by fkeitel           #+#    #+#             */
/*   Updated: 2024/04/24 21:50:10 by flo              ###   ########.fr       */
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

typedef struct s_command
{
	int					type;
	int					flag;
	int					order;
	struct s_command	*next;

}	t_cmd;

typedef struct s_parse_tree
{
	int					type;
	int					command;
	// external commands
	char				**flags;
	char				**arguments;
	int					args_num;
	char				**cmd_brch;
	// env
	struct s_parse_tree	*parent_pipe;
	struct s_parse_tree	*child_pipe;
	int					output;
	int					pipes_num;
	t_cmd				*parsed_command;
}	t_tree;

/*
---------------------------------- FUNCTIONS -----------------------------------
*/

//----------------------------- clean functions --------------------------------

//	clean.c
void	free_tree(t_tree *parse_tree);

//---------------------------- command functions -------------------------------

//	command.c

//----------------------------- error functions --------------------------------

//	error.c

//--------------------------- execution functions ------------------------------

//	execute.c
void	execute_command(char **args);

//----------------------------- helper functions -------------------------------

//	helper_1.c
int		word_cmp(const char *s1, const char *s2, size_t n);
void 	remove_char(char *str, char char_to_remove, int start, int end);
//	split_pipes.c
char	**split_pipes(char const *s, char c);

//---------------------------- parsing functions -------------------------------

//	parsing.c
t_tree	*parse_command(char *command);
//	process_arg_str.c
char	*ft_fgets(void);
int		seperate_pipes(t_tree *tree, char *command_str);
int		check_for_quotes(t_tree *tree, char *command_str);

//---------------------------- signal functions -------------------------------

//	signal.c
void	handle_signal(int signo);

// debugging.c
void	print_parse_tree(const t_tree *tree);

#endif
