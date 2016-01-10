#include"AddMaterial.h"

//卡布奇诺咖啡的价格,并运动到相应的位置
void AddMaterial::AddCappuccino(double & p, string CupSize)
{
	//添加运动到相应工位的代码

	if ( CupSize == "large")	//大杯
	  p = p + 30;
	if (CupSize == "small")	//小杯
		p = p + 20;
}

//拿铁的价钱,并运动到相应的位置
void AddMaterial::AddLatte(double & p, string CupSize)
{
	//添加运动到相应工位的代码

	if (CupSize == "large")	//大杯
		p = p + 30;
	if (CupSize == "small")	//小杯
		p = p + 20;

}

//摩卡的价钱,并运动到相应的位置
void AddMaterial::AddMocha(double & p,string CupSize)
{
	//添加运动到相应工位的代码

	if (CupSize == "large")	//大杯
		p = p + 30;
	if (CupSize == "small")	//小杯
		p = p + 20;
}

//蓝山咖啡的价钱，并运动到相应位置
void AddMaterial::AddBlueMountain(double & p,string CupSize)
{
	//添加运动到相应工位的代码

	if (CupSize == "large")	//大杯
		p = p + 25;
	if (CupSize == "small")	//小杯
		p = p + 15;
}

//加糖要多加0.5元,并运动到相应的位置
void AddMaterial::AddCastorSugar(double & p)	//p为咖啡的初始价格，获得添加白砂糖后的价格
{
	//添加运动到相应工位的代码

	p = p + 1;

}

void AddMaterial::AddCubicSugar(double & p)	//p为咖啡的初始价格，获得添加白砂糖后的价格
{
	//添加运动到相应工位的代码

	p = p + 1;

}

//加牛奶要多加1.5元,并运动到相应的位置
void AddMaterial::AddMilk(double & p)	//p为咖啡的初始价格
{
	//添加运动到相应工位的代码

	p = p + 1.5;
	
}

//添加奶酪多加1.5元，并运动到相应位置
void AddMaterial::AddCheese(double & p)	//p为咖啡的初始价格
{
	//添加运动到相应工位的代码

	p = p + 1.5;

}

//找零钱，第一个参数是投入的金额，第二个参数是咖啡总价格
double  AddMaterial::GetExchange(double & inMoney, double & p)
{
	return (inMoney - p);
}
