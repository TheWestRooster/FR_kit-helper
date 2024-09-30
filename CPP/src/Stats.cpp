//
// Created by mscheman on 8/27/24.
//

#include "Stats.h"

Stats::Stats() {
	this->_pvs = 2500;
	this->_rgn = 5;
	this->_atk = 200;
	this->_pwr = 0;
	this->_def = 100;
	this->_res = 100;
	this->_spd = 100;
	this->_let = 0;
	this->_igd = 0;
	this->_pen = 0;
	this->_tnc = 0;
	this->_rsl = 0;
	this->_vmp = 0;
	this->_avp = 0;
	this->_cdr = 0;
	this->_crc = 0;
	this->_crm = 0.5;
}

Stats::Stats(float pvs, float rgn, float atk, float pwr, float def, float res,
			 float spd, float let, float igd, float pen, float tnc, float rsl, float vmp, float avp,
			 float cdr, float crc, float crm) {
	this->_pvs = pvs;
	this->_rgn = rgn;
	this->_atk = atk;
	this->_pwr = pwr;
	this->_def = def;
	this->_res = res;
	this->_spd = spd;
	this->_let = let;
	this->_igd = igd;
	this->_pen = pen;
	this->_tnc = tnc;
	this->_rsl = rsl;
	this->_vmp = vmp;
	this->_avp = avp;
	this->_cdr = cdr;
	this->_crc = crc;
	this->_crm = crm;
}

Stats::Stats(const Stats &s) {
	this->_pvs = s._pvs;
	this->_rgn = s._rgn;
	this->_atk = s._atk;
	this->_pwr = s._pwr;
	this->_def = s._def;
	this->_res = s._res;
	this->_spd = s._spd;
	this->_let = s._let;
	this->_igd = s._igd;
	this->_pen = s._pen;
	this->_tnc = s._tnc;
	this->_rsl = s._rsl;
	this->_vmp = s._vmp;
	this->_avp = s._avp;
	this->_cdr = s._cdr;
	this->_crc = s._crc;
	this->_crm = s._crm;
}

Stats Stats::operator=(const Stats &s) {
	this->_pvs = s._pvs;
	this->_rgn = s._rgn;
	this->_atk = s._atk;
	this->_pwr = s._pwr;
	this->_def = s._def;
	this->_res = s._res;
	this->_spd = s._spd;
	this->_let = s._let;
	this->_igd = s._igd;
	this->_pen = s._pen;
	this->_tnc = s._tnc;
	this->_rsl = s._rsl;
	this->_vmp = s._vmp;
	this->_avp = s._avp;
	this->_cdr = s._cdr;
	this->_crc = s._crc;
	this->_crm = s._crm;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Stats &stats) {
	std::cout << BGRN " PVs: " CLR << stats._pvs << std::endl;
	std::cout << BGRN " Regen: " CLR << 5 * stats._rgn << "PVs/5s" << std::endl;
	std::cout << BRED " Attack: " CLR << stats._atk << std::endl;
	std::cout << BRED " Power: " CLR << stats._pwr << std::endl;
	std::cout << BYLW " Defense: " CLR << stats._def << std::endl;
	std::cout << BYLW " Resistance: " CLR << stats._res << std::endl;
	std::cout << BCYN " Speed: " CLR << stats._spd << std::endl;
	std::cout << BBLU " Lethality: " CLR << stats._let << std::endl;
	std::cout << BBLU " Ignore Def.: " CLR << roundf(stats._igd * 100) << "%" << std::endl;
	std::cout << BBLU " Penetration: " CLR << stats._pen << std::endl;
	std::cout << BCYN " Tenacity: " CLR << roundf(stats._tnc * 100) << "%" << std::endl;
	std::cout << BCYN " Resilience: " CLR << roundf(stats._rsl * 100) << "%" << std::endl;
	std::cout << BPRP " Vamp: " CLR << roundf(stats._vmp * 100) << "%" << std::endl;
	std::cout << BPRP " AntiVamp: " CLR << roundf(stats._avp * 100) << "%" << std::endl;
	std::cout << BCYN " CDR: " CLR << stats._cdr << std::endl;
	std::cout << BRED " CritChance: " CLR << stats._crc * 100 << std::endl;
	std::cout << BRED " CritDamage: " CLR << roundf(stats._crm * 100) << "%" << std::endl;
	return os;
}

