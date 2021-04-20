/*
 *  Simple.cpp
 *  ktRayTracer
 *
 *  Created by Gabriel on 2/28/10.
 *  Copyright 2010 krahSTek, LLC. All rights reserved.
 *
 */

#include "Simple.h"


#pragma mark Simple

Simple::Simple(void) : color(vec3f(0, 0, 0)) {
	
}

Simple::Simple(const vec3f& color) : color(color) {
	
}

Simple::Simple(float r, float g, float b) : color(vec3f(r, g, b)) {
	
}

Simple::~Simple(void) {
	
}


#pragma mark -
#pragma mark Info

void Simple::showInfo(void) const {
	cout << "*** Simple Material ***" << endl;
	cout << "Color:  " << color << endl << endl;
}


#pragma mark -
#pragma mark Color

void Simple::setColor(const vec3f& color) {
	this->color = color;
}

void Simple::setColor(float r, float g, float b) {
	color = vec3f(r, g, b);
}

vec3f Simple::getColor(void) {
	return color;
}


#pragma mark -
#pragma mark Shade

vec3f Simple::shade(HitData& hd) {
	return color;
}
