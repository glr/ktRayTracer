/*
 *  BTDF.cpp
 *  ktRayTracer
 */

#include "BTDF.h"


#pragma mark BTDF

BTDF::BTDF(void) {
	
}

BTDF::~BTDF(void) {
	
}


#pragma mark -
#pragma mark f

vec3f BTDF::f(const HitData& hd, const vec3f& wo, const vec3f& wt) const {
	return vec3f(0, 0, 0);
}

vec3f BTDF::sample_f(const HitData& hd, const vec3f& wo, vec3f& wt) const {
	return vec3f(0, 0, 0);
}


#pragma mark -
#pragma mark Rho

vec3f BTDF::rho(const HitData& hd, const vec3f& wo) const {
	return vec3f(0, 0, 0);
}
