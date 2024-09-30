#include "Damage.h"

// Canonical Orthodox Form
Damage::Damage(const std::string &name, const Kit &kit, const t_type &type)
	: _name(name), _linkedKit(kit), _type(type)
{}

Damage::Damage(const Damage &src)
: _name(src._name), _linkedKit(src._linkedKit), _type(src._type)
{}

Damage &Damage::operator=(const Damage &rhs) {
	const_cast<std::string &>(this->_name) = rhs._name;
	const_cast<Kit &>(this->_linkedKit) = rhs._linkedKit;
	const_cast<t_type &>(this->_type) = rhs._type;
	return *this;
}

Damage::~Damage() {}

// Methods
void Damage::addRatio(t_stats stat, float ratio) {
	this->_stats.push_back(stat);
	this->_ratios.push_back(ratio);
}

float Damage::calculateDamage(const Kit &victim, bool details)
{
	float damage;
	float critDamage = 0;
	float critChance;
	float instance;

	damage = 0;
	if (details)
		std::cout << BCYN << _name << CYN ": " CLR; 
	for (size_t i = 0; _stats[i] != ESTATS_END; i++)
	{
		if (_stats[i] >= VICTIM_PVS)
			instance = _ratios[i] * victim.extractStat((t_stats)(this->_stats[i] - VICTIM_PVS));
		else
			instance = _ratios[i] * _linkedKit.extractStat(_stats[i]);
		if (details)
		{
			std::cout << BBLK << roundf(_ratios[i] * 100) << "% ";
			std::cout << Stats::statToStr(_stats[i]);
			std::cout << "(" << roundf(instance) << ")";
			if (_stats[i + 1] != ESTATS_END)
				std::cout << " + ";
			else
				std::cout << " -> ";
		}
		damage += instance;
	}
	if (details)
		std::cout << CLR << roundf(damage);
	if ((critChance = _linkedKit.extractStat(CRC)))
		critDamage = damage * (_linkedKit.extractStat(CRM));
	damage *= calculateReduction(victim);
	critDamage *= calculateReduction(victim);
	if (details)
	{
		std::cout << CLR " = " PRP "-" << roundf(damage) << " PVS" CLR;
		if (critDamage)
		{
			std::cout << RED " + " << roundf(critDamage) << " PVS" CLR;
			critDamage = damage * (1 - critChance + critChance * (1 + _linkedKit.extractStat(CRM)));
			std::cout << BBLK " ( ~ -" << roundf(critDamage) << " PVS )" CLR;
		}
		std::cout << std::endl;
	}
	damage *= (1 - critChance + critChance * (1 + _linkedKit.extractStat(CRM)));
	return damage;
}

float Damage::calculateReduction(const Kit &victim) {
	float victimStat;

	victimStat = 0;
	switch (_type)
	{
	case PHYSICAL:
		victimStat = victim.getStats().getValue(DEF);
		victimStat *= 1 - _linkedKit.getStats().getValue(IGD);
		victimStat -= _linkedKit.getStats().getValue(LET);
		break ;
	case MAGICAL:
		victimStat = victim.getStats().getValue(RES);
		victimStat *= Damage::penToMultiplier(_linkedKit.getStats().getValue(PEN), victim.getStats().getValue(RES));
		break ;
	default:
		break ;
	}
	victimStat = Damage::statToReduction(victimStat);
	return victimStat;
}

// Static
float Damage::statToReduction(float stat)
{
	if (stat > 0)
		return (200.0f / (200.0f + stat));
	else
		return (2.0f - 200.0f/(200.0f - stat));
}

float Damage::penToMultiplier(float pen, float res)
{
	res = 1.0f / Damage::statToReduction(res);
	return 1.0f + res * pen / 2500.0f;
}
