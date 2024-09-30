//
// Created by mscheman on 8/27/24.
//

#ifndef CPP_STATS_H
#define CPP_STATS_H

#include <ostream>
#include <iostream>
#include <string>
#include <cmath>
#include "colors.h"

typedef enum e_stats {
	PVS = 0,
	RGN,
	ATK,
	PWR,
	DEF,
	RES,
	SPD,
	LET,
	IGD,
	PEN,
	TNC,
	RSL,
	VMP,
	AVP,
	CDR,
	CRC,
	CRM,
	MPV,
	CPV,
	VICTIM_PVS,
	VICTIM_RGN,
	VICTIM_ATK,
	VICTIM_PWR,
	VICTIM_DEF,
	VICTIM_RES,
	VICTIM_SPD,
	VICTIM_LET,
	VICTIM_IGD,
	VICTIM_PEN,
	VICTIM_TNC,
	VICTIM_RSL,
	VICTIM_VMP,
	VICTIM_AVP,
	VICTIM_CDR,
	VICTIM_CRC,
	VICTIM_CRM,
	VICTIM_MPV,
	VICTIM_CPV,
	ESTATS_END
} t_stats;

class Stats {
private:
	float _stats[CRM + 1];
public:
	// Canonical Orthodox Form
	Stats();
	Stats(float stats[CRM + 1]);
	Stats(const Stats &s);
	Stats &operator=(const Stats &s);

	// Overloads
	friend std::ostream &operator<<(std::ostream &os, const Stats &stats);
	Stats &operator+=(const Stats &rhs);

	// Static
	static const std::string statToStr(t_stats stat);
	static t_stats strToStat(const std::string &str);

	// Accessors
	float getValue(t_stats stat) const;
	void setValue(t_stats stat, float newValue);
};


#endif //CPP_STATS_H
