/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:37:57 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/29 15:19:06 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_count_words(const char *s, char *charset)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (ft_ischarset(s[i], charset))
			i++;
		if (s[i])
			count += 1;
		while (s[i] && !ft_ischarset(s[i], charset))
			i++;
	}
	return (count);
}

static int	ft_wlen(const char *s, char *charset)
{
	int	len;

	len = 0;
	while (s[len] && !ft_ischarset(s[len], charset))
		len++;
	return (len);
}

static char	*ft_strndup(const char *s, char *charset)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_wlen(s, charset) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < ft_wlen(s, charset))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_freesplit(char **split, size_t j)
{
	if (split[j] == NULL)
	{
		while (j > 0)
		{
			free(split[j]);
			j--;
		}
		free(split);
		return (NULL);
	}
	return (split);
}

char	**ft_split(char const *s, char *charset)
{
	char	**split;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	split = (char **)malloc((ft_count_words(s, charset) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (ft_ischarset(s[i], charset) && !ft_ischarset('\0', charset))
		i++;
	j = 0;
	while (j < ft_count_words(s, charset))
	{
		split[j] = ft_strndup(&s[i], charset);
		ft_freesplit(split, j);
		while (s[i] && !ft_ischarset(s[i], charset))
			i++;
		while (ft_ischarset(s[i], charset))
			i++;
		j++;
	}
	split[j] = NULL;
	return (split);
}
