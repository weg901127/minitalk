/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 07:26:01 by gilee             #+#    #+#             */
/*   Updated: 2021/01/21 03:32:30 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*rest;
	const char	*ps1;
	size_t		len;

	ps1 = s1;
	len = ft_strlen(s1);
	if (!(rest = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (len--)
	{
		*rest++ = *ps1++;
	}
	*rest = '\0';
	return (rest - ft_strlen(s1));
}
