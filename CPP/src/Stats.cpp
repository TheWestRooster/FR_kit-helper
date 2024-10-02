//
// Created by mscheman on 8/27/24.
//

#include "Stats.h"

// Orthodox Canonical Form
Stats::Stats() {
	this->_stats[PVS] = 2500;
	this->_stats[RGN] = 5;
	this->_stats[ATK] = 200;
	this->_stats[PWR] = 0;
	this->_stats[DEF] = 100;
	this->_stats[RES] = 100;
	this->_stats[SPD] = 100;
	this->_stats[LET] = 0;
	this->_stats[IGD] = 0;
	this->_stats[PEN] = 0;
	this->_stats[TNC] = 0;
	this->_stats[RSL] = 0;
	this->_stats[VMP] = 0;
	this->_stats[AVP] = 0;
	this->_stats[CDR] = 0;
	this->_stats[CRIT_CHANCE] = 0;
	this->_stats[CRIT_DAMAGE] = 0.5;
}

Stats::Stats(float stats[CRIT_DAMAGE + 1])
{
	for (int i = 0; i < CRIT_DAMAGE + 1; i++)
	{
		if (!stats)
			_stats[i] = 0;
		else
			_stats[i] = stats[i];
	}
}

Stats::Stats(const Stats &s) {
	for (int i = 0; i < CRIT_DAMAGE + 1; i++)
		_stats[i] = s._stats[i];
}

Stats &Stats::operator=(const Stats &s) {
	for (int i = 0; i < CRIT_DAMAGE + 1; i++)
		_stats[i] = s._stats[i];
	return (*this);
}

// Accessors
float Stats::getValue(t_stats stat) const
{
	return _stats[stat];
}

void Stats::setValue(t_stats stat, float newValue) {
	_stats[stat] = newValue;
}

// Overloads
std::ostream &operator<<(std::ostream &os, const Stats &stats) {
	std::cout << BGRN " PVs: " CLR << stats.getValue(PVS) << std::endl;
	std::cout << BGRN " Regen: " CLR << 5 * stats.getValue(RGN) << "PVs/5s" << std::endl;
	std::cout << BRED " Attack: " CLR << stats.getValue(ATK) << std::endl;
	std::cout << BRED " Power: " CLR << stats.getValue(PWR) << std::endl;
	std::cout << BYLW " Defense: " CLR << stats.getValue(DEF) << std::endl;
	std::cout << BYLW " Resistance: " CLR << stats.getValue(RES) << std::endl;
	std::cout << BCYN " Speed: " CLR << stats.getValue(SPD) << std::endl;
	std::cout << BBLU " Lethality: " CLR << stats.getValue(LET) << std::endl;
	std::cout << BBLU " Ignore Def.: " CLR << roundf(stats.getValue(IGD) * 100) << "%" << std::endl;
	std::cout << BBLU " Penetration: " CLR << stats.getValue(PEN) << std::endl;
	std::cout << BCYN " Tenacity: " CLR << roundf(stats.getValue(TNC) * 100) << "%" << std::endl;
	std::cout << BCYN " Resilience: " CLR << roundf(stats.getValue(RSL) * 100) << "%" << std::endl;
	std::cout << BPRP " Vamp: " CLR << roundf(stats.getValue(VMP) * 100) << "%" << std::endl;
	std::cout << BPRP " AntiVamp: " CLR << roundf(stats.getValue(AVP) * 100) << "%" << std::endl;
	std::cout << BCYN " CDR: " CLR << stats.getValue(CDR) << std::endl;
	std::cout << BRED " CritChance: " CLR << stats.getValue(CRIT_CHANCE) * 100 << std::endl;
	std::cout << BRED " CritDamage: " CLR << roundf(stats.getValue(CRIT_DAMAGE) * 100) << "%" << std::endl;
	return os;
}

Stats &Stats::operator+=(const Stats &rhs)
{
	for (int i = 0; i < CRIT_DAMAGE + 1; i++)
		_stats[i] += rhs._stats[i];
	return (*this);
}

Stats &Stats::operator-=(const Stats &rhs)
{
	for (int i = 0; i < CRIT_DAMAGE + 1; i++)
		_stats[i] -= rhs._stats[i];
	return (*this);
}

bool Stats::operator==(const Stats &rhs) const {
	for (int i = 0; i < CRIT_DAMAGE + 1; i++)
	{
		if (_stats[i] != rhs._stats[i])
			return false;
	}
	return true;
}

bool Stats::operator!=(const Stats &rhs) const {
	return !(*this == rhs);
}

