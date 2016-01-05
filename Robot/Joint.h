#define PI 3.1415926
class Joint{
	private:
		double deg1;
		double deg2;
	public: 
		Joint();
		Joint(int a,int b);
		void setDeg1(double rad);
		void setDeg2(double rad);
		double getDeg1();
		double getDeg2();
		
};
