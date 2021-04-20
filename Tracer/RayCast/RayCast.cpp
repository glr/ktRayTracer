/*
 *  RayCast.cpp
 *  ktRayTracer
 */

#include "RayCast.h"


#pragma mark RayCast

RayCast::RayCast(void) : Tracer() {
	
}

RayCast::RayCast(World *world) : Tracer(world) {
	
}

RayCast::~RayCast(void) {
	
}


#pragma mark -
#pragma mark Trace Functions

vec3f RayCast::trace(const Ray& ray) const {
	HitData hd(world->hitObjects(ray));
	
	if (hd.getHit()) {
		hd.setRay(ray);
		return (hd.getMaterial()->shade(hd));
	}   
	else
		return vec3f(0, 0, 0);
}

vec3f RayCast::trace(const Ray ray, const int depth) const {
	HitData hd(world->hitObjects(ray));
	
	if (hd.getHit()) {
		hd.setRay(ray);
		return (hd.getMaterial()->shade(hd));
	}   
	else
		return vec3f(0, 0, 0);
}