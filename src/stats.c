/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:16:14 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/09 22:16:14 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <final_return.h>

void	print_ratios(t_fx_info *infos)
{
	int	i;

	i = 0;
	printf(BOLD);
	while (infos->ratios_stats[i])
	{
		printf(" + %f", infos->ratios_amount[i]);
		switch (infos->ratios_stats[i])
		{
			case HPS:
				printf(" PVS");
			case RGN:
				printf(" RGN");
			case ATK:
				printf(" ATK");
			case DEF:
				printf(" DEF");
			case PWR:
				printf(" PWR");
			case DSP:
				printf(" DSP");
			case LET:
				printf(" LET");
			case IGD:
				printf(" IGD");
			case PNT:
				printf(" PNT");
			case CDR:
				printf(" CDR");
			case VMP:
				printf(" VMP");
			case AVP:
				printf(" AVP");
		}
		i++;
	}
	printf(CLR);
}
