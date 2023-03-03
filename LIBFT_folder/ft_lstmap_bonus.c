/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 18:58:48 by izaitcev      #+#    #+#                 */
/*   Updated: 2022/04/30 21:49:45 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*elem;

	first = NULL;
	while (lst)
	{
		elem = ft_lstnew(f(lst->content));
		if (!elem)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		if (first == NULL)
			first = elem;
		else
			ft_lstadd_back(&first, elem);
		lst = lst->next;
	}
	return (first);
}
