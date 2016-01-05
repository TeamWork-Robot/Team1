#include"AddMaterial.h"

//卡布奇诺咖啡的价格,并运动到相应的位置
void AddMaterial::AddCappuccino(double & p)
{
	//添加运动到相应工位的代码

	p = p + 5;
}

//拿铁的价钱,并运动到相应的位置
void AddMaterial::AddLatte(double & p)
{
	//添加运动到相应工位的代码

	p = p + 4;

}

//摩卡的价钱,并运动到相应的位置
void AddMaterial::AddMocha(double & p)
{
	//添加运动到相应工位的代码

	p = p + 6;

}

//加糖要多加0.5元,并运动到相应的位置
void AddMaterial::AddSugar(double & p)	//p为咖啡的初始价格
{
	//添加运动到相应工位的代码

	p = p + 0.5;

}

//加牛奶要多加0.8元,并运动到相应的位置
void AddMaterial::AddMilk(double & p)	//p为咖啡的初始价格
{
	//添加运动到相应工位的代码

	p = p + 0.8;
	
}

//找零钱，第一个参数是投入的金额，第二个参数是咖啡总价格
double  AddMaterial::GetExchange(double & inMoney, double & p)
{
	return (inMoney - p);
}
