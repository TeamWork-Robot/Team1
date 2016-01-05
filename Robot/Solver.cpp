#include <iostream>
#include "Solver.h"
#include <math.h>

#define PI 3.1415926

using namespace std;

		Point Solver::move(Point p1,Point p2){
			double tempx=p1.getX()+p2.getX();
			double tempy=p1.getY()+p2.getY();
			Point point(tempx,tempy);
			return point;
		}
		Point Solver::rotate(Point p,double deg){
			double tempx;
			double tempy;
			tempx=p.getX()*cos(PI*deg/180)-p.getY()*sin(PI*deg/180);
			tempy=p.getX()*sin(PI*deg/180)+p.getY()*cos(PI*deg/180);
            Point point(tempx,tempy);
			return point;
		}
		
		//将用户坐标系转化为世界坐标系 
		Point Solver::FrameStandardize(Frame fr,Point po){
			Point point1=rotate(po,fr.getDegree());
			Point point2=move(point1,fr.getPoint());
		    return point1;
		}
		//在世界坐标系下反算关节坐标 
		Solver::FrameToJoint(Point po,double arm1,double arm2){
			double len= sqrt(po.getX()*po.getX()+po.getY()*po.getY());
			
			if(len>=(arm1+arm2)||len<=abs(arm1-arm2)){
				cout<<"坐标超出范围，机器人无法达到"<<endl;
			}else{
				double rad1=acos((arm1*arm1+len*len-arm2*arm2)/(2*arm1*len));
				double rad2=acos((arm1*arm1+arm2*arm2-len*len)/(2*arm1*arm2));
				double rad11=atan(po.getY()/po.getX());
				double rad22=PI;
				joint.setDeg1(rad1+rad11);
				joint.setDeg2(rad2+rad22);
				cout<<"关节1应转动角度为："<<joint.getDeg1()<<" 关节2应转动角度为："<<joint.getDeg2()<<endl;
			}
					
		}
		//将世界坐标系下的关节坐标还原为用户坐标系 
		Solver::FrameReturn(Frame fr){
		}
		Solver::JointToFrame(Point po){
			
		}
		
