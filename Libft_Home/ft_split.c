/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csahyoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 01:25:24 by csahyoun          #+#    #+#             */
/*   Updated: 2025/07/21 01:25:27 by csahyoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(const char *s, char c);
static char	*word_dup(const char *start, int len);
static int	word_len(const char *s, char c);
static char	**free_all(char **substr, int i);

char	**ft_split(char const *s, char c)
{
	char	**substr_array;
	int		i;
	int		len;
	int		word_count;

	if (s == NULL)
		return (NULL);
	word_count = count_words(s, c);
	substr_array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (substr_array == NULL)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		substr_array[i] = word_dup(s, len);
		if (substr_array[i] == NULL)
			return (free_all(substr_array, i));
		s += len;
		i++;
	}
	substr_array[i] = NULL;
	return (substr_array);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char	*word_dup(const char *start, int len)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static char	**free_all(char **substr, int i)
{
	while (i > 0)
	{
		i--;
		free(substr[i]);
	}
	free(substr);
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char s1[30] = "Hello World";
//     char s2[40] = "   Hello   World  ";
//     char s3[20] = "abc,,def";
//     char s4[5] = "";
//     char s5[30] = "OneDelimiterOnly";
//     s1[29] = '\0';
//     s2[39] = '\0';
//     s3[19] = '\0';
//     s4[4] = '\0';
//     s5[29] = '\0';

//     char **split1 = ft_split(s1, ' ');
//     char **split2 = ft_split(s2, ' ');
//     char **split3 = ft_split(s3, ',');
//     char **split4 = ft_split(s4, ',');
// 	char **split5 = ft_split(s5, ',');

//     for (int i = 0; split1[i]; i++)
//         printf("%s\n", split1[i]);
//     for (int i = 0; split2[i]; i++)
//         printf("%s\n", split2[i]);
//     for (int i = 0; split3[i]; i++)
//         printf("%s\n", split3[i]);
//     for (int i = 0; split4[i]; i++)
//         printf("%s\n", split4[i]);
//     for (int i = 0; split5[i]; i++)
//         printf("%s", split5[i]);

//     for (int i = 0; split1[i]; i++) 
// 		free(split1[i]);
// 	free(split1);
//     for (int i = 0; split2[i]; i++) 
// 		free(split2[i]);
// 	free(split2);
//     for (int i = 0; split3[i]; i++) 
// 		free(split3[i]);
// 	free(split3);
//     for (int i = 0; split4[i]; i++) 
// 		free(split4[i]);
// 	free(split4);
//     for (int i = 0; split5[i]; i++) 
// 		free(split5[i]);
// 	free(split5);
//     return (0);
// }