/*
 *  Material.cpp
 *  ktRayTracer
 */

#include "Material.h"


#pragma mark Material

Material::Material(void) {
	
}


#pragma mark -
#pragma mark Shade

vec3f Material::shade(HitData& hd) {
	return vec3f(0, 0, 0);
}
