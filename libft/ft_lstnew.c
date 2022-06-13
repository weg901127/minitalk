/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:29:23 by gilee             #+#    #+#             */
/*   Updated: 2021/01/18 18:30:18 by gilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*link;

	if (!(link = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	link->content = (void*)content;
	link->next = NULL;
	return (link);
}
