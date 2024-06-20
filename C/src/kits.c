/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 21:46:10 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/20 23:23:25 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <final_return.h>

t_kit	*create_kit(void)
{
	t_kit	*kit;
	t_item	*loop;

	kit = malloc(sizeof(t_kit));
	kit->name = readline(BPRP"Name of the kit: "CLR);
	kit->items = NULL;
	if (!kit->name) { unload_kit(kit); return (NULL); }
	printf(BPRP"Stats for LV0\n" CLR);
	create_stats(kit->base_stat);
	printf(BPRP"Stats per LvUP\n" CLR);
	create_stats(kit->stat_perlvl);
	printf(BPRP"Items\n" CLR);
	kit->items = create_item();
	loop = kit->items;
	while (loop)
	{
		loop->next = create_item();
		loop = loop->next;
	}
	return (kit);
}

void	unload_kit(t_kit *kit)
{
	t_item	*loop;
	free(kit->name);
	memset(kit->base_stat, -1, sizeof(double) * 16);
	memset(kit->stat_perlvl, -1, sizeof(double) * 16);
	loop = kit->items;
	while (loop)
	{
		loop = loop->next;
		delete_item(kit->items);
		kit->items = loop;
	}
	kit->items = NULL;
	free(kit);
}

void	print_kit(t_kit *kit)
{
	printf(BCYN"\n%s\n"CLR, kit->name);
	for (int i = 0; i < VICTIM - 1; ++i) {
		printf(BOLD" | %s: "CLR, stattostr(i + 1));
		if (kit->base_stat[i] < 1)
		{
			if (kit->stat_perlvl[i] != 0) { printf("%0.f%% + %0.f%%/Lvl", kit->base_stat[i] * 100, kit->stat_perlvl[i] * 100); }
			else { printf("%0.f%%", kit->base_stat[i] * 100); }
		}
		else
		{
			if (kit->stat_perlvl[i] != 0) { printf("%0.f + %0.f/Lvl", kit->base_stat[i], kit->stat_perlvl[i]); }
			else { printf("%0.f", kit->base_stat[i]); }
		}
		printf("\n");
	}
	for (t_item *loop = kit->items; loop != NULL; loop = loop->next) {
		print_item(loop);
	}
}