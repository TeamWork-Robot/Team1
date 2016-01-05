#include "Point.h"

class Frame{
	private:
		Point origin;
		double degree;
	public:
		Frame();
	 	Frame(Point orig,double deg);
		Point getPoint();
		double getDegree();
		
};
