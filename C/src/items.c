/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:54:17 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/20 23:23:37 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <final_return.h>

t_item	*create_item(void)
{
	char		*input;
	t_item		*new_item;

	new_item = malloc(sizeof(t_item));
	new_item->name = NULL;
	new_item->effects = NULL;
	new_item->level_ups = NULL;
	new_item->next = NULL;
	printf(PRP"Creating item...\n"CLR);
	input = readline(BYLW"Name of the item/passive: "CLR BOLD);
	if (!input)
		return (error_exit(new_item, 0));
	new_item->name = strdup(input);
	free(input);
	input = readline(BYLW"Cooldown of the item/passive: "CLR BOLD);
	if (!input)
		return (error_exit(new_item, 1));
	new_item->cooldown = (int)strtol(input, NULL, 10);
	free(input);
	input = readline(BYLW"Level lock of the item/passive: "CLR BOLD);
	if (!input)
		return (error_exit(new_item, 2));
	new_item->level_lock = (int)strtol(input, NULL, 10);
	free(input);
	set_effects(new_item);
	if (new_item->effects != NULL) // NOLINT
		return (new_item);
	return (error_exit(new_item, 3));
}

void	print_item(t_item *item)
{
	printf(BGRN"\n%s\n"CLR, item->name);
	printf(BOLD" | Cooldown:"CLR" %d\n", item->cooldown);
	printf(BOLD" | Level_Locked:"CLR" %d\n", item->level_lock);
	printf(BOLD" | Effects:\n");
	print_item_info(item->effects);
}

void	print_item_info(t_fx_info *info)
{
	while (info)
	{
		printf(" | - ");
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
			print_ratios(info->ratios_stats, info->ratios_amount);
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
		if (info->fx == BUFF || info->fx == DEBUFF)
		{
			printf("%d", info->base_amount);
			print_ratios(info->change_stats, info->change_amount);
			printf(BOLD" %s"CLR, stattostr(info->stat_buff));
			printf(" for "BOLD"%ds\n"CLR, info->duration);
		}
		if (info->fx == REVIVE)
		{
			printf("%d", info->revive_num);
			printf(BOLD" time(s) with "CLR);
			if (info->revive_hp <= 1)
				printf("%.0f%% max HP healing\n", info->revive_hp * 100);
			else
				printf("%.0f HP healing\n", info->revive_hp);
		}
		if (info->fx == INVINCIBLE)
			printf("%ds of invincibility\n", info->invincible_time);
		info = info->next;
	}
}

void	print_ratios(t_int_lst *stats, t_double_lst *amounts)
{
	printf(BOLD);
	while (stats && amounts)
	{
		if (stats->i == VICTIM)
			printf(" + %.0f%%", amounts->next->db * 100);
		else
			printf(" + %.0f%%", amounts->db * 100);
		switch (stats->i)
		{
			case HPS:
				printf(" HPS");
				break ;
			case RGN:
				printf(" RGN");
				break ;
			case ATK:
				printf(" ATK");
				break ;
			case DEF:
				printf(" DEF");
				break ;
			case PWR:
				printf(" PWR");
				break ;
			case DSP:
				printf(" DSP");
				break ;
			case SPD:
				printf(" SPD");
				break ;
			case LET:
				printf(" LET");
				break ;
			case IGD:
				printf(" IGD");
				break ;
			case PNT:
				printf(" PNT");
				break ;
			case CDR:
				printf(" CDR");
				break ;
			case VMP:
				printf(" VMP");
				break ;
			case AVP:
				printf(" AVP");
				break ;
			case VICTIM:
				printf(CYN" %s (victim)"CLR, stattostr(stats->next->i));
				break ;
		}
		if (stats->i == VICTIM)
		{
			stats = stats->next;
			amounts = amounts->next;
		}
		stats = stats->next;
		amounts = amounts->next;
	}
	printf("\n"CLR);
}

void	delete_item(t_item *item)
{
	if (!item)
		return ;
	if (item->name)
		free(item->name);
	if (item->effects)
		fx_clear(&item->effects);
	if (item->level_ups)
		fx_clear(&item->level_ups);
	free(item);
}