/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 05:30:45 by gtandeo           #+#    #+#             */
/*   Updated: 2015/02/12 00:54:08 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *s1, const char *s2)
{
	if (*s2 == '\0')
		return ((char *)s1);
	while (ft_strncmp(s1, s2, ft_strlen(s2)) != 0)
	{
		if (*s1 == '\0')
			return (NULL);
		s1++;
	}
	return ((char*)s1);
}
