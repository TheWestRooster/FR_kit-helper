#ifndef DAMAGE_H
# define DAMAGE_H

# include <iostream>
# include <string>
# include <vector>
# include "Kit.h"
# include "Stats.h"
# include "colors.h"

typedef enum e_type {
	PHYSICAL,
	MAGICAL,
	BRUT,
	ETYPE_END
} t_type;

class Damage
{
public:
	// Orthodox Canonical Form
	Damage(const std::string &name, const Kit &kit, const t_type &type, float cooldown, float base);
	Damage(const Damage &src);
	Damage &operator=(const Damage &rhs);
	~Damage();

	// Accessors
	const std::string &getName() const;
	void setName(const std::string &name);
	t_type getType() const;
	void setType(t_type type);
	const Kit &getLinkedKit() const;
	void setLinkedKit(const Kit &linkedKit);
	const float &getCooldown() const;
	void setCooldown(const float &cooldown);

	// Methods
	void addRatio(t_stats stat, float ratio);
	void popRatio();
	float calculateDamage(const Kit &victim, bool details=false);
	float calculateReduction(const Kit &victim);
	float calculateDPS(const Kit &victim);

	// Overloads
	bool operator==(const Damage &rhs) const;

	// Static
	static float statToReduction(float stat);
	static float penToMultiplier(float pen, float res);

private:
	const std::string _name;
	const Kit &_linkedKit;
	const t_type _type;
	const float _cooldown;
	float _base;
	std::vector<t_stats> _stats;
	std::vector<float> _ratios;
};

#endif //DAMAGE
