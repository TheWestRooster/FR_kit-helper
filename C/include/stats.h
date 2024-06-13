/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:15:25 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/11 23:11:03 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATS_H
# define STATS_H

void	print_ratios(t_int_lst *stats, t_double_lst *amounts);
t_fx	strtofx(char *str);
t_stats	strtostat(char *str);
char	*stattostr(t_stats stat);

#endif
