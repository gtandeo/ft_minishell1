/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 04:04:45 by gtandeo           #+#    #+#             */
/*   Updated: 2015/02/12 00:24:04 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	unsigned char	*source;
	unsigned char	*desti;

	source = (unsigned char*)src;
	desti = (unsigned char*)dst;
	if (n > 0)
	{
		while (n--)
		{
			if ((*desti++ = *source++) == (unsigned char)c)
				return (desti);
		}
	}
	return (NULL);
}
