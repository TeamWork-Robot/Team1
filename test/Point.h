#ifndef POINT_H //如果没有定义POINT_H这个宏，则编译以下代码
#define POINT_H  //定义宏 ，避免此后重复编译
class Point{
	private:
		double x;
		double y;
	public: 
		Point();
		Point(double a,double b);
		double getX();
		double getY();
		void setX(double a);
		void setY(double b);
		
		
};
#endif
