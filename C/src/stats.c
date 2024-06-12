/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:16:14 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/11 23:10:46 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <final_return.h>

void	print_ratios(t_fx_info *infos)
{
	t_int_lst		*tmp_stat;
	t_double_lst	*tmp_amount;

	tmp_stat = infos->ratios_stats;
	tmp_amount = infos->ratios_amount;
	printf(BOLD);
	while (tmp_stat && tmp_amount)
	{
		if (tmp_stat->i == VICTIM)
			printf(" + %.0f%%", tmp_amount->next->db * 100);
		else
			printf(" + %.0f%%", tmp_amount->db * 100);
		switch (tmp_stat->i)
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
				printf(CYN" %s (victim)"CLR, stattostr(tmp_stat->next->i));
				break ;
		}
		if (tmp_stat->i == VICTIM)
		{
			tmp_stat = tmp_stat->next;
			tmp_amount = tmp_amount->next;
		}
		tmp_stat = tmp_stat->next;
		tmp_amount = tmp_amount->next;
	}
	printf(CLR);
}

t_fx	strtofx(char *str)
{
	if (!strcmp(str, "HEAL"))
		return (HEAL);
	if (!strcmp(str, "SHIELD"))
		return (SHIELD);
	if (!strcmp(str, "DMG"))
		return (DMG);
	if (!strcmp(str, "DOT"))
		return (DOT);
	if (!strcmp(str, "BUFF"))
		return (BUFF);
	if (!strcmp(str, "DEBUFF"))
		return (DEBUFF);
	if (!strcmp(str, "REVIVE"))
		return (REVIVE);
	if (!strcmp(str, "INVINCIBLE"))
		return (INVINCIBLE);
	return (0);
}

t_stats	strtostat(char *str)
{
	if (!strcmp(str, "HPS"))
		return (HPS);
	if (!strcmp(str, "RGN"))
		return (RGN);
	if (!strcmp(str, "ATK"))
		return (ATK);
	if (!strcmp(str, "DEF"))
		return (DEF);
	if (!strcmp(str, "PWR"))
		return (PWR);
	if (!strcmp(str, "DSP"))
		return (DSP);
	if (!strcmp(str, "LET"))
		return (LET);
	if (!strcmp(str, "IGD"))
		return (IGD);
	if (!strcmp(str, "TNC"))
		return (TNC);
	if (!strcmp(str, "RSL"))
		return (RSL);
	if (!strcmp(str, "PNT"))
		return (PNT);
	if (!strcmp(str, "CDR"))
		return (CDR);
	if (!strcmp(str, "VMP"))
		return (VMP);
	if (!strcmp(str, "AVP"))
		return (AVP);
	if (!strcmp(str, "END"))
		return (END);
	if (!strcmp(str, "VICTIM"))
		return (VICTIM);
	return (0);
}

char	*stattostr(t_stats stat)
{
	if (stat == HPS)
		return ("HPS");
	if (stat == RGN)
		return ("RGN");
	if (stat == ATK)
		return ("ATK");
	if (stat == DEF)
		return ("DEF");
	if (stat == PWR)
		return ("PWR");
	if (stat == DSP)
		return ("DSP");
	if (stat == LET)
		return ("LET");
	if (stat == IGD)
		return ("IGD");
	if (stat == PNT)
		return ("PNT");
	if (stat == TNC)
		return ("TNC");
	if (stat == RSL)
		return ("RSL");
	if (stat == CDR)
		return ("CDR");
	if (stat == VMP)
		return ("VMP");
	if (stat == AVP)
		return ("AVP");
	if (stat == END)
		return ("END");
	if (stat == VICTIM)
		return ("VICTIM");
	return (0);
}
