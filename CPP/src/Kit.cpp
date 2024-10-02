#include "Kit.h"

// Canonical Orthodox Form
const std::string Kit::templateName = KIT_DEFAULT_NAME;
const Stats Kit::templateStats = Stats();
const Stats Kit::nullStats = Stats({0});
const Kit Kit::templateKit = Kit();

Kit::Kit() : _name(Kit::templateName), _stats(Kit::templateStats) {
	_currPV = getStats().getValue(PVS);
	_isDead = false;
	_shield = 0;
}

Kit::Kit(const std::string &name, const Stats &stats) : _name(name), _stats(stats) {
	_currPV = getStats().getValue(PVS);
	_isDead = false;
	_shield = 0;
}

Kit::Kit(const Kit &src) : _name(src._name), _stats(src._stats) {
	this->_attacks = src._attacks;
	_currPV = getStats().getValue(PVS);
	_isDead = src._isDead;
	_shield = src._shield;
}

Kit &Kit::operator=(const Kit &rhs) {
	const_cast<std::string &>(this->_name) = rhs._name;
	const_cast<Stats &>(this->_stats) = rhs._stats;
	this->_attacks = rhs._attacks;
	_currPV = getStats().getValue(PVS);
	_isDead = rhs._isDead;
	_shield = rhs._shield;
	return *this;
}

Kit::~Kit() {
}

// Accessors
const std::string &Kit::getName() const {
	return _name;
}

void Kit::setName(const std::string &name) {
	const_cast<std::string &>(_name) = name;
}

const Stats& Kit::getStats() const {
	return this->_stats;
}

void Kit::setStats(const Stats &stats) {
	const_cast<Stats &>(this->_stats) = stats;
}

const float &Kit::getCurrPV() const
{
	return _currPV;
}

void Kit::setCurrPV(const float &currPV)
{
	_currPV = currPV;
	changePV(0);
}

const bool &Kit::getIsDead() const
{
	return _isDead;
}

const std::vector<class Damage> &Kit::getAttacks() const {
	return _attacks;
}

float Kit::extractStat(t_stats stat) const
{
	if (stat != CURRENT_PVS && stat != MISSING_PVS)
		return _stats.getValue(stat);
	if (stat == CURRENT_PVS)
		return _currPV;
	return _stats.getValue(PVS) - _currPV;
}

// Overload
std::ostream &operator<<(std::ostream &os, const Kit &kit)
{
	std::cout << BOLD << kit._name << CLR << std::endl;
	std::cout << kit._stats << std::endl;
	return os;
}

Kit &Kit::operator=(float rhs)
{
	setCurrPV(rhs);
	return (*this);
}

Kit &Kit::operator+=(float rhs)
{
	changePV(rhs);
	return (*this);
}

Kit &Kit::operator-=(float rhs)
{
	changePV(-rhs);
	return (*this);
}

Kit &Kit::operator+=(const Stats &rhs) {
	const_cast<Stats &>(_stats) += rhs;
	return (*this);
}

Kit &Kit::operator-=(const Stats &rhs) {
	const_cast<Stats &>(_stats) -= rhs;
	return (*this);
}

Kit & Kit::operator+=(const Damage &rhs) {
	for (size_t i = 0; i < _attacks.size(); ++i) {
		if (_attacks[i].getName() != rhs.getName())
			continue;
		_attacks[i] += rhs;
		return (*this);
	}
	addAttack(rhs);
	return *this;
}

bool Kit::operator==(const Kit &rhs) const {
	if (_name != rhs._name)
		return false;
	if (_stats != rhs._stats)
		return false;
	if (_attacks != rhs._attacks)
		return false;
	return true;
}

bool Kit::operator!=(const Kit &rhs) const {
	return !(*this == rhs);
}

// Methods
void Kit::changePV(float amount)
{
	if (_isDead)
		return ;
	_currPV += amount;
	if (_currPV > getStats().getValue(PVS))
		_currPV = getStats().getValue(PVS);
	if (_currPV > 0)
		return ;
	_currPV = 0;
	_isDead = true;
}

void Kit::addAttack(Damage attack) {
	if (attack == Damage::damageNull)
		return ;
	if (attack.getLinkedKit() != *this)
		attack.setLinkedKit(*this);
	_attacks.push_back(attack);
}

void Kit::removeAttack(const std::string &attack) {
	for (auto it = _attacks.begin(); it < _attacks.end(); it++)
	{
		if (it.base()->getName() != attack)
			continue ;
		_attacks.erase(it);
		return ;
	}
}

Damage &Kit::findAttack(const std::string &name) {
	for (auto it = _attacks.begin(); it < _attacks.end(); it++)
	{
		if (it.base()->getName() == name)
			return *it.base();
	}
	return const_cast<Damage &>(Damage::damageNull);
}
