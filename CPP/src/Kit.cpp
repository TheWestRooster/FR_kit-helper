#include "Kit.h"

// Canonical Orthodox Form

const std::string &Kit::templateName = KIT_DEFAULT_NAME;
const Stats &Kit::templateStats = Stats();

Kit::Kit() : _name(Kit::templateName), _stats(Kit::templateStats) {
	_currPV = getStats().getPvs();
	_isDead = false;
	_shield = 0;
}

Kit::Kit(const std::string &name, const Stats &stats) : _name(name), _stats(stats) {
	_currPV = getStats().getPvs();
	_isDead = false;
	_shield = 0;
}

Kit::Kit(const Kit &src) : _name(src._name), _stats(src._stats) {
	_currPV = getStats().getPvs();
	_isDead = src._isDead;
	_shield = src._shield;
}

Kit &Kit::operator=(const Kit &rhs) {
	const_cast<std::string &>(this->_name) = rhs._name;
	const_cast<Stats &>(this->_stats) = rhs._stats;
	_currPV = getStats().getPvs();
	_isDead = rhs._isDead;
	_shield = rhs._shield;
	return *this;
}

Kit::~Kit() {
}

// Accessors
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

// Overload
std::ostream &operator<<(std::ostream &os, const Kit &kit)
{
	std::cout << BOLD << kit._name << CLR << std::endl;
	std::cout << kit._stats;
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

// Methods
float Kit::extractStat(t_stats stat) const
{
	switch (stat)
	{
	case PVS:
		return this->getStats().getPvs();
	case MPV:
		return this->getStats().getPvs() - _currPV;
	case CPV:
		return _currPV;	
	case RGN:
		return this->getStats().getRgn();
	case ATK:
		return this->getStats().getAtk();
	case PWR:
		return this->getStats().getPwr();
	case DEF:
		return this->getStats().getDef();
	case RES:
		return this->getStats().getRes();
	case SPD:
		return this->getStats().getSpd();
	case LET:
		return this->getStats().getLet();
	case IGD:
		return this->getStats().getIgd();
	case PEN:
		return this->getStats().getPen();
	case TNC:
		return this->getStats().getTnc();
	case RSL:
		return this->getStats().getRsl();
	case VMP:
		return this->getStats().getVmp();
	case AVP:
		return this->getStats().getAvp();
	case CDR:
		return this->getStats().getCdr();
	case CRC:
		return this->getStats().getCrc();
	case CRM:
		return this->getStats().getCrm();
	default:
		return -1.0f;
	}
}

void Kit::changePV(float amount)
{
	if (_isDead)
		return ;
	_currPV += amount;
	if (_currPV > getStats().getPvs())
		_currPV = getStats().getPvs();
	if (_currPV > 0)
		return ;
	_currPV = 0;
	_isDead = true;
}
