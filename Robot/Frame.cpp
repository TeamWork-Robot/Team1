#include "Frame.h"
using namespace std;
		Frame::Frame(){}
	 	Frame::Frame(Point orig,double deg){
		 	origin=orig;
		 	degree=deg;
		 }
		Point Frame::getPoint(){
			return origin;
		}
		double Frame::getDegree(){
			return degree;
		}
		

