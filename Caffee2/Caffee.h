#ifndef CAFFEE
#define CAFFEE

#include<string>
#include"AddMaterial.h"

using namespace std;

class Caffee
{
private:
	string caffeeName;
	double price;
	string Size;
	AddMaterial add;

public:
	Caffee(){};
	Caffee(string name = "",string CupSize = "");	//初始化咖啡只需要名字，首字母大写
	void addCastorSugar();
	void  addCubicSugar();
	void addMilk();
	void addCheese();
	double getPrice();
	double getExchane(double);
};


#endif CAFFEE

