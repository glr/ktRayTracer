/*
 *  Ambient.cpp
 *  ktRayTracer
 */

#include "Ambient.h"


#pragma mark Ambient

Ambient::Ambient(void) : Light(), ls(1), color(vec3f(1, 1, 1)) {
	
}

Ambient::Ambient(float ls, const vec3f&color) : Light(), ls(ls), color(color) {
	
}

Ambient::Ambient(float ls, float r, float g, float b) : Light(), ls(ls), color(vec3f(r, g, b)) {
	
}

Ambient::~Ambient(void) {
	
}


#pragma mark -
#pragma mark Info

void Ambient::showInfo(void) const {
	cout << "*** Ambient Light ***" << endl;
	cout << "ls:  " << ls << endl;
	cout << "Color:  " << color << endl;
}


#pragma mark -
#pragma mark Color

void Ambient::setColor(const vec3f& color) {
	this->color = color;
}

void Ambient::setColor(const float r, const float g, const float b) {
	color = vec3f(r, g, b);
}

vec3f Ambient::getColor(void) {
	return color;
}


#pragma mark -
#pragma mark Ray Direction

vec3f Ambient::getDirection(HitData& hd) {
	return vec3f(0, 0, 0);
}


#pragma mark -
#pragma mark Shadow

bool Ambient::shadow(const Ray& ray, const HitData& hd) const {
	return false;
}

#pragma mark -
#pragma mark Radiance

void Ambient::setLs(const float ls) {
	this->ls = ls;
}

float Ambient::getLs(void) const {
	return ls;
}

vec3f Ambient::L(HitData& hd) {
	return ls * color;
}
