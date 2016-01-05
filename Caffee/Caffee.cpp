#include"Caffee.h"
#include<iostream>
using namespace std;

Caffee::Caffee(string name)
{
	caffeeName = name;
	price = 0.0;

	if (caffeeName == "Cappuccino")		//卡布奇诺
		 add.AddCappuccino(price);

	if (caffeeName == "Latte")		//拿铁
		 add.AddCappuccino(price);

	if (caffeeName == "Mocha")		//摩卡
		 add.AddCappuccino(price);

}

//咖啡加糖，返回价钱
void Caffee::addSugar()
{
	return add.AddSugar(price);
}

//咖啡加牛奶，返回价格
void Caffee::addMilk()
{
	return add.AddMilk(price);
}

//获取咖啡的价格
double Caffee::getPrice()
{
	return price;
}

//找零钱
double Caffee::getExchane(double inMoney)
{
	if (inMoney < price)
	{
		cout << "请投入足够的钱！";
		return 0;
	}
	else

		return add.GetExchange(inMoney, price);

}
