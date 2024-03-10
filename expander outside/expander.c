#include "expander.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n && s1[i] && s2[i] && (s1[i] == s2[i]))
	{
		++i;
		--n;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*indeed_expand(char *to_expand, char *before_equal[], char **after_equal)
{
	int	k;

	k = 0;
	while (before_equal[k] != NULL)
	{
		if (ft_strncmp(to_expand, before_equal[k],
				ft_strlen(before_equal[k])) == 0)
			break ;
		k++;
	}
	return (after_equal[k]);
}

int	check_if_expand(char *str, char **before_equal, char *c)
{
	//int	k;
	int i;

	i = 0;
	printf("inside check_if_expand : %s\n", c);

	while(before_equal[i] != NULL)
	{
		printf("this is the env var : %s\n", before_equal[i]);
		i++;
	}
	//k = 0;
	if (str[0] == '$')
	{
		while (*before_equal != NULL)
		{
			if (ft_strncmp(str, *before_equal, ft_strlen(*before_equal)) == 0)
				return (1);
			before_equal++;
			//k++;
		}
	}
	return (0);
}

char *assemble(char **strings_to_assemble)
{
    char *assembled_string;
    int total_n = 0; // Initialize total_n here
    int i = 0;
    
    // Count the total number of characters in all strings
    while (strings_to_assemble[i] != NULL)
    {
        total_n += strlen(strings_to_assemble[i]);
        i++;
    }
    
    // Allocate memory for assembled string (+1 for null terminator)
    assembled_string = calloc(total_n + 1, sizeof(char));
    if (assembled_string == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    // Concatenate all strings into assembled_string
    i = 0;
    int offset = 0; // Keep track of the offset in assembled_string
    while (strings_to_assemble[i] != NULL)
    {
        strcat(assembled_string + offset, strings_to_assemble[i]);
        offset += strlen(strings_to_assemble[i]);
        i++;
    }
	printf("here is the assembled string inside of the assemble function : %s\n", assembled_string);
    return assembled_string;
}

// void	print_before_equal(char **before_equal)
// {
// 	int	i;

// 	printf("Before equal array:\n");
// 	i = 0;
// 	while (before_equal[i] != NULL)
// 	{
// 		printf("[%d]: %s\n", i, before_equal[i]);
// 		i++;
// 	}
// 	printf("last is null ? : %s\n", before_equal[i]);
// }

// void	print_after_equal(char **after_equal)
// {
// 	int	i;

// 	printf("After equal array:\n");
// 	i = 0;
// 	while (after_equal[i] != NULL)
// 	{
// 		printf("[%d]: %s\n", i, after_equal[i]);
// 		i++;
// 	}
// 	printf("last is null ? : %s\n", after_equal[i]);
// }

char	*expand_and_assemble(char **str, char **before_equal,
		char **after_equal)
{
	int		i;
	int		n;
	char	**expanded_str;
	char	*assembled_expanded_str;

	i = 0;
	n = 0;
	(void)i;
	while (str[n] != NULL)
		n++;
	expanded_str = calloc(n + 1, sizeof(char *));
	while(str[i] != NULL)
	{
		printf("%s\n", str[i]);
		i++;
	}
	// printf("%s\n", str[i]);
	// Inside expand_and_assemble function
	// printf("Before expand_and_assemble:\n");
	// print_before_equal(before_equal);
	// printf("\n");
	// printf("After expand_and_assemble:\n");
	// print_after_equal(after_equal);
	// printf("\n");
	i = 0;
	///// ! to uncomment
	while (i < n)
	{
		if ((check_if_expand(str[i], before_equal, "exp_and_ass")))
		{
			printf("from expand and assemble\n");
			expanded_str[i] = indeed_expand(str[i], before_equal, after_equal);
		}
		else
			expanded_str[i] = strdup(str[i]);
		printf("i is %d\n", i);
		i++;
	}
	expanded_str[i] = NULL;
	assembled_expanded_str = assemble(expanded_str);
	printf("this is the assembled & expanded string : %s\n", assembled_expanded_str);
	printf("out of expand_and_assemble\n");
	//! assembled_expanded_str has the NULL address
	return (assembled_expanded_str);
}

char	*remove_single_quote(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = ft_strlen(str) - 2;
	j = 0;
	new_str = calloc(i + 1, sizeof(char));
	while (j > i)
	{
		new_str[j] = str[j + 1];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

int	single_quote_doll(char *str)
{
	if ((str[0] == '\'') && (str[1] = '$'))
		return (1);
	else
		return (0);
}

char	**remove_wrong_env_var(char **str, char **before_equal)
{
	int		i;
	int		j;
	int		k;
	char	**removed_wrong_env_var;

	printf("inside remove_wrong_env_var\n");
	i = 0;
	j = 0;
	k = 0;
	while (str[i] != NULL)
	{
		if ((str[i][0] == '$' && check_if_expand(str[i], before_equal, "rem1"))
			|| (str[i][0] != '$' && str[i][0] != '\'')
				|| single_quote_doll(str[i]))
			j++;
		i++;
	}
	removed_wrong_env_var = calloc(i + 1, sizeof(char *));
	i = 0;
	(void)j;
	while (str[i] != NULL)
	{
		if ((str[i][0] == '$' && check_if_expand(str[i], before_equal, "rem2"))
			|| (str[i][0] != '$' && str[i][0] != '\'')
				|| single_quote_doll(str[i]))
		{
			if (single_quote_doll(str[i]))
				removed_wrong_env_var[k] = remove_single_quote(str[i]);
			removed_wrong_env_var[k] = str[i];
			k++;
		}
		i++;
	}
	removed_wrong_env_var[i] = NULL; // ^ not sure if needed
	int l = 0;                       // todo remove this part
	while (removed_wrong_env_var[l] != 0)
	{
		printf("string %d in removed wrong env var is : %s\n", l + 1,
			removed_wrong_env_var[l]);
		l++;
	}
	return (removed_wrong_env_var);
}

int	check_dollar_word_expand(char **dollar_separated_str, char **before_equal)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("inside check_dollar_word_expand\n");
	while (dollar_separated_str[i] != NULL)
	{
		if (dollar_separated_str[i][0] == '$')
		{
			if (check_if_expand(dollar_separated_str[i], before_equal,
					"check_doll_word_exp"))
				j++;
		}
		i++;
	}
	printf("the return (value is %d inside check_dollar_word_expand\n", j);
	return (j);
}

int	check_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

t_token	*expander(t_token *tokenized_tokens, char **env)
{
	t_lists_env	lists_env;
	char		**before_equal;
	char		**after_equal;
	char **divided_by_dollar;

	int i = 0; // ! to delete
	lists_env = split_lists_env(env);
	before_equal = lists_env.before_equal;
	after_equal = lists_env.after_equal;
	// (void)before_equal;
	// (void)after_equal;
	// while(*before_equal)
	// {
	// 	printf("%s\n", *before_equal);
	// 	before_equal++;
	// }
	// while(*after_equal)
	// {
	// 	printf("%s\n", *after_equal);
	// 	after_equal++;
	// }
	while (tokenized_tokens != NULL)
	{
		if (tokenized_tokens->type == TOKEN_WORD)
		{
			if (check_dollar(tokenized_tokens->value))
			{
				printf("check dollar is passed\n");
				divided_by_dollar = new_ft_split(tokenized_tokens->value, '\'');
				printf("split the single quotes word is passed\n");
				while (divided_by_dollar[i] != NULL)
				{
					printf("%s\n", divided_by_dollar[i]);
					i++;
				}
				// todo ajouter une condtion dans ft_split double qui ne split pas les str qui commence par '$
				divided_by_dollar = ft_split_double(divided_by_dollar, '$');
				printf("split the words with dollar is passed\n");
				i = 0;
				while (divided_by_dollar[i] != NULL)
				{
					printf("%s\n", divided_by_dollar[i]);
					i++;
				}
				printf("%s\n", divided_by_dollar[i]);
				printf("about to enter the check_dollar_word_expand\n");
				if ((check_dollar_word_expand(divided_by_dollar,
							before_equal)) > 1)
				{
					printf("check dollar word expand passed successfully");
					divided_by_dollar = remove_wrong_env_var(divided_by_dollar,
							before_equal);
				}


				
				else
					printf("check dollar word expand return (value is 0 or negative\n");
				tokenized_tokens->value = expand_and_assemble(divided_by_dollar,
						before_equal, after_equal);
				// free(divided_by_dollar);
			}
			// todo : did I tackle giving back the empty string when encoutering a wrong env var ?
		}
		tokenized_tokens = tokenized_tokens->next;
	}
	// make a function that gets back at the beginning of the linked list
	return (tokenized_tokens);
}

int main(int argc, char **argv, char **env)
{
    t_token *tokenized_tokens;
    t_token *current_token;
    t_token *next_token;

    // Sample tokenized input
    (void)argc;
    (void)argv;
    tokenized_tokens = malloc(sizeof(t_token));
    tokenized_tokens->type = TOKEN_WORD;
    tokenized_tokens->value = strdup("$USER $SHELL Hello '$USER', your home directory is $HOME");
    tokenized_tokens->next = NULL;

    // Call the expander function
    tokenized_tokens = expander(tokenized_tokens, env);

	printf("we are back in the main\n");
    // Print the expanded tokens
    current_token = tokenized_tokens;
	printf("Token: %s\n", current_token->value);
    while (current_token != NULL)
    {
        if (current_token->value != NULL)
        {
            printf("Token: %s\n", current_token->value);
            free(current_token->value);
        }
        next_token = current_token->next;
        free(current_token);
        current_token = next_token;
    }
    
    return 0;
}

// remarque : lorsque la env var est entre ' single quotes ' on imprime tel quel --> comment implementer ça ?