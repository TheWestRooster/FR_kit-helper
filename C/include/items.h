/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:27:53 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/11 23:11:05 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEMS_H
# define ITEMS_H

# include <linked_list.h>

typedef enum e_stats {
	HPS = 1,
	RGN,
	ATK,
	DEF,
	PWR,
	DSP,
	LET,
	IGD,
	PNT,
	TNC,
	RSL,
	CDR,
	VMP,
	AVP,
	END,
	VICTIM
}	t_stats;

typedef enum	e_fx {
	HEAL = 1,
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
	int					base_amount;
	t_int_lst			*ratios_stats;
	t_double_lst		*ratios_amount;
	//DMG, DOT
	int					dmg_type;
	//DOT
	int					dot_ticks;
	double				dot_delay;
	//BUFF, DEBUFF
	t_int_lst 			*change_stats;
	t_double_lst 		*change_amount;
	int					duration;
	//REVIVE
	int					revive_num;
	//INVINCIBLE
	int					invincible_time;
}	t_fx_info;

typedef struct	s_item {
	char			*name;
	unsigned int	cooldown;
	unsigned int	level_lock;
	t_fx_info		*effects;
	t_fx_info		*level_ups;
	struct s_item	*next;
}	t_item;

typedef struct s_kit t_kit;

t_item	*create_item(void);
void	print_item(t_kit *kit, t_item *item);
void	delete_item(t_item **item);

t_fx_info	*fx_new(t_fx type);
void		fx_add(t_fx_info **lst, t_fx_info *new);
void		fx_clear(t_fx_info **lst);

#endif
