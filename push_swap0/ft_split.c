#include "push_swap.h"

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
