/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mizola <mizola@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 03:25:31 by mizola            #+#    #+#             */
/*   Updated: 2020/05/14 03:45:12 by mizola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	if (*lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = tmp;
		}
	}
}

void 	del(void *content)
{
	content = "";
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
		new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list *new_el;

	new_el = malloc(sizeof(t_list));
	if (new_el == NULL)
		return (NULL);
	new_el->content = content;
	new_el->next = NULL;
	return (new_el);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}


int 	main(void)
{
	t_list *pro;

	pro = NULL;
	ft_lstadd_front(&pro, ft_lstnew("hello"));
	ft_lstadd_front(&pro, ft_lstnew("ello"));
	ft_lstadd_front(&pro, ft_lstnew("llo"));
	ft_lstadd_front(&pro, ft_lstnew("lo"));
	ft_lstclear(&pro, del);
	if (pro)
	{
		while (pro->content != NULL)
		{
			printf("1 :%s\n", pro->content);
			pro = pro->next;
		}
	}
	return (0);

}