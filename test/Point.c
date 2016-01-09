#include "Point.h"
using namespace std;
		Point::Point(){}
		Point::Point(double a,double b){
			x=a;
			y=b;
		}
		double Point::getX(){
			return x;
		}
		double Point::getY(){
			return y;
		}
		void Point::setX(double a){
			x=a;
		}
		void Point::setY(double b){
			y=b;
		}
		

