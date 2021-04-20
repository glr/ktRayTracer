/*
 *  Ray.cpp
 *  ktRayTracer
 */

#include "Ray.h"


#pragma mark Ray

Ray::Ray(void) : origin(vec3f(0, 0, 0)), direction(vec3f(0, 1, 0)) {
	direction.normalize();
}

Ray::Ray(const vec3f& origin, const vec3f direction) : origin(origin), direction(direction) {
	this->direction.normalize();
}

Ray::Ray(float x, float y, float z, vec3f direction) : origin(vec3f(x, y, z)), direction(direction) {
	direction.normalize();
}

Ray::Ray(const vec3f& origin, float u, float v, float w) : origin(origin), direction(vec3f(u, v, w)) {
	direction.normalize();	
}

Ray::Ray(float x, float y, float z, float u, float v, float w) : origin(vec3f(x, y, z)), direction(vec3f(u, v, w)) {
	direction.normalize();	
}

Ray::~Ray(void) {
	
}


#pragma mark -
#pragma mark Origin

void Ray::setOrigin(const vec3f& origin) {
	this->origin = origin;
}

void Ray::setOrigin(float x, float y, float z) {
	origin = vec3f(x, y, z);
}

vec3f Ray::getOrigin(void) const {
	return origin;
}


#pragma mark -
#pragma mark Direction

void Ray::setDirection(const vec3f& direction) {
	this->direction = direction;
}

void Ray::setDirection(float u, float v, float w) {
	direction = vec3f(u, v, w);
	direction.normalize();
}

vec3f Ray::getDirection(void) const {
	return direction;
}


#pragma mark -
#pragma mark Point

vec3f Ray::getPoint(float t) const{
	return origin + t * direction;
}
