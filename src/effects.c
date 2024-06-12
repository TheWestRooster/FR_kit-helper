/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:44:48 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/11 23:10:33 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <final_return.h>

t_fx_info	*fx_new(t_fx type)
{
	t_fx_info	*new;

	new = malloc(sizeof(t_fx_info));
	new->fx = type;
	new->next = NULL;
	return (new);
}

void	fx_add(t_fx_info **lst, t_fx_info *new)
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
	fx_add(&(*lst)->next, new);
}
