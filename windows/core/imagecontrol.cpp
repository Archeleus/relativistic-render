#include "stdafx.h"
#include <cmath>
#define PI 3.14159265358979323846264338328
using namespace Magick;

polar3D::polar3D(){
	backImage.read("bg.jpg");
	//scale backImage width to be height*2;
	pRad = backImage.baseRows()/PI;
	pRadv = backImage.baseColumns()/(2*PI);

	
}

void polar3D::getRGB(float x,float y,float z, float *rgb){
	float theta = getTheta(x,y,z);
	float phi = getPhi(x,z);
	float bX,bY;
	//printf("(1,1,1) Theta = %.2f Phi = %.2f",getTheta(1,1,1)*180/PI,getPhi(1,1)*180/PI);
	bY = pRad*theta;
	bX = pRadv*phi;
	//backImage.pixelColor(bX,bY,Color(0,0,0));
	Magick::ColorRGB bCol = backImage.pixelColor(bX,bY);
	*rgb = bCol.red();
	*(rgb+1) = bCol.green();
	*(rgb+2) = bCol.blue();
	


}

polar3D::~polar3D(){
}

float polar3D::InvSqrt(float a){
	union {
		float f;
		int i;
	} tmp;
	tmp.f = a;
	tmp.i = 0x5f3759df - (tmp.i >> 1);
	float y = tmp.f;
	return y * (1.5f - 0.5f * a * y * y);
}

float polar3D::getTheta(float x, float y, float z){
	float bb = x*x+z*z;
	float cos_theta = bb/sqrt((bb+y*y)*(bb));
	float theta = acos(cos_theta);
	if(y>0){theta = 0.5*PI-theta;}
	else if(y<0){theta += 0.5*PI;}
	else{theta=0.5*PI;}
	return theta;
}

float polar3D::getPhi(float x,float z){
	//make sure to account for cases when x = 0;
	if(x==0){
		if(z>0){
			return 0.5*PI;
		}else if(z<0){
			return 0.75*PI;
		}else{return 0;}
	}else if(x>0){
		if(z>0){
			return atan(z/x);
		}else if(z<0){
			return 2*PI + atan(z/x);
		}else{return 0;}
	}else if(x<0){
		if(z>0){
			return PI + atan(z/x);
		}else if(z<0){
			return PI + atan(z/x);
		}else{return 0;}
	}
	return 0;
}

