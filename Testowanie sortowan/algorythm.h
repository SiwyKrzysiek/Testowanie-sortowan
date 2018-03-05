#ifndef ALGORYTHM_H
#define ALGORYTHM_H
#include <string>
#include <vector>

class Algorythm
{
	std::string name;
	void(*sortowanie) (std::vector<int>);

public:
	Algorythm();

	std::string getName() const;
	void setName(std::string name);
};

#endif // ALGORYTHM_H