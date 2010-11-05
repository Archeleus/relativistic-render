#include "Magick++.h"

class polar3D{
	float pRad;
	float pRadv;
	float minX,minY,maxX,maxY;
public:
	Magick::Image backImage;
	polar3D();
	~polar3D();
	void getRGB(float x,float y,float z,float* rgb);
	float getTheta(float x,float y,float z);
	float getPhi(float x,float z);
	float InvSqrt(float a);
	

};

extern polar3D pImage;