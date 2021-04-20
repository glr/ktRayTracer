/*
 *  BRDF.cpp
 *  ktRayTracer
 */

#include "BRDF.h"


#pragma mark BRDF

BRDF::BRDF(void) {
	
}

BRDF::~BRDF(void) {
	
}


#pragma mark -
#pragma mark f

vec3f BRDF::f(const HitData& hd, const vec3f& wo, const vec3f& wi) const {
	return vec3f(0, 0, 0);
}

vec3f BRDF::sample_f(const HitData& hd, const vec3f& wo, vec3f& wi) const {
	return vec3f(0, 0, 0);
}


#pragma mark -
#pragma mark Rho

vec3f BRDF::rho(const HitData& hd, const vec3f& wo) const {
	return vec3f(0, 0, 0);
}
