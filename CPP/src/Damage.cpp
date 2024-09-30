#include "Damage.h"

// Canonical Orthodox Form
Damage::Damage(const std::string &name, const Kit &kit) : _name(name), _linkedKit(kit) {
}

Damage::Damage(const Damage &src) : _name(src._name), _linkedKit(src._linkedKit) {
}

Damage &Damage::operator=(const Damage &rhs) {
	const_cast<Kit &>(this->_linkedKit) = rhs._linkedKit;
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
	float instance;

	damage = 0;
	if (details)
		std::cout << BCYN << _name << CYN ": " CLR; 
	for (size_t i = 0; true; i++)
	{
		if (i > _ratios.size() || i > _stats.size())
			break;
		if (_stats[i] >= VICTIM_PVS)
			instance = _ratios[i] * victim.extractStat((t_stats)(this->_stats[i] - VICTIM_PVS));
		else
			instance = _ratios[i] * _linkedKit.extractStat(_stats[i]);
		if (details)
		{
			std::cout << BBLK << roundf(_ratios[i] * 100) << "% ";
			std::cout << Stats::statToStr(_stats[i]);
			std::cout << "(" << roundf(instance) << ")";
			if (i < _ratios.size() && i < _stats.size())
				std::cout << " + ";
			else
				std::cout << " = " CLR;
		}
		damage += instance;
	}
	if (details)
		std::cout << CLR BOLD << roundf(damage) << CLR << std::endl;
	return damage;
}
