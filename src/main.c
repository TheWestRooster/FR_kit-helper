/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:49:36 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/11 23:10:43 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <final_return.h>

int	main()
{
	t_item	*item;

	printf(BGRN"Welcome to"BCYN" Final Return Kit-helper\n"CLR);
	item = create_item();
	if (item)
	{
		print_item(NULL, item);
		free(item->name);
		free(item);
	}
}
