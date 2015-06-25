/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 00:59:12 by gtandeo           #+#    #+#             */
/*   Updated: 2015/02/12 01:04:26 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tab)
{
	char	**ret;
	int		i;

	i = 0;
	ret = (char**)malloc(sizeof(char*) * ft_tablen(tab) + 1);
	while (tab[i])
	{
		ret[i] = ft_strdup(tab[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
