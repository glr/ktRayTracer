/*
 *  BoundBox.cpp
 *  ktRayTracer
 */

#include "BoundBox.h"
#include "Ray.h"


const float BoundBox::kEpsilon = 0.00001;


#pragma mark BoundBox

BoundBox::BoundBox(void) : BoundVolume(), p0(vec3f(-0.5, -0.5, -0.5)), p1(vec3f(0.5, 0.5, 0.5)) {
	setCenter();
}

BoundBox::BoundBox(const vec3f& p0, const vec3f& p1) : BoundVolume(), p0(p0), p1(p1) {
	setCenter();	
}

BoundBox::BoundBox(float x0, float y0, float z0, float x1, float y1, float z1) : BoundVolume(), p0(vec3f(x0, y0, z0)), p1(vec3f(x1, y1, z1)) {
	setCenter();
}

BoundBox::BoundBox(const BoundBox& b0, const BoundBox& b1) : BoundVolume() {
	p0 = b0.p0;
	p0 = vs_min(p0, b1.p0);
	
	p1 = b0.p1;
	p1 = vs_max(p1, b1.p1);
	setCenter();
}

BoundBox::~BoundBox(void) {
	
}


#pragma mark -
#pragma mark Info

void BoundBox::showInfo(void) const {
	BoundVolume::showInfo();
	cout << "*** Bounding Box ***" << endl;
	cout << "p0:  " << p0 << endl;
	cout << "p1:  " << p1 << endl;
	cout << "center:  " << center << endl;
}


#pragma mark -
#pragma mark Hit

bool BoundBox::hit(const Ray& ray) const {
	
	vec3f d = ray.getDirection();
	vec3f di(1.0 / d[0], 1.0 / d[1], 1.0 / d[2]);
	vec3f o = ray.getOrigin();
	
	vec3f tMin, tMax;
	
	// x
	if (di[0] >= 0) {
		tMin[0] = (p0[0] - o[0]) * di[0];
		tMax[0] = (p1[0] - o[0]) * di[0];
	} else {
		tMin[0] = (p1[0] - o[0]) * di[0];
		tMax[0] = (p0[0] - o[0]) * di[0];
	}

	// y
	if (di[1] >= 0) {
		tMin[1] = (p0[1] - o[1]) * di[1];
		tMax[1] = (p1[1] - o[1]) * di[1];
	} else {
		tMin[1] = (p1[1] - o[1]) * di[1];
		tMax[1] = (p0[1] - o[1]) * di[1];
	}
	
	// z
	if (di[2] >= 0) {
		tMin[2] = (p0[2] - o[2]) * di[2];
		tMax[2] = (p1[2] - o[2]) * di[2];
	} else {
		tMin[2] = (p1[2] - o[2]) * di[2];
		tMax[2] = (p0[2] - o[2]) * di[2];
	}
	
	float t0, t1;
	
	t0 = (tMin[0] > tMin[1])?tMin[0]:tMin[1];
	t0 = (tMin[2] > t0)?tMin[2]:t0;
	
	t1 = (tMax[0] < tMax[1])?tMax[0]:tMax[1];
	t1 = (tMax[2] < t0)?tMax[2]:t1;
	
	return (t0 < t1 && t1 > kEpsilon);
}


#pragma mark -
#pragma mark Points

void BoundBox::setP0(const vec3f& p0) {
	this->p0 = p0;
	setCenter();
}

void BoundBox::setP0(float x, float y, float z) {
	p0 = vec3f(x, y, z);
	setCenter();
}

vec3f BoundBox::getP0(void) {
	return p0;
}

void BoundBox::setP1(const vec3f& p1) {
	this->p1 = p1;
	setCenter();
}

void BoundBox::setP1(float x, float y, float z) {
	p1 = vec3f(x, y, z);
	setCenter();
}

vec3f BoundBox::getP1(void) {
	return p1;
}

vec3f BoundBox::getCenter(void) {
	return center;
}
