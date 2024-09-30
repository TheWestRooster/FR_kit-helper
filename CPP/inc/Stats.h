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
	MPV,
	CPV,
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
	VICTIM_PVS,
	VICTIM_MPV,
	VICTIM_CPV,
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
	ESTATS_END
} t_stats;

class Stats {
private:
	float _pvs;
	float _rgn;
	float _atk;
	float _pwr;
	float _def;
	float _res;
	float _spd;
	float _let;
	float _igd;
	float _pen;
	float _tnc;
	float _rsl;
	float _vmp;
	float _avp;
	float _cdr;
	float _crc;
	float _crm;
public:
	Stats();
	Stats(float pvs, float rgn, float atk, float pwr, float def, float res,
		  float spd, float let, float igd, float pen, float tnc, float rsl, float vmp, float avp,
		  float cdr, float crc, float crm);
	Stats(const Stats &s);
	Stats operator=(const Stats &s);

	friend std::ostream &operator<<(std::ostream &os, const Stats &stats);
	Stats operator+(const Stats &rhs);

	static const std::string statToStr(t_stats stat);

	float getPvs() const;
	void setPvs(float pvs);
	float getRgn() const;
	void setRgn(float rgn);
	float getAtk() const;
	void setAtk(float atk);
	float getPwr() const;
	void setPwr(float pwr);
	float getDef() const;
	void setDef(float def);
	float getRes() const;
	void setRes(float res);
	float getSpd() const;
	void setSpd(float spd);
	float getLet() const;
	void setLet(float let);
	float getIgd() const;
	void setIgd(float igd);
	float getPen() const;
	void setPen(float pen);
	float getTnc() const;
	void setTnc(float tnc);
	float getRsl() const;
	void setRsl(float rsl);
	float getVmp() const;
	void setVmp(float vmp);
	float getAvp() const;
	void setAvp(float avp);
	float getCdr() const;
	void setCdr(float cdr);
	float getCrc() const;
	void setCrc(float crc);
	float getCrm() const;
	void setCrm(float crm);
};


#endif //CPP_STATS_H
