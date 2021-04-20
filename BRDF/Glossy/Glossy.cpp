/*
 *  Glossy.cpp
 *  ktRayTracer
 */

#include "Glossy.h"
#include "HitData.h"


#pragma mark Glossy

Glossy::Glossy(void) : BRDF(), ks(1), cs(vec3f(1, 1, 1)), ps(1) {
	
}

Glossy::Glossy(float ks, const vec3f& cs, float ps) : BRDF(), ks(ks), cs(cs), ps(ps) {
	
}

Glossy::Glossy(float ks, float r, float g, float b, float ps) : BRDF(), ks(ks), cs(vec3f(r, g, b)), ps(ps) {
	
}

Glossy::~Glossy(void) {
	
}


#pragma mark -
#pragma mark Info

void Glossy::showInfo(void) const {
	cout << "*** Glossy BRDF ***" << endl;
	cout << "k specular:  " << ks << endl;
	cout << "specular power:  " << ps << endl;
	cout << "color specular:  " << cs << endl<< endl;
}


#pragma mark -
#pragma mark f

vec3f Glossy::f(const HitData& hd, const vec3f& wo, const vec3f& wi) const {
	float ndotwi = hd.getNormal().dot(wi);
	
	vec3f norm = hd.getNormal();
	
	vec3f r = -wi + norm * 2 * ndotwi;
	
	float rdotwo = r.dot(wo);
	
	vec3f retval(0, 0, 0);
	if (rdotwo > 0) {
		retval = vec3f(powf(rdotwo, ps) * ks);
	}
	
	return retval;
}


#pragma mark -
#pragma mark Rho

vec3f Glossy::rho(const HitData& hd, const vec3f& wo) const {
	return vec3f(0, 0, 0);
}


#pragma mark -
#pragma mark Specular

void Glossy::setKs(float ks) {
	this->ks = ks;
}

float Glossy::getKs(void) {
	return ks;
}

void Glossy::setPs(float ps) {
	this->ps = ps;
}

float Glossy::getPs(void) {
	return ps;
}

void Glossy::setCs(const vec3f& cs) {
	this->cs = cs;
}

void Glossy::setCs(float r, float g, float b) {
	cs = vec3f(r, g, b);
}

vec3f Glossy::getCs(void) {
	return cs;
}
