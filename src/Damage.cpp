#include "Damage.h"


// Canonical Orthodox Form
Damage::Damage()
	: _name("None"), _type(ETYPE_END), _cooldown(0), _base(0)
{}

Damage::Damage(const std::string &name, t_type type, float cooldown, float base)
	: _name(name), _type(type), _cooldown(cooldown), _base(base)
{}

Damage::Damage(const Damage &src) {
	*this = src;
}

Damage &Damage::operator=(const Damage &rhs) {
	const_cast<std::string &>(this->_name) = rhs._name;
	this->_type = rhs._type;
	this->_cooldown = rhs._cooldown;
	_base = rhs._base;
	_stats = rhs._stats;
	_ratios = rhs._ratios;
	return *this;
}

Damage::~Damage() = default;

// Accessors
const std::string &Damage::getName() const {
	return _name;
}

void Damage::setName(const std::string &name) {
	const_cast<std::string &>(_name) = name;
}

t_type Damage::getType() const {
	return _type;
}

void Damage::setType(t_type type) {
	const_cast<t_type &>(_type) = type;
}

const float &Damage::getCooldown() const
{
	return _cooldown;
}

void Damage::setCooldown(const float &cooldown)
{
	const_cast<float &>(_cooldown) = cooldown;
}

const float & Damage::getBase() const {
	return _base;
}

void Damage::setBase(float base) {
	const_cast<float &>(_base) = base;
}

const std::vector<float> & Damage::getRatios() const {
	return _ratios;
}

const std::vector<t_stats> & Damage::getStats() const {
	return _stats;
}

// Methods
void Damage::addRatio(t_stats stat, float ratio) {
	this->_stats.push_back(stat);
	this->_ratios.push_back(ratio);
}

void Damage::popRatio()
{
	if (_ratios.empty())
		return
	_stats.pop_back();
	_ratios.pop_back();
}

float Damage::calculateDamage(const Kit &attacker, const Kit &victim, bool details)
{
	float damage;
	float critDamage = 0;
	float critChance;
	float instance;

	damage = _base;
	if (details)
		std::cout << BCYN << _name << CYN ": " CLR << _base;
	for (size_t i = 0; i < _stats.size(); i++)
	{
		if (_stats[i] >= VICTIM_PVS)
			instance = _ratios[i] * victim.extractStat((t_stats)(this->_stats[i] - VICTIM_PVS));
		else
			instance = _ratios[i] * attacker.extractStat(_stats[i]);
		if (details)
		{
			std::cout << BBLK " + ";
			std::cout << roundf(_ratios[i] * 100) << "% ";
			std::cout << Stats::statToStr(_stats[i]);
			std::cout << "(" << roundf(instance) << ")";
		}
		damage += instance;
	}
	if (details)
		std::cout << " -> " CLR << roundf(damage);
	damage *= calculateReduction(attacker, victim);
	if ((critChance = attacker.extractStat(CRIT_CHANCE)))
		critDamage = damage * (attacker.extractStat(CRIT_DAMAGE));
	if (details)
	{
		std::cout << CLR " = " PRP "-" << roundf(damage) << " PVS" CLR;
		if (critDamage)
		{
			std::cout << RED " + " << roundf(critDamage) << " PVS" CLR;
			critDamage = damage * (1 - critChance + critChance * (1 + attacker.extractStat(CRIT_DAMAGE)));
			std::cout << BBLK " ( ~ -" << roundf(critDamage) << " PVS )" CLR;
		}
		std::cout << std::endl;
	}
	damage *= (1 - critChance + critChance * (1 + attacker.extractStat(CRIT_DAMAGE)));
	return damage;
}

float Damage::calculateReduction(const Kit &attacker, const Kit &victim) {
	float victimStat;

	victimStat = 0;
	switch (_type)
	{
	case PHYSICAL:
		victimStat = victim.getStats().getValue(DEF);
		victimStat *= 1 - attacker.getStats().getValue(IGD);
		victimStat -= attacker.getStats().getValue(LET);
		break ;
	case MAGICAL:
		victimStat = victim.getStats().getValue(RES);
		break ;
	default:
		break ;
	}
	victimStat = Damage::statToReduction(victimStat);
	if (_type == MAGICAL)
		victimStat *= Damage::penToMultiplier(attacker.getStats().getValue(PEN), victimStat);
	return victimStat;
}

float Damage::calculateDPS(const Kit &attacker, const Kit &victim)
{
	return calculateDamage(attacker, victim) / _cooldown;
}

// Overloads
std::ostream & operator<<(std::ostream &os, const Damage &damage) {
	os << damage.getName() << ": ";
	os << damage.getBase();
	for (size_t i = 0; i < damage._stats.size(); ++i) {
		os << " + ";
		os << roundf(damage.getRatios()[i] * 100.0f) << "% ";
		os << Stats::statToStr(damage.getStats()[i]);
	}
	return (os);
}

bool Damage::operator==(const Damage &rhs) const {
	if (_name != rhs._name)
		return false;
	if (_type != rhs._type)
		return false;
	if (_stats != rhs._stats)
		return (false);
	if (_ratios != rhs._ratios)
		return (false);
	return true;
}

bool Damage::operator!=(const Damage &rhs) const {
	return !(*this == rhs);
}

Damage & Damage::operator+=(const Damage &rhs) {
	for (size_t i = 0; i < rhs._stats.size(); i++)
		this->addRatio(rhs._stats[i], rhs._ratios[i]);
	return *this;
}

Damage & Damage::operator--() {
	this->popRatio();
	return (*this);
}

// Static
const Damage Damage::damageNull;

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

std::string Damage::typeToStr(t_type type) {
	switch (type) {
		case PHYSICAL:
			return "PHYSICAL";
		case MAGICAL:
			return "MAGICAL";
		case BRUT:
			return "BRUT";
		default:
			return "";
	}
}

t_type Damage::strToType(const std::string &name) {
	if (name == "PHYSICAL") return PHYSICAL;
	if (name == "MAGICAL") return MAGICAL;
	if (name == "BRUT") return BRUT;
	return ETYPE_END;
}
