/*
 *  Lambert.cpp
 *  ktRayTracer
 */

#include "Lambert.h"


#pragma mark Lambert

Lambert::Lambert(void) : BRDF(), kd(1), cd(vec3f(1, 1, 1)) {
	
}

Lambert::Lambert(float kd, const vec3f& cd) : BRDF(), kd(kd), cd(cd) {
	
}

Lambert::Lambert(float kd, float r, float g, float b) : BRDF(), kd(kd), cd(vec3f(r, g, b)) {
	
}

Lambert::~Lambert(void) {
	
}


#pragma mark -
#pragma mark Info

void Lambert::showInfo(void) const {
	cout << "*** Lambert BRDF ***" << endl;
	cout << "k diffuse:  " << kd << endl;
	cout << "color diffuse:  " << cd << endl << endl;
}


#pragma mark -
#pragma mark f

vec3f Lambert::f(const HitData& hd, const vec3f& wo, const vec3f& wi) const {
	return (kd * cd) / M_PI;
}


#pragma mark -
#pragma mark Rho

vec3f Lambert::rho(const HitData& hd, const vec3f& wo) const {
	return kd * cd;
}


#pragma mark -
#pragma mark Diffuse

void Lambert::setKd(float kd) {
	this->kd = kd;
}

float Lambert::getKd(void) {
	return kd;
}

void Lambert::setCd(const vec3f& cd) {
	this->cd = cd;
}

void Lambert::setCd(float r, float g, float b) {
	cd = vec3f(r, g, b);
}

vec3f Lambert::getCd(void) {
	return cd;
}