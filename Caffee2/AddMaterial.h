#ifndef ADDMATERIAL
#define ADDMATERIAL

#include<string>
using namespace std;

class AddMaterial
{
public:
	AddMaterial(){};
	void  AddCappuccino(double & p,string CupSize);		//卡布奇诺
	void  AddLatte(double & p, string CupSize);		//拿铁咖啡
	void  AddMocha(double & p, string CupSize);		//摩卡咖啡
	void  AddBlueMountain(double & p, string CupSize);	//蓝山咖啡
	void  AddCastorSugar(double & p);		//咖啡加白沙糖
	void  AddCubicSugar(double & p);		//咖啡加方糖糖
	void  AddMilk(double & p);		//咖啡加牛奶
	void  AddCheese(double & P);	//咖啡加奶酪
	double  GetExchange(double &,double &);	//找零钱
};


#endif ADDMATERIAL
