/*
 *  PerfectSpecular.cpp
 *  ktRayTracer
 */

#include "PerfectSpecular.h"
#include "HitData.h"


#pragma mark PerfectSpecular

PerfectSpecular::PerfectSpecular(void) : BRDF(), kr(1), cr(vec3f(0, 0, 0)) {
	
}

PerfectSpecular::PerfectSpecular(float kr, const vec3f& cr) : BRDF(), kr(kr), cr(cr) {
	
}

PerfectSpecular::PerfectSpecular(float kr, float r, float g, float b) : BRDF(), kr(kr), cr(vec3f(r, g, b)) {
	
}

PerfectSpecular::~PerfectSpecular(void) {
	
}


#pragma mark -
#pragma mark Info

void PerfectSpecular::showInfo(void) const {
	cout << "*** PerfectSpecular BRDF ***" << endl;
	cout << "k reflection:  " << kr << endl;
	cout << "color reflection:  " << cr << endl<< endl;
}


#pragma mark -
#pragma mark f

vec3f PerfectSpecular::sample_f(const HitData& hd, const vec3f& wo, vec3f& wi) const {
	float ndotwo = hd.getNormal().dot(wo);
	wi = -wo + hd.getNormal() * ndotwo * 2.0;
	
	return (kr * cr / (hd.getNormal().dot(wi)));
}


#pragma mark -
#pragma mark Reflection

void PerfectSpecular::setKr(float kr) {
	this->kr = kr;
}

float PerfectSpecular::getKr(void) {
	return kr;
}

void PerfectSpecular::setCr(const vec3f& cr) {
	this->cr = cr;
}

void PerfectSpecular::setCr(float r, float g, float b) {
	cr = vec3f(r, g, b);
}

vec3f PerfectSpecular::getCr(void) {
	return cr;
}
