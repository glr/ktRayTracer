/*
 *  Whitted.cpp
 *  ktRayTracer
 */

#include "Whitted.h"


#pragma mark Whitted

Whitted::Whitted(void) : Tracer() {
	
}

Whitted::Whitted(World* world) : Tracer(world) {
	
}

Whitted::~Whitted(void) {
	
}


#pragma mark -
#pragma mark Trace

vec3f Whitted::trace(const Ray& ray) const {
	HitData hd(world->hitObjects(ray));
	
	if (hd.getHit()) {
		hd.setRay(ray);
		return (hd.getMaterial()->shade(hd));
	}   
	else
		return vec3f(0.0, 0.0, 0.0);
}

vec3f Whitted::trace(const Ray ray, const int depth) const {
	// TODO:  This should come from camera/view plane, not hard coded
	if (depth > 10) {
		return vec3f(0.0, 0.0, 0.0);
	} else {
		HitData hd(world->hitObjects(ray));
		
		if (hd.getHit()) {
			hd.setDepth(depth);
			hd.setRay(ray);
			
			return (hd.getMaterial()->shade(hd));
		}   
		else
			return vec3f(0.0, 0.0, 0.0);
	}
}

vec3f Whitted::trace(const Ray ray, float& tmin, const int depth) const {
	// TODO:  This should come from camera/view plane/world, not hard coded
	if (depth > 5) {
		return vec3f(0.0, 0.0, 0.0);
	} else {
		HitData hd(world->hitObjects(ray));
		
		if (hd.getHit()) {
			hd.setDepth(depth);
			hd.setRay(ray);
			tmin = hd.getT();
			
			return (hd.getMaterial()->shade(hd));
		}   
		else {
			tmin = 1000000.0;
			return vec3f(0.0, 0.0, 0.0);
		}
	}
}