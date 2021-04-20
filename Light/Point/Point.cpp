/*
 *  Point.cpp
 *  ktRayTracer
 */

#include "Point.h"
#include "World.h"


#pragma mark Point

Point::Point(void) : Light(), ls(1), location(vec3f(0, 0, 1)), color(vec3f(1, 1, 1)) {
	
}

Point::Point(float ls, const vec3f& location, const vec3f& color) : Light(), ls(ls), location(location), color(color) {
	
}

Point::Point(float ls, float x, float y, float z, const vec3f& color) : Light(), ls(ls), location(vec3f(x, y, z)), color(color) {
	
}

Point::Point(float ls, const vec3f& location, float r, float g, float b) : Light(), ls(ls), location(location), color(vec3f(r, g, b)) {
	
}

Point::Point(float ls, float x, float y, float z, float r, float g, float b) : Light(), ls(ls), location(vec3f(x, y, z)), color(vec3f(r, g, b)) {
	
}

Point::~Point(void) {
	
}


#pragma mark -
#pragma mark Info

void Point::showInfo(void) const {
	cout << "*** Point Light ***" << endl;
	cout << "ls:  " << ls << endl;
	cout << "Location:  " << location << endl;
	cout << "Color:  " << color << endl;
}


#pragma mark -
#pragma mark Location

void Point::setLocation(const vec3f& location) {
	this->location = location;
}

void Point::setLocation(float x, float y, float z) {
	location = vec3f(x, y, z);
}

vec3f Point::getLocation(void) {
	return location;
}


#pragma mark -
#pragma mark Color

void Point::setColor(const vec3f& color) {
	this->color = color;
}

void Point::setColor(float r, float g, float b) {
	color = vec3f(r, g, b);
}

vec3f Point::getColor(void) {
	return color;
}


#pragma mark -
#pragma mark Ray Direction

vec3f Point::getDirection(HitData& hd) {
	vec3f d = location - hd.getHitPoint();
	d.normalize();
	return d;
}


#pragma mark -
#pragma mark Shadow

bool Point::shadow(const Ray& ray, const HitData& hd) const {
	float t;
	
	// uncomment to disable shadows
	//return false;
	
	World w = hd.getWorld();
	unsigned int count = w.getGeometry().size();
	float dist = (location - ray.getOrigin()).norm();
	
	for (unsigned int i = 0; i < count; i++) {
		if (w.getGeometry()[i]->shadowHit(ray, t) && (t < dist)) {
			return true;
		}
	}
	return false;
}


#pragma mark -
#pragma mark Radiance

void Point::setLs(float ls) {
	this->ls = ls;
}

float Point::getLs(void) {
	return ls;
}

vec3f Point::L(HitData& hd) {
	return ls * color;
}