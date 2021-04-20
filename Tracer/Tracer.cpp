/*
 *  Tracer.cpp
 *  ktRayTracer
 */

#include "Tracer.h"

#pragma mark Tracer

Tracer::Tracer(void) : world(NULL) {
	
}

Tracer::Tracer(World *world) : world(world) {
	
}

Tracer::~Tracer(void) {
	
}


#pragma mark -
#pragma mark Trace Functions

vec3f Tracer::trace(const Ray& ray) const {
	return vec3f(0, 0, 0);
}

vec3f Tracer::trace(const Ray ray, const int depth) const {
	return vec3f(0, 0, 0);
}

vec3f Tracer::trace(const Ray ray, float& tmin, const int depth) const {
	return vec3f(0, 0, 0);
}