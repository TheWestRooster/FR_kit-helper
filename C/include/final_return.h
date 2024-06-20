/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_return.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:49:50 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/11 23:10:59 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FR_KIT_HELPER_H
# define FR_KIT_HELPER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <colors.h>
# include <items.h>
# include <stats.h>
# include <linked_list.h>

typedef struct	s_kit {
	char	*name;
	double	base_stat[16];
	double	stat_perlvl[16];
	t_item	*items;
}	t_kit;

t_kit	*create_kit(void);
void	print_kit(t_kit *kit);
void	unload_kit(t_kit *kit);

#endif
