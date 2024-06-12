/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:54:17 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/11 23:10:40 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <final_return.h>

void	print_item_info(t_fx_info *info);

void	print_item(t_kit *kit, t_item *item)
{
	(void)kit;
	printf(BGRN"\n%s\n"CLR, item->name);
	printf(BOLD"\tCooldown:"CLR" %d\n", item->cooldown);
	printf(BOLD"\tLevel_Locked:"CLR" %d\n", item->level_lock);
	printf(BOLD"\tEffects:\n");
	print_item_info(item->effects);
}

void	print_item_info(t_fx_info *info)
{
	while (info)
	{
		printf("\t\t- ");
		switch (info->fx) //Print the effect type
		{
			case HEAL:
				printf("Heal = ");
				break;
			case SHIELD:
				printf("Shield = ");
				break;
			case DMG:
				printf("Damage = ");
				break;
			case DOT:
				printf("DoT = ");
				break;
			case BUFF:
				printf("Buff = ");
				break;
			case DEBUFF:
				printf("Debuff = ");
				break;
			case REVIVE:
				printf("Revive = ");
				break;
			case INVINCIBLE:
				printf("Invincible = ");
				break;
		}
		printf(CLR);
		if (info->fx == HEAL || info->fx == SHIELD || info->fx == DMG || info->fx == DOT)
		{
			printf("%d", info->base_amount);
			print_ratios(info);
			if (info->fx == DMG || info->fx == DOT) /*Print le type de degats*/ {
				switch (info->dmg_type) {
					case 0:
						printf(BRED" Physical Damage\n"CLR);
						break;
					case 1:
						printf(BRED" Magical Damage\n"CLR);
						break;
					case 2:
						printf(BRED" Brut Damage\n"CLR);
						break;
				}
			}
		}
		info = info->next;
	}
}