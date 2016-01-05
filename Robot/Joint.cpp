#include "Joint.h"
using namespace std;
		Joint::Joint(){}
		Joint::Joint(int a,int b){
			deg1=a;
			deg2=b;
		}
		void Joint::setDeg1(double rad){
			deg1=rad*180/PI;
		}
		void Joint::setDeg2(double rad){
			deg2=rad*180/PI;
		}
		double Joint::getDeg1(){
			return deg1;
		}
		double Joint::getDeg2(){
			return deg2;
		}
		

