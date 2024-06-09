/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_return.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:49:50 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/09 21:51:38 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FR_KIT_HELPER_H
# define FR_KIT_HELPER_H

# include <colors.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <items.h>
# include <stats.h>


typedef struct	s_kit {
	int		level;
	int		base_stat[12];
	int		stat_perlvl[12];
	t_item	**items;
}	t_kit;

#endif
