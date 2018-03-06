#ifndef ALGORYTHM_H
#define ALGORYTHM_H
#include <string>
#include <vector>

class Algorythm
{
	std::string name;
	void(*sortowanie) (std::vector<int>&);

public:
	Algorythm(std::string name, void(*sortowanie) (std::vector<int>&));

	std::string getName() const;
	void setName(std::string name);
	void sort(std::vector<int>& tab);
};

#endif // ALGORYTHM_H