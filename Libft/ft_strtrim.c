/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:31:08 by stouitou          #+#    #+#             */
/*   Updated: 2024/01/19 10:59:26 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		start;
	int		len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (ft_ischarset(s1[i], set) && s1[i])
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (ft_ischarset(s1[i], set) && i > start)
		i--;
	len = i + 1 - start;
	str = ft_substr(s1, start, len);
	return (str);
}
