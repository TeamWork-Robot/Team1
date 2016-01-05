
#include "Solver.h"
class Robot{
	private:
		double arm1;
		double arm2;
		double arm1Range;
		double arm2Range;
	public:
		Robot();
		Robot(double a,double b);
		void PTPmove(Frame fr,Point po);
};
