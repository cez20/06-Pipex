/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:33:47 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/10/25 17:11:08 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_words_in_string(char const *s, char c)
{
	int	nb_of_words;
	int	i;
	int	j;

	nb_of_words = 0;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			nb_of_words++;
			i = i + (j - 1);
			j = 0;
		}
		i++;
	}
	return (nb_of_words);
}

static char	*copy_word(const char *s, int start, int finish)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc((finish - start + 1) * sizeof(*str));
	while (start < finish)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

static char	**ft_add_content(const char *s, char **split, char c)
{
	size_t	i;
	size_t	j;
	int		index;

	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = copy_word(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((nb_words_in_string(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	ft_add_content(s, split, c);
	return (split);
}
