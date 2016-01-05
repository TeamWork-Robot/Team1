#ifndef ADDMATERIAL
#define ADDMATERIAL

class AddMaterial
{
public:
	AddMaterial(){};
	void  AddCappuccino(double &);		//卡布奇诺
	void  AddLatte(double &);		//拿铁咖啡
	void  AddMocha(double &);		//摩卡咖啡
	void  AddSugar(double &);		//咖啡加糖，返回价格
	void  AddMilk(double &);		//咖啡加牛奶，返回价格
	double  GetExchange(double &,double &);	//找零钱
};


#endif ADDMATERIAL
