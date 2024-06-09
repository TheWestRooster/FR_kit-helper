/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:54:17 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/09 21:54:17 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <final_return.h>

static void	print_item_info(t_fx_info *info);

void	print_item(t_kit *kit, t_item *item)
{
	printf(BOLD"%s\n"CLR, item->name);
	printf("\tLevel_Locked: %d\n", item->level_lock);
	printf("\tCooldown: %d\n", item->cooldown);
	printf("\tEffects:\n");
	print_item_info(item->effects);
}

static void	print_item_info(t_fx_info *info)
{
	while (info)
	{
		printf("\t\t- ");
		switch (info->fx) //Print the effect type
		{
			case HEAL:
				printf("Heal = ");
			case SHIELD:
				printf("Shield = ");
			case DMG:
				printf("Damage = ");
			case DOT:
				printf("DoT = ");
			case BUFF:
				printf("Buff = ");
			case DEBUFF:
				printf("Debuff = ");
			case REVIVE:
				printf("Revive = ");
			case INVINCIBLE:
				printf("Invincible = ");
		}
		if (info->fx == HEAL || info->fx == DMG || info->fx == SHIELD)
		{
			printf("%d", info->base_amount);
			print_ratios(info);
			printf("PVS");
			if (info->fx == DMG) /*Print le type de degats*/ {
				switch (info->dmg_type) {
					case 0:
						printf("as Physical");
					case 1:
						printf("as Magical");
					case 2:
						printf("as Brut");
				}
			}

		}
	}
}