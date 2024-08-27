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

Stats::Stats(unsigned int pvs, unsigned int rgn, unsigned int atk, unsigned int pwr, unsigned int def, unsigned int res,
			 unsigned int spd, unsigned int let, float igd, unsigned int pen, float tnc, float rsl, float vmp, float avp,
			 unsigned int cdr, unsigned int crc, float crm) {
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
	return Stats(s);
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

unsigned int Stats::getPvs() const {
	return _pvs;
}

void Stats::setPvs(unsigned int pvs) {
	_pvs = pvs;
}

unsigned int Stats::getRgn() const {
	return _rgn;
}

void Stats::setRgn(unsigned int rgn) {
	_rgn = rgn;
}

unsigned int Stats::getAtk() const {
	return _atk;
}

void Stats::setAtk(unsigned int atk) {
	_atk = atk;
}

unsigned int Stats::getPwr() const {
	return _pwr;
}

void Stats::setPwr(unsigned int pwr) {
	_pwr = pwr;
}

unsigned int Stats::getDef() const {
	return _def;
}

void Stats::setDef(unsigned int def) {
	_def = def;
}

unsigned int Stats::getRes() const {
	return _res;
}

void Stats::setRes(unsigned int res) {
	_res = res;
}

unsigned int Stats::getSpd() const {
	return _spd;
}

void Stats::setSpd(unsigned int spd) {
	_spd = spd;
}

unsigned int Stats::getLet() const {
	return _let;
}

void Stats::setLet(unsigned int let) {
	_let = let;
}

float Stats::getIgd() const {
	return _igd;
}

void Stats::setIgd(float igd) {
	_igd = igd;
}

unsigned int Stats::getPen() const {
	return _pen;
}

void Stats::setPen(unsigned int pen) {
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

unsigned int Stats::getCdr() const {
	return _cdr;
}

void Stats::setCdr(unsigned int cdr) {
	_cdr = cdr;
}

unsigned int Stats::getCrc() const {
	return _crc;
}

void Stats::setCrc(unsigned int crc) {
	_crc = crc;
}

float Stats::getCrm() const {
	return _crm;
}

void Stats::setCrm(float crm) {
	_crm = crm;
}
