
#include "Robot.h"
using namespace std;
		Robot::Robot(){}
		Robot::Robot(double a,double b){
			arm1=a;
			arm2=b;
		}
		void Robot::PTPmove(Frame fr,Point po){
			Solver solver;
			Point point;
			
			point=solver.FrameStandardize(fr,po);
			solver.FrameToJoint(point,arm1,arm2);
				
		}

