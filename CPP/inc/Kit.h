#ifndef KIT_H
# define KIT_H

# include <iostream>
# include <string>
# include <vector>

class Kit;

# include "Stats.h"
# include "Damage.h"
# include "colors.h"

# define KIT_DEFAULT_NAME "Template"

class Kit
{
public:
	// Static
	static const Kit templateKit;
	static const std::string templateName;
	static const Stats templateStats;
	static const Stats nullStats;

	// Orthodox Canonical Form
	Kit();
	Kit(const std::string &name, const Stats &stats);
	Kit(const Kit &src);
	Kit &operator=(const Kit &rhs);
	~Kit();

	// Accessors
	const std::string &getName() const;
	void setName(const std::string &name);
	const Stats &getStats() const;
	void setStats(const Stats &stats);
	const float &getCurrPV() const;
	void setCurrPV(const float &currPV);
	const bool &getIsDead() const;
	const std::vector<class Damage> &getAttacks();
	float extractStat(t_stats stat) const;

	// Overloads
	friend std::ostream &operator<<(std::ostream &os, const Kit &kit);
	Kit &operator=(float rhs);
	Kit &operator+=(float rhs);
	Kit &operator-=(float rhs);
	Kit &operator+=(const Stats &rhs);
	Kit &operator-=(const Stats &rhs);
	bool operator==(const Kit &rhs) const;
	bool operator!=(const Kit &rhs) const;

	// Methods
	void changePV(float amount);
	void addAttack(Damage attack);
	void removeAttack(const std::string &name);

private:
	const std::string _name;
	const Stats _stats;
	std::vector<class Damage> _attacks;
	float _currPV;
	float _shield;
	bool _isDead;
};

#endif //KIT
