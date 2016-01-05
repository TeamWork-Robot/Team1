#include <iostream>
#include <math.h>
#include "Robot.h"


#define PI 3.1415926
using namespace std;
	
int main(){
	Robot myRobot(4,3);   //定义机器人的关节长度 
	
	Point origin(0,0);
	Point origin1(2,3);
	Point origin2(6,1);
	Point origin3(5,9);   //设置一组坐标系原点在世界坐标系中的坐标值 
	
	Point point1(-5,1);
	Point point2(-3,-1);
	Point point3(4,2);
	Point point4(3,7);   // 设置每个坐标系中机器人运动目标坐标点 
	
	Frame WF(origin,0);
	Frame TF1(origin1,30);
	Frame TF2(origin2,60);
	Frame TF3(origin3,90);  //建立世界坐标系与用户坐标系 
	
	
	myRobot.PTPmove(WF,point1);
	myRobot.PTPmove(TF1,point2);
	myRobot.PTPmove(TF2,point3);
	myRobot.PTPmove(TF3,point4);
	
	
	return 0;
}
