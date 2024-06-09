/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:27:53 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/09 21:51:35 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEMS_H
# define ITEMS_H

typedef enum e_stats {
	HPS = 0,
	RGN,
	ATK,
	DEF,
	PWR,
	DSP,
	LET,
	IGD,
	PNT,
	CDR,
	VMP,
	AVP
}	t_stats;

typedef enum	e_fx {
	HEAL,
	SHIELD,
	DMG,
	DOT,
	BUFF,
	DEBUFF,
	REVIVE,
	INVINCIBLE
}	t_fx;

typedef enum	e_dmg_type {
	PHYSICAL,
	MAGICAL,
	BRUT
}	t_dmg_type;

typedef struct	s_fx_info {
	t_fx				fx;
	struct s_fx_info	*next;
	//HEAL, DMG, DOT
	int		base_amount;
	t_stats	*ratios_stats;
	double	*ratios_amount;
	//DMG, DOT
	int		dmg_type;
	//DOT
	int		dot_ticks;
	double	dot_delay;
	//BUFF, DEBUFF
	t_stats	*change_stats;
	int		*change_amount;
	int		duration;
	//REVIVE
	int		revive_num;
	//INVINCIBLE
	int		invincible_time;
}	t_fx_info;

typedef struct	s_item {
	char		*name;
	int 		level_lock;
	int			cooldown;
	int			*level_ups;
	t_fx_info	*effects;
}	t_item;

typedef struct s_kit t_kit;

t_item	*item_new(char *input_name, int input_lvl_lock, int input_cd, t_fx_info *input_fx);
void	print_item(t_kit *kit, t_item *item);

#endif
