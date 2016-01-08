#include<iostream>
#include"Caffee.h"

using namespace std;

int main()
{
	Caffee CappuccinoL("Cappuccino","large");
	double ini = CappuccinoL.getPrice();
	cout << "只加咖啡时的价格" << ini <<endl;
	CappuccinoL.addMilk();
	ini = CappuccinoL.getPrice();
	cout << "加牛奶之后的价格" << ini << endl;
	CappuccinoL.addCastorSugar();
	ini = CappuccinoL.getPrice();
	cout << "加牛奶和白沙糖之后的价格" << ini << endl;

	Caffee CappuccinoS("Cappuccino", "small");
	double ini2 = CappuccinoS.getPrice();
	cout << "只加咖啡时的价格" << ini2 << endl;
	CappuccinoS.addCheese();
	ini2 = CappuccinoS.getPrice();
	cout << "加奶酪之后的价格" << ini2 << endl;
	CappuccinoS.addCubicSugar();
	ini2 = CappuccinoS.getPrice();
	cout << "加牛奶和白沙糖之后的价格" << ini2 << endl;

	system("pause");
	return 0;

}
