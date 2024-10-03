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
	// Static
	static const Damage damageNull;

	// Orthodox Canonical Form
	Damage();
	Damage(const std::string &name, t_type type, float cooldown, float base);
	Damage(const Damage &src);
	Damage &operator=(const Damage &rhs);
	~Damage();

	// Accessors
	const std::string &getName() const;
	void setName(const std::string &name);
	t_type getType() const;
	void setType(t_type type);
	const float &getCooldown() const;
	void setCooldown(const float &cooldown);
	const float &getBase() const;
	void setBase(float base);
	const std::vector<float> &getRatios() const;
	const std::vector<t_stats> &getStats() const;

	// Methods
	void addRatio(t_stats stat, float ratio);
	void popRatio();
	float calculateDamage(const Kit &attacker, const Kit &victim, bool details=false);
	float calculateReduction(const Kit &attacker, const Kit &victim);
	float calculateDPS(const Kit &attacker, const Kit &victim);

	// Overloads
	friend std::ostream &operator<<(std::ostream &os, const Damage &damage);
	bool operator==(const Damage &rhs) const;
	bool operator!=(const Damage &rhs) const;
	Damage &operator+=(const Damage &rhs);
	Damage &operator--();

	// Static
	static float statToReduction(float stat);
	static float penToMultiplier(float pen, float res);
	static std::string typeToStr(t_type type);
	static t_type strToType(const std::string &name);

private:
	const std::string _name;
	t_type _type;
	float _cooldown;
	float _base;
	std::vector<t_stats> _stats;
	std::vector<float> _ratios;
};

#endif //DAMAGE
