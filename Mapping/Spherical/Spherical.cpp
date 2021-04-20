/*
 *  Spherical.cpp
 *  ktRayTracer
 */

#include <cmath>

#include "Spherical.h"


#pragma mark Spherical

Spherical::Spherical(void) : Mapping() {
	
}

Spherical::~Spherical(void) {
	
}


#pragma mark -
#pragma mark Info

void Spherical::showInfo(void) const {
	cout << "*** Spherical Mapping ***" << endl;
}


#pragma mark -
#pragma mark Texel Coordinates

void Spherical::getTexelCoords(const vec3f& hitPoint, const int wRes, const int hRes, int &x, int& y) const {
	
	float theta = atan2f(hitPoint[1], hitPoint[0]);
	float phi = acosf(hitPoint[2]);
	
	if (theta < 0) {
		theta += (2 * M_PI);
	}
	
	float u = theta / (2 * M_PI);
	float v = (M_PI - phi) / M_PI;
	
	x = (int)((wRes - 1) * u);
	y = (int)((hRes - 1) * v);
}