Stats Stats::operator+(const Stats &rhs)
{
	Stats sum;
	sum._pvs = this->_pvs + rhs._pvs;
	sum._rgn = this->_rgn + rhs._rgn;
	sum._atk = this->_atk + rhs._atk;
	sum._pwr = this->_pwr + rhs._pwr;
	sum._def = this->_def + rhs._def;
	sum._res = this->_res + rhs._res;
	sum._spd = this->_spd + rhs._spd;
	sum._let = this->_let + rhs._let;
	sum._igd = this->_igd + rhs._igd;
	sum._pen = this->_pen + rhs._pen;
	sum._tnc = this->_tnc + rhs._tnc;
	sum._rsl = this->_rsl + rhs._rsl;
	sum._vmp = this->_vmp + rhs._vmp;
	sum._avp = this->_avp + rhs._avp;
	sum._cdr = this->_cdr + rhs._cdr;
	sum._crc = this->_crc + rhs._crc;
	sum._crm = this->_crm + rhs._crm;
	return sum;
}

const std::string Stats::statToStr(t_stats stat)
{
	switch (stat)
	{
	case PVS:
		return "PVS"; 
	case MPV:
		return "MISSING_PVS"; 
	case CPV:
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
	case CRC:
		return "CRIT_CHANCE";
	case CRM:
		return "CRIT_DAMAGE"; 
	case VICTIM_PVS:
		return "VICTIM_PVS"; 
	case VICTIM_MPV:
		return "VICTIM_MISSING_PVS"; 
	case VICTIM_CPV:
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
	case VICTIM_CRC:
		return "VICTIM_CRIT_CHANCE"; 
	case VICTIM_CRM:
		return "VICTIM_CRIT_DAMAGE"; 
	default:
		return "";
	}
}

float Stats::getPvs() const
{
	return _pvs;
}

void Stats::setPvs(float pvs) {
	_pvs = pvs;
}

float Stats::getRgn() const {
	return _rgn;
}

void Stats::setRgn(float rgn) {
	_rgn = rgn;
}

float Stats::getAtk() const {
	return _atk;
}

void Stats::setAtk(float atk) {
	_atk = atk;
}

float Stats::getPwr() const {
	return _pwr;
}

void Stats::setPwr(float pwr) {
	_pwr = pwr;
}

float Stats::getDef() const {
	return _def;
}

void Stats::setDef(float def) {
	_def = def;
}

float Stats::getRes() const {
	return _res;
}

void Stats::setRes(float res) {
	_res = res;
}

float Stats::getSpd() const {
	return _spd;
}

void Stats::setSpd(float spd) {
	_spd = spd;
}

float Stats::getLet() const {
	return _let;
}

void Stats::setLet(float let) {
	_let = let;
}

float Stats::getIgd() const {
	return _igd;
}

void Stats::setIgd(float igd) {
	_igd = igd;
}

float Stats::getPen() const {
	return _pen;
}

void Stats::setPen(float pen) {
	_pen = pen;
}

float Stats::getTnc() const {
	return _tnc;
}

void Stats::setTnc(float tnc) {
	_tnc = tnc;
}

float Stats::getRsl() const {
	return _rsl;
}

void Stats::setRsl(float rsl) {
	_rsl = rsl;
}

float Stats::getVmp() const {
	return _vmp;
}

void Stats::setVmp(float vmp) {
	_vmp = vmp;
}

float Stats::getAvp() const {
	return _avp;
}

void Stats::setAvp(float avp) {
	_avp = avp;
}

float Stats::getCdr() const {
	return _cdr;
}

void Stats::setCdr(float cdr) {
	_cdr = cdr;
}

float Stats::getCrc() const {
	return _crc;
}

void Stats::setCrc(float crc) {
	_crc = crc;
}

float Stats::getCrm() const {
	return _crm;
}

void Stats::setCrm(float crm) {
	_crm = crm;
}
