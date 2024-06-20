/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:16:14 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/20 23:23:46 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <final_return.h>

void	create_stats(double stats[16])
{
	char	*input;

	printf(PRP"Creating stats...\n"CLR);
	memset(stats, -1, sizeof(double) * 16);
	printf(CYN"Available commands: exit, back, skip\n");
	printf(CYN"Put -1 if you want to set stat to 0, don\'t ask why\n");
	for (int i = 0; i < VICTIM - 1; ++i) {
		if (i < 0) { i = 0; }
		input = NULL;
		while (!input || !check_valid_num(input, true))
		{
			printf(BYLW"%s", stattostr(i + 1));
			input = readline(": "CLR BOLD);
			if (!input) { return; }
			if (!strcmp(input, "exit")) { return; }
			if (!strcmp(input, "back")) { i -= 2; goto end_of_loop; }
			if (!strcmp(input, "skip")) { i++; goto end_of_loop; }
		}
		stats[i] = strtod(input, NULL);
		free(input);
		if (stats[i] == -1) { stats[i] = 0; }
		end_of_loop:;
	}
	printf(PRP"Stats have been created\n"CLR);
}

void	print_stats(double stats[16])
{
	for (int i = 0; i < VICTIM - 1 && stats[i] > -1; ++i) {
		printf("%s", stattostr(i + 1));
		if (stats[i] < 1 && stats[i] != 0.0f)
			printf(" %.0f%%", stats[i] * 100);
		else
			printf(" %.0f", stats[i]);
		printf("\n");
	}
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
	if (!strcmp(str, "SPD"))
		return (SPD);
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
	if (stat == SPD)
		return ("SPD");
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
