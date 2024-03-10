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

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	s = (char *) s;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// static int	ft_nbr_words(char const *s, char c)
// {
// 	int	announce;
// 	int	n;

// 	n = 0;
// 	announce = 0;
// 	while (*s)
// 	{
// 		if (*s != c && announce == 0)
// 		{
// 			announce = 1;
// 			n++;
// 		}
// 		else if (*s == c)
// 			announce = 0;
// 		s++;
// 	}
// 	return (n);
// }

// static char	*ft_cutter(char const *s, int begin, int end)
// {
// 	char	*str;
// 	int		n;

// 	n = 0;
// 	str = malloc (sizeof(char) * (end - begin + 1));
// 	while (begin < end)
// 	{
// 		str[n++] = s[begin++];
// 	}
// 	str[n] = '\0';
// 	return (str);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**str_arr;
// 	size_t	i;
// 	size_t	j;
// 	int		index;

// 	str_arr = malloc (sizeof(char *) * (ft_nbr_words(s, c) + 1));
// 	if (!str_arr || !s)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	index = -1;
// 	while (i <= ft_strlen(s))
// 	{
// 		if (s[i] != c && index < 0)
// 			index = i;
// 		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
// 		{
// 			str_arr[j++] = ft_cutter(s, index, i);
// 			index = -1;
// 		}
// 		i++;
// 	}
// 	str_arr[j] = 0;
// 	return (str_arr);
// }



// char	*ft_strchr(const char *s, int c)
// {
// 	size_t	len;
// 	size_t	j;

// 	j = 0;
// 	len = ft_strlen(s);
// 	if (s[j] == (char)c)
// 	{
// 		return ((char *) &s[j]);
// 	}
// 	while (s[j] != (char)c && j < len)
// 	{
// 		j++;
// 		if (s[j] == (char)c)
// 		{
// 			return ((char *) &s[j]);
// 		}
// 	}
// 	return (NULL);
// }

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (src[i] != '\0')
// 	{
// 		i++;
// 	}
// 	if (size == 0)
// 	{
// 		return (i);
// 	}
// 	while (j < size - 1 && src[j] != '\0')
// 	{
// 		dst[j] = src[j];
// 		j++;
// 	}
// 	dst[j] = '\0';
// 	return (i);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*s_new;
// 	size_t	s_new_len;
// 	int		s_len;

// 	s_len = ft_strlen((char *)s);
// 	if (start >= ft_strlen((char *)s))
// 	{
// 		s_new = malloc (sizeof(char));
// 		if (!s_new)
// 			return (NULL);
// 		*s_new = '\0';
// 		return (s_new);
// 	}
// 	if (len <= s_len - start)
// 		s_new_len = len;
// 	else
// 		s_new_len = s_len - start;
// 	s_new = malloc (sizeof(char) * s_new_len + 1);
// 	if (s_new == NULL)
// 		return (0);
// 	ft_strlcpy(s_new, &s[start], s_new_len + 1);
// 	return (&s_new[0]);
// }

// static size_t	ft_countword(char const *s, char c)
// {
// 	size_t	count;

// 	if (!*s)
// 		return (0);
// 	count = 0;
// 	while (*s)
// 	{
// 		while (*s == c)
// 			s++;
// 		if (*s)
// 			count++;
// 		while (*s != c && *s)
// 			s++;
// 	}
// 	return (count);
// }

// char **ft_split(const char *s, char c)
// {
//     char    **lst;
//     size_t  word_len;
//     int     i;

//     lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
//     if (!s || !lst)
//         return (0);
//     i = 0;
//     while (*s)
//     {
//         while (*s == c && *s)
//             s++;
//         if (*s)
//         {
//             const char *next_c = ft_strchr(s, c);
//             if (!next_c) {
//                 // If no more occurrences of separator, set word_len to the length until the end of the string
//                 word_len = ft_strlen(s);
//             } else {
//                 // Include the separator in the substring
//                 word_len = next_c - s + 1;
//             }
//             lst[i++] = ft_substr(s, 0, word_len);
//             s += word_len;
//         }
//     }
//     lst[i] = NULL;
//     return (lst);
// }

// void print_strings(char **strings)
// {
//     int i = 0;
//     while (strings[i] != NULL)
//     {
//         printf("%s\n", strings[i]);
//         i++;
//     }
// }

// int main()
// {
//     char *str = "$USER$hello.    hello";
//     char **split_strings = ft_split(str, '$');
//     if (split_strings)
//     {
//         printf("Split strings:\n");
//         print_strings(split_strings);
//     }
//     else
//     {
//         printf("Memory allocation failed.\n");
//     }
//     return 0;
// }
size_t	ft_strlen(const char *s)
{
	size_t	i;

	s = (char *) s;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	size_t	j;

	j = 0;
	len = ft_strlen(s);
	if (s[j] == (char)c)
	{
		return ((char *) &s[j]);
	}
	while (s[j] != (char)c && j < len)
	{
		j++;
		if (s[j] == (char)c)
		{
			return ((char *) &s[j]);
		}
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	if (size == 0)
	{
		return (i);
	}
	while (j < size - 1 && src[j] != '\0')
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_new;
	size_t	s_new_len;
	size_t		s_len;

	s_len = ft_strlen((char *)s);
	if (start >= ft_strlen((char *)s))
	{
		s_new = malloc (sizeof(char));
		if (!s_new)
			return (NULL);
		*s_new = '\0';
		return (s_new);
	}
	if (len <= s_len - start)
		s_new_len = len;
	else
		s_new_len = s_len - start;
	s_new = malloc (sizeof(char) * s_new_len + 1);
	if (s_new == NULL)
		return (0);
	ft_strlcpy(s_new, &s[start], s_new_len + 1);
	return (&s_new[0]);
}
int ft_countword(const char *s, char c)
{
    int count = 0;
    while (*s)
    {
        while (*s == c)
            s++;
        if (*s)
            count++;
        while (*s != c && *s)
            s++;
    }
    return count;
}

char **ft_split(const char *s, char c)
{
    char    **lst;
    size_t  word_len;
    int     i;

    lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
    if (!s || !lst)
        return (0);
    i = 0;
    while (*s)
    {
        while (*s == c && *s)
            s++;
        if (*s)
        {
            const char *next_c = ft_strchr(s, c);
            if (!next_c) {
                // If no more occurrences of separator, set word_len to the length until the end of the string
                word_len = ft_strlen(s);
            } else {
                // Include the separator in the substring
                word_len = next_c - s + 1;
            }
            lst[i++] = ft_substr(s, 0, word_len);
            s += word_len;
        }
    }
    lst[i] = NULL;
    return (lst);
}

char *fill_the_word(char *str, int end, int start , char *lst)
{
    int i;

    i = 0;
    while(i < end - start)
    {
        lst[i] = str[start + i];
        i++;
    }
    lst[i] = 0;
    return(lst);
}

char **rest_of_split(char *str, char c)
{
    char **lst;
    size_t word_len;
    int i;
    int j;
    int reset;

    reset = 0;
    j = 0;
    lst = (char **)malloc((ft_countword(str, c) + 1) * sizeof(char *));
    if (!str || !lst)
        return NULL;
    i = 0;
    while (str[i] != '\0')
    {
        while ((reset > 0 && str[i] != c) || reset == 0)
        {
            i++;
            reset++;
            if (str[i] == 0)
              break;
        }
        lst[j] = calloc (reset + 1, sizeof(char));
        lst[j] = fill_the_word(str, i, (i - reset), lst[j]);
        j++;
        reset = 0;
    }
    lst[j] = 0;
    // Add code to populate lst with the rest of the split strings
    return lst;
}

 // la j'ai une double d array avec le nombre de slot necessaire
 // la je vais mettre tout depuis le debut dans une str jusqu'à ce que je trouve une char c ou que j'arrive à la fin
 // si j'ai trouvé une char c je vais m&lloc la taille de ce que j'ai comme compteur - une valeur de debut
 // ! ne pas oublier de reculer de 1 en terme d'index pour pouvoir etre au niveau du charactère que je dois verifier
 // apres je vais mettre toutes les lettres de la valeur de debut jusqu'à la fin dans la str de l'index correct de la double d array que je viens de creer
 // ensuite je vais remplir la prochaine str de la double d array
 // ! à ce moment là je serai juste avant un $ donc il faut avoir une sorte de condition qui permet de passer le premier dollar en mode c'est okay. ça pourrait etre utile au cas ou le dollar est le premier char aussi 


void print_strings(char **strings)
{
    int i = 0;
    while (strings[i] != NULL)
    {
        printf("%s\n", strings[i]);
        i++;
    }
}



// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// size_t ft_strlen(const char *s)
// {
//     size_t len = 0;
//     while (s[len] != '\0')
//         len++;
//     return len;
// }

// char *ft_strchr(const char *s, int c)
// {
//     while (*s != '\0')
//     {
//         if (*s == c)
//             return (char *)s;
//         s++;
//     }
//     if (c == '\0')
//         return (char *)s;
//     return NULL;
// }

// char *ft_substr(const char *s, unsigned int start, size_t len)
// {
//     char *substr = (char *)malloc((len + 1) * sizeof(char));
//     if (!substr)
//         return NULL;
//     strncpy(substr, s + start, len);
//     substr[len] = '\0';
//     return substr;
// }

// int ft_countword(const char *s, char c)
// {
//     int count = 0;
//     while (*s)
//     {
//         while (*s == c)
//             s++;
//         if (*s)
//             count++;
//         while (*s != c && *s)
//             s++;
//     }
//     return count;
// }

// char **ft_split(const char *s, char c)
// {
//     char **lst;
//     size_t word_len;
//     int i;

//     lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
//     if (!s || !lst)
//         return NULL;
//     i = 0;
//     while (*s)
//     {
//         while (*s == c && *s)
//             s++;
//         if (*s)
//         {
//             const char *next_c = ft_strchr(s, c);
//             if (!next_c)
//             {
//                 // If no more occurrences of separator, set word_len to the length until the end of the string
//                 word_len = ft_strlen(s);
//             }
//             else
//             {
//                 // Include the separator in the substring
//                 word_len = next_c - s + 1;
//             }
//             lst[i++] = ft_substr(s, 0, word_len);
//             s += word_len;
//         }
//     }
//     lst[i] = NULL;
//     return lst;
// }

// void print_strings(char **strings)
// {
//     int i = 0;
//     while (strings[i] != NULL)
//     {
//         printf("%s\n", strings[i]);
//         i++;
//     }
// }

int main()
{
    char *str = "$USER$hello.    hello";
    char **split_strings = rest_of_split(str, '$');
    if (split_strings)
    {
        printf("Split strings:\n");
        print_strings(split_strings);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }
    return 0;
}




















// char **all_in_one(char **final_strings,char ***triple_d_str)
// {
//     int i;
//     int j;
//     int k;

//     i = 0;
//     j = 0;
//     k = 0;
//     while (triple_d_str[i] != NULL)
//     {
//         j = 0;
//         while(triple_d_str[i][j] != NULL)
//         {
//             final_strings[k] = triple_d_str[i][j];
//             k++;
//             j++;
//         }
//         // I remove because we will only have one NULL at the end of the only big double d array
//         i++;
//     }
//     final_strings[k] = NULL;
//     return(final_strings);
// }

// int count_number_of_words(char ***triple_d_str)
// {
//     int i;
//     int j;
//     int total;

//     i = 0;
//     j = 0;
//     total = 0;
//     while (triple_d_str[i] != NULL)
//     {
//         j = 0;
//         while(triple_d_str[i][j] != NULL)
//         {
//             total++;
//             j++;
//         }
//         // I remove because we will only have one NULL at the end of the only big double d array
//         total--;
//         i++;
//     }
//     total++;
//     return(total);
// }

// char **ft_split_double(char **str, char c)
// {
//     int i;
//     int j;
//     int total;
//     char ***new_str_str;
//     char **final_strings;

//     i = 0;
//     j = 0;
//     // ici je vais split un mot pour recevoir un string array
//     // au final j'aurai le nombre inital de double d array
//     while(str[i] != NULL)
//         i++;
//     new_str_str = calloc (i + 1, sizeof(char **));
//     i = 0;
//     while(str[i] != NULL)
//     {
//         if (str[i][0] != c)
//             new_str_str[j] = ft_split(str[i], '$');
//         else
//         {
//             new_str_str[j] = calloc(2, sizeof(char *)); // Allocate memory for an array of pointers
//             new_str_str[j][0] = strdup(str[i]); // Copy str[i] into the array
//             new_str_str[j][1] = NULL; // Terminate the array with NULL
//         }
//         i++;
//         j++;
//     }
//     new_str_str[j] = NULL;
//     total = count_number_of_words(new_str_str);
//     final_strings = calloc(total, sizeof(char *));
//     if (!final_strings)
//     {
//         printf("Memory allocation failed.\n");
//         return (NULL);
//     }
//     final_strings = all_in_one(final_strings, new_str_str);

//     return (final_strings);
// }

// int main()
// {
//     char *input_strings[] = {
//         "$USER$hello.    hello",
//         "'$USER'",
//         "   yo$USER",
//         NULL
//     };
//     int i = 0;
//     char **final_strings = ft_split_double(input_strings, '\'');

//     if (final_strings) 
//     {
//         printf("Final strings:\n");
//         while(final_strings[i] != NULL)
//         {
//             printf("%s\n", final_strings[i]);
//             i++;
//         }

//     } else {
//         printf("Memory allocation failed.\n");
//     }

//     return 0;
// }
