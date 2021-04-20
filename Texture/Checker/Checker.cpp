/*
 *  Checker.cpp
 *  ktRayTracer
 */

#include "Checker.h"


#pragma mark Checker

Checker::Checker(void) : Texture(), size(1), colorA(vec3f(.2, .2, .2)), colorB(vec3f(1, 1, 1)) {
	
}

Checker::Checker(float size, const vec3f& colorA, const vec3f& colorB) 
: Texture(), size(size), colorA(colorA), colorB(colorB) {
	
}

Checker::Checker(float size, float ra, float ga, float ba, float rb, float gb, float bb) 
: Texture(), size(size), colorA(vec3f(ra, ga, ba)), colorB(vec3f(rb, gb, bb)) {

}

Checker::~Checker(void) {
	
}


#pragma mark -
#pragma mark Info

void Checker::showInfo(void) const {
	cout << "*** Checker Texture ***" << endl;
	cout << "Size:  " << size << endl;
	cout << "Colar A:  " << colorA << endl;
	cout << "Color B:  " << colorB << endl;
}


#pragma mark -
#pragma mark Color

vec3f Checker::getColor(const HitData& hd) const {
	float x = hd.getHitPoint()[0];
	float y = hd.getHitPoint()[1];
	int ix = floor(x / size);
	int iy = floor(y / size);
	
	if ((ix + iy) % 2 == 0) {
		return colorA;
	} else {
		return colorB;
	}
}