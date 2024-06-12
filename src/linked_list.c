/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:35:03 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/11 23:10:28 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <final_return.h>

t_int_lst	*int_new(int num)
{
	t_int_lst	*new;

	new = malloc(sizeof(t_int_lst));
	new->i = num;
	new->next = NULL;
	return (new);
}

void	int_add(t_int_lst **lst, t_int_lst *new)
{
	if ((*lst) == NULL)
	{
		(*lst) = new;
		return ;
	}
	if (new == NULL)
		return ;
	if ((*lst)->next == NULL)
	{
		(*lst)->next = new;
		return ;
	}
	int_add(&(*lst)->next, new);
}

void	int_clear(t_int_lst **lst)
{
	if (!lst || !*lst)
		return ;
	if ((*lst)->next)
		int_clear((&(*lst)->next));
	free(*lst);
}

t_double_lst	*double_new(double num)
{
	t_double_lst	*new;

	new = malloc(sizeof(t_double_lst));
	new->db = num;
	new->next = NULL;
	return (new);
}

void	double_add(t_double_lst **lst, t_double_lst *new)
{
	if ((*lst) == NULL)
	{
		(*lst) = new;
		return ;
	}
	if (new == NULL)
		return ;
	if ((*lst)->next == NULL)
	{
		(*lst)->next = new;
		return ;
	}
	double_add(&(*lst)->next, new);
}

void	double_clear(t_int_lst **lst)
{
	if (!lst || !*lst)
		return ;
	if ((*lst)->next)
		double_clear((&(*lst)->next));
	free(*lst);
}
