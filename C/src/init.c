/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:51:49 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/11 23:10:37 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <final_return.h>

static int			set_effects(t_item *item);
static t_fx_info	*init_ratios(t_fx type);
static t_item		*error_exit(t_item *item, int steps);

t_item	*create_item(void)
{
	char		*input;
	t_item		*new_item;
	
	new_item = malloc(sizeof(t_item));
	new_item->name = NULL;
	new_item->effects = NULL;
	new_item->level_ups = NULL;
	input = readline(BYLW"Name of the item/passive: "CLR BOLD);
	if (!input)
		return (error_exit(new_item, 0));
	new_item->name = input;
	input = readline(BYLW"Cooldown of the item/passive: "CLR BOLD);
	if (!input)
		return (error_exit(new_item, 1));
	new_item->cooldown = (int)strtol(input, NULL, 10);
	free(input);
	input = readline(BYLW"Level lock of the item/passive: "CLR BOLD);
	if (!input)
		return (error_exit(new_item, 2));
	new_item->level_lock = (int)strtol(input, NULL, 10);
	set_effects(new_item);
	return (new_item);
}

static int	set_effects(t_item *item)
{
	char	*input;

	while (true)
	{
		printf(BGRN"Please add one effect of the item/passive\n"CLR);
		printf(BGRN"Once you are finished, just press CTRL+D\n"CLR);
		input = readline(BYLW"(HEAL, SHIELD, DMG, DOT, BUFF, DEBUFF, REVIVE, INVINCIBLE)\n>"CLR BOLD);
		if (!input)
			return (EXIT_SUCCESS);
		switch (strtofx(input)) {
			case HEAL:
				fx_add(&item->effects, init_ratios(HEAL));
				break;
			case SHIELD:
				fx_add(&item->effects, init_ratios(SHIELD));
				break;
			case DMG:
				fx_add(&item->effects, init_ratios(DMG));
				break;
			case DOT:
				fx_add(&item->effects, init_ratios(DOT));
				break;
			case BUFF:
				break;
			case DEBUFF:
				break;
			case REVIVE:
				break;
			case INVINCIBLE:
				break;
		}
	}
}

static t_fx_info	*init_ratios(t_fx type)
{
	t_fx_info	*new;
	char		*input;

	new = fx_new(type);
	if (type == DMG || type == DOT)
	{
		printf(BOLD"PHYSICAL, MAGICAL or BRUT\n"CLR);
		input = readline(BYLW"Type of Damage: "CLR BOLD);
		if (!strcmp(input, "PHYSICAL"))
			new->dmg_type = PHYSICAL;
		if (!strcmp(input, "MAGICAL"))
			new->dmg_type = MAGICAL;
		if (!strcmp(input, "BRUT"))
			new->dmg_type = BRUT;
	}
	input = readline(BYLW"Base amount: "CLR BOLD);
	if (input)
	{
		new->base_amount = (int)strtol(input, NULL, 10);
		free(input);
	}
	new->ratios_stats = NULL;
	new->ratios_amount = NULL;
	while (true)
	{
		stat_name:
		printf(BCYN"Valid inputs are HPS, RGN, ATK, DEF, PWR, DSP, LET, IGD, PNT, CDR, VMP, AVP, VICTIM\n"CLR);
		printf(CYN"If your input is \"VICTIM\", put the amount to 0 and make sure to add an other one after.\n");
		input = readline(BYLW"Stats to base the ratio off: "BCYN);
		if (!input)
			break ;
		if (!strtostat(input))
			goto stat_name;
		int_add(&new->ratios_stats, int_new(strtostat(input)));
		input = readline(BYLW"Amount of the ratio: "CLR BOLD);
		double_add(&new->ratios_amount, double_new(strtod(input, NULL)));
	}
	printf(BPRP"Exited ratios setup...\n"CLR);
	return (new);
}

t_item	*error_exit(t_item *item, int steps)
{
	printf(BRED"Unexpected exit: ");
	switch (steps) {
		case 0:
			printf(" Incorrect name\n"CLR);
			break;
		case 1:
			printf(" Incorrect cooldown\n"CLR);
			break;
		case 2:
			printf(" Incorrect level_lock\n"CLR);
			break;
	}
	delete_item(&item);
	return (NULL);
}