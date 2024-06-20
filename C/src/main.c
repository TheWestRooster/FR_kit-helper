/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:49:36 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/20 23:23:44 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <final_return.h>

int	main()
{
	t_kit	*kit;
	printf(BGRN"Welcome to"BCYN" Final Return Kit-helper\n"CLR);

	kit = create_kit();
	print_kit(kit);
	unload_kit(kit);
}

