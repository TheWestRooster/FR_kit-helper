/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   effects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:44:48 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/20 23:23:32 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <final_return.h>

t_fx	strtofx(char *str)
{
	if (!strcmp(str, "HEAL"))
		return (HEAL);
	if (!strcmp(str, "SHIELD"))
		return (SHIELD);
	if (!strcmp(str, "DMG"))
		return (DMG);
	if (!strcmp(str, "DOT"))
		return (DOT);
	if (!strcmp(str, "BUFF"))
		return (BUFF);
	if (!strcmp(str, "DEBUFF"))
		return (DEBUFF);
	if (!strcmp(str, "REVIVE"))
		return (REVIVE);
	if (!strcmp(str, "INVINCIBLE"))
		return (INVINCIBLE);
	return (0);
}

t_fx_info	*fx_new(t_fx type)
{
	t_fx_info	*new;

	new = malloc(sizeof(t_fx_info));
	new->fx = type;
	new->next = NULL;
	new->ratios_stats = NULL;
	new->ratios_amount = NULL;
	new->change_stats = NULL;
	new->change_amount = NULL;
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

void	fx_clear(t_fx_info **lst)
{
	if (!lst || !*lst)
		return ;
	if ((*lst)->next)
		fx_clear((&(*lst)->next));

	t_fx_info	*to_clear = (*lst);

	if(to_clear->ratios_stats)
	{
		int_clear(&to_clear->ratios_stats);
		double_clear(&to_clear->ratios_amount);
	}
	if (to_clear->change_stats)
	{
		int_clear(&to_clear->change_stats);
		double_clear(&to_clear->change_amount);
	}
	free(*lst);
}
