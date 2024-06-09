/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:51:49 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/09 21:53:50 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <final_return.h>

static t_item	*error_exit(t_item *item, int steps);

t_item	*create_item(void)
{
	char		*input;
	t_item		*new_item;

	new_item = malloc(sizeof(t_item));
	input = readline(BYLW"Put the name of the item/passive: "CLR BOLD);
	if (!input)
		return (error_exit(new_item, 0));
	new_item->name = input;
	printf(BYLW"The item name is "BGRN"%s"CLR, new_item->name);

	return (new_item);
}

t_item	*error_exit(t_item *item, int steps)
{
	printf(BRED"Unexpected exit: ");
	switch (steps) {
		case 0:
			printf(" Incorrect name"CLR);
		case 1:
			printf(" Incorrect bozo"CLR);
	}
	free(item->name);
	free(item);
	return (NULL);
}