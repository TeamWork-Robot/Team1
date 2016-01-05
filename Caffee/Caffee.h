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
	AddMaterial add;

public:
	Caffee(){};
	Caffee(string name = "");	//初始化咖啡只需要名字，首字母大写
	void addSugar();
	void addMilk();
	double getPrice();
	double getExchane(double);
};


#endif CAFFEE

