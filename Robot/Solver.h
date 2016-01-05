#include "Joint.h"
#include "Frame.h"
class Solver{
	private:
		Joint joint;
		Frame frame;
	public:
		Point move(Point p1,Point p2);
		
		Point rotate(Point p,double deg);
		
		//将用户坐标系转化为世界坐标系 
		Point FrameStandardize(Frame fr,Point po);
		
		//在世界坐标系下反算关节坐标 
		FrameToJoint(Point po,double arm1,double arm2);
					
				//将世界坐标系下的关节坐标还原为用户坐标系 
		FrameReturn(Frame fr);
		JointToFrame(Point po);
		
};
