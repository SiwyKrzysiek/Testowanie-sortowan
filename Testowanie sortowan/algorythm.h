#ifndef ALGORYTHM_H
#define ALGORYTHM_H
#include <string>
#include <vector>

typedef void(*FuncSig)(std::vector<int>&);

class Algorythm
{
	std::string name;
	void(*sortowanie) (std::vector<int>&);

public:
	Algorythm(std::string name, void(*sortowanie) (std::vector<int>&));
	FuncSig getSortingFunction() const;
	std::string getName() const;
	void setName(std::string name);

	void sort(std::vector<int>& tab);
	friend std::ostream &operator<<(std::ostream &output, const Algorythm &algorythm);
};

#endif // ALGORYTHM_H