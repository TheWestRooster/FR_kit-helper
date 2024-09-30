#ifndef KIT_H
# define KIT_H

# include <iostream>
# include <string>
# include "Stats.h"

class Kit;

# include "Damage.h"
# include "colors.h"

# define KIT_DEFAULT_NAME "Template"

class Kit
{
public:
	// Static
	static const std::string &templateName;
	static const Stats &templateStats;

	// Orthodox Canonical Form
	Kit();
	Kit(const std::string &name, const Stats &stats);
	Kit(const Kit &src);
	Kit &operator=(const Kit &rhs);
	~Kit();

	// Accessors
	const Stats &getStats() const;
	void setStats(const Stats &stats);
	const float &getCurrPV() const;
	void setCurrPV(const float &currPV);
	const bool &getIsDead() const;

	// Overloads
	friend std::ostream &operator<<(std::ostream &os, const Kit &kit);
	Kit &operator=(float rhs);
	Kit &operator+=(float rhs);
	Kit &operator-=(float rhs);

	// Methods
	float extractStat(t_stats stat) const;
	void changePV(float amount);

private:
	const std::string &_name;
	const Stats &_stats;
	float _currPV;
	float _shield;
	bool _isDead;
};

#endif //KIT
