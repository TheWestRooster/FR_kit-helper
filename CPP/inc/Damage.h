#ifndef DAMAGE_H
# define DAMAGE_H

# include <iostream>
# include <string>
# include <vector>
# include "Kit.h"
# include "Stats.h"
# include "colors.h"

class Damage
{
public:
	// Orthodox Canonical Form
	Damage(const std::string &name, const Kit &kit);
	Damage(const Damage &src);
	Damage&operator=(const Damage &rhs);
	~Damage();

	// Methods
	void addRatio(t_stats stat, float ratio);
	float calculateDamage(const Kit &victim, bool details=false);

private:
	const std::string &_name;
	const Kit &_linkedKit;
	std::vector<t_stats> _stats;
	std::vector<float> _ratios;
};

#endif //DAMAGE
