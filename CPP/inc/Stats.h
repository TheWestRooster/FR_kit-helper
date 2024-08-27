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

class Stats {
private:
	unsigned int _pvs;
	unsigned int _rgn;
	unsigned int _atk;
	unsigned int _pwr;
	unsigned int _def;
	unsigned int _res;
	unsigned int _spd;
	unsigned int _let;
	float		 _igd;
	unsigned int _pen;
	float		 _tnc;
	float		 _rsl;
	float		 _vmp;
	float		 _avp;
	unsigned int _cdr;
	unsigned int _crc;
	float		 _crm;
public:
	Stats();
	Stats(unsigned int pvs, unsigned int rgn, unsigned int atk, unsigned int pwr, unsigned int def, unsigned int res,
		  unsigned int spd, unsigned int let, float igd, unsigned int pen, float tnc, float rsl, float vmp, float avp,
		  unsigned int cdr, unsigned int crc, float crm);
	Stats(const Stats &s);
	Stats operator=(const Stats &s);

	friend std::ostream &operator<<(std::ostream &os, const Stats &stats);
	
	unsigned int getPvs() const;
	void setPvs(unsigned int pvs);
	unsigned int getRgn() const;
	void setRgn(unsigned int rgn);
	unsigned int getAtk() const;
	void setAtk(unsigned int atk);
	unsigned int getPwr() const;
	void setPwr(unsigned int pwr);
	unsigned int getDef() const;
	void setDef(unsigned int def);
	unsigned int getRes() const;
	void setRes(unsigned int res);
	unsigned int getSpd() const;
	void setSpd(unsigned int spd);
	unsigned int getLet() const;
	void setLet(unsigned int let);
	float getIgd() const;
	void setIgd(float igd);
	unsigned int getPen() const;
	void setPen(unsigned int pen);
	float getTnc() const;
	void setTnc(float tnc);
	float getRsl() const;
	void setRsl(float rsl);
	float getVmp() const;
	void setVmp(float vmp);
	float getAvp() const;
	void setAvp(float avp);
	unsigned int getCdr() const;
	void setCdr(unsigned int cdr);
	unsigned int getCrc() const;
	void setCrc(unsigned int crc);
	float getCrm() const;
	void setCrm(float crm);
};


#endif //CPP_STATS_H
