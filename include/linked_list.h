/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:31:34 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/11 23:10:53 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

typedef struct s_int_lst {
	int					i;
	struct s_int_lst	*next;
}	t_int_lst;

typedef struct s_double_lst {
	double				db;
	struct s_double_lst	*next;
}	t_double_lst;

t_int_lst		*int_new(int num);
void			int_add(t_int_lst **lst, t_int_lst *new);
void			int_clear(t_int_lst **lst);

t_double_lst	*double_new(double num);
void			double_add(t_double_lst **lst, t_double_lst *new);
void			double_clear(t_int_lst **lst);

#endif