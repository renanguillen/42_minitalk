/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ridalgo- <ridalgo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:47:14 by ridalgo-          #+#    #+#             */
/*   Updated: 2022/05/03 15:28:49 by ridalgo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	words;
	int	is_word;
	int	i;

	words = 0;
	is_word = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && is_word)
		{
			is_word = 0;
			words++;
		}
		else if (s[i] == c)
			is_word = 1;
		i++;
	}
	return (words);
}

static void	ft_allocate(char **ans, int word, char c, char *aux)
{
	int	i;
	int	j;
	int	start;
	int	end;

	i = 0;
	j = 0;
	while (i < word)
	{
		while (aux[j] == c)
			j++;
		start = j;
		while (aux[j] != c && aux[j])
		{
			if (aux[j + 1] == c || aux[j + 1] == 0)
				end = j;
			j++;
		}
		ans[i] = ft_substr(&aux[start], 0, (end - start + 1));
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		word;

	if (!s && s[0] == 0)
		return (NULL);
	word = ft_count_words(s, c);
	ans = (char **)malloc(sizeof(char *) * (word + 1));
	if (!ans)
		return (NULL);
	ft_allocate(ans, word, c, (char *)s);
	ans[word] = NULL;
	return (ans);
}