// Static
const std::string Stats::statToStr(t_stats stat)
{
	switch (stat)
	{
	case PVS:
		return "PVS";
	case MISSING_PVS:
		return "MISSING_PVS";
	case CURRENT_PVS:
		return "CURRENT_PVS";
	case RGN:
		return "RGN";
	case ATK:
		return "ATK";
	case PWR:
		return "PWR";
	case DEF:
		return "DEF";
	case RES:
		return "RES";
	case SPD:
		return "SPD";
	case LET:
		return "LET";
	case IGD:
		return "IGD";
	case PEN:
		return "PEN";
	case TNC:
		return "TNC";
	case RSL:
		return "RSL";
	case VMP:
		return "VMP";
	case AVP:
		return "AVP";
	case CDR:
		return "CDR";
	case CRIT_CHANCE:
		return "CRIT_CHANCE";
	case CRIT_DAMAGE:
		return "CRIT_DAMAGE";
	case VICTIM_PVS:
		return "VICTIM_PVS";
	case VICTIM_MISSING_PVS:
		return "VICTIM_MISSING_PVS";
	case VICTIM_CURRENT_PVS:
		return "VICTIM_CURRENT_PVS";
	case VICTIM_RGN:
		return "VICTIM_RGN";
	case VICTIM_ATK:
		return "VICTIM_ATK";
	case VICTIM_PWR:
		return "VICTIM_PWR";
	case VICTIM_DEF:
		return "VICTIM_DEF";
	case VICTIM_RES:
		return "VICTIM_RES";
	case VICTIM_SPD:
		return "VICTIM_SPD";
	case VICTIM_LET:
		return "VICTIM_LET";
	case VICTIM_IGD:
		return "VICTIM_IGD";
	case VICTIM_PEN:
		return "VICTIM_PEN";
	case VICTIM_TNC:
		return "VICTIM_TNC";
	case VICTIM_RSL:
		return "VICTIM_RSL";
	case VICTIM_VMP:
		return "VICTIM_VMP";
	case VICTIM_AVP:
		return "VICTIM_AVP";
	case VICTIM_CDR:
		return "VICTIM_CDR";
	case VICTIM_CRIT_CHANCE:
		return "VICTIM_CRIT_CHANCE";
	case VICTIM_CRIT_DAMAGE:
		return "VICTIM_CRIT_DAMAGE";
	default:
		return "";
	}
}

t_stats Stats::strToStat(const std::string &str)
{
	if (str == "PVS") return PVS;
	if (str == "MISSING_PVS") return MISSING_PVS;
	if (str == "CURRENT_PVS") return CURRENT_PVS;
	if (str == "RGN") return RGN;
	if (str == "ATK") return ATK;
	if (str == "PWR") return PWR;
	if (str == "DEF") return DEF;
	if (str == "RES") return RES;
	if (str == "SPD") return SPD;
	if (str == "LET") return LET;
	if (str == "IGD") return IGD;
	if (str == "PEN") return PEN;
	if (str == "TNC") return TNC;
	if (str == "RSL") return RSL;
	if (str == "VMP") return VMP;
	if (str == "AVP") return AVP;
	if (str == "CDR") return CDR;
	if (str == "CRIT_CHANCE") return CRIT_CHANCE;
	if (str == "CRIT_DAMAGE") return CRIT_DAMAGE;
	if (str == "VICTIM_PVS") return VICTIM_PVS;
	if (str == "VICTIM_MISSING_PVS") return VICTIM_MISSING_PVS;
	if (str == "VICTIM_CURRENT_PVS") return VICTIM_CURRENT_PVS;
	if (str == "VICTIM_RGN") return VICTIM_RGN;
	if (str == "VICTIM_ATK") return VICTIM_ATK;
	if (str == "VICTIM_PWR") return VICTIM_PWR;
	if (str == "VICTIM_DEF") return VICTIM_DEF;
	if (str == "VICTIM_RES") return VICTIM_RES;
	if (str == "VICTIM_SPD") return VICTIM_SPD;
	if (str == "VICTIM_LET") return VICTIM_LET;
	if (str == "VICTIM_IGD") return VICTIM_IGD;
	if (str == "VICTIM_PEN") return VICTIM_PEN;
	if (str == "VICTIM_TNC") return VICTIM_TNC;
	if (str == "VICTIM_RSL") return VICTIM_RSL;
	if (str == "VICTIM_VMP") return VICTIM_VMP;
	if (str == "VICTIM_AVP") return VICTIM_AVP;
	if (str == "VICTIM_CDR") return VICTIM_CDR;
	if (str == "VICTIM_CRIT_CHANCE") return VICTIM_CRIT_CHANCE;
	if (str == "VICTIM_CRIT_DAMAGE") return VICTIM_CRIT_DAMAGE;
	return ESTATS_END;
}
