/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 02:31:08 by gtandeo           #+#    #+#             */
/*   Updated: 2015/02/12 00:40:18 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i != len)
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return ((char*)str);
}
