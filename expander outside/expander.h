#ifndef EXPANDER_H
# define EXPANDER_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <string.h>
# include <ctype.h>

typedef struct s_lists_env
{
    char **before_equal;
    char **after_equal;
} t_lists_env;

typedef enum 
{
    TOKEN_WORD, // cmd
    TOKEN_PIPE, // |
    TOKEN_INPUT_REDIRECTION, // <
    TOKEN_OUTPUT_REDIRECTION, // >
    TOKEN_APPEND_OUTPUT_REDIRECTION, // >>
    TOKEN_HEREDOC, // <<
    TOKEN_NL // \n

} t_token_type;

typedef struct s_token
{
	t_token_type		type;
	char				*value;
	struct s_token		*next;
	struct s_token		*prev;
}	t_token;

size_t	ft_strlen(const char *s);
int     ft_check_expand(char *str, int i, char **env);
char    *ft_find_env_var_part2(char *str);
char    **ft_split(char *str, char c);
char    **new_ft_split(char *str, char c);
char    **ft_split_double(char **str, char c);
int ft_strncmp(char *s1, char *s2, size_t n);
int	check_if_expand(char *str, char **before_equal , char *c); //! added in edit
t_lists_env	split_lists_env (char **env);
t_token *expander(t_token *tokenized_tokens, char **env);

#endif