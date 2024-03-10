#include "expander.h"

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

char **ft_split(char *str, char c)
{
    char **lst;
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
    lst[j] = NULL;
	//printf("in ft_split\n");
	int k = 0;
	while(lst[k])
	{
		printf("ft split strings %s\n", lst[k]);
		k++;
	}
    return (lst);
}


