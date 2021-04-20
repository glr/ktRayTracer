/*
 *  Transparent.cpp
 *  ktRayTracer
 */

#include "Transparent.h"
#include "World.h"
#include "Tracer.h"


#pragma mark Transparent

Transparent::Transparent(void) : Phong(), reflection(new PerfectSpecular()), transparency(new PerfectTransmitter()) {
	
}

Transparent::Transparent(float ka, float kd, const vec3f& cd, float ks, const vec3f& cs, float ps, float kr, const vec3f& cr, float kt, float ior)
: Phong(ka, kd, cd, ks, cs, ps), reflection(new PerfectSpecular(kr, cr)), transparency(new PerfectTransmitter(kt, ior)) {
	
}


Transparent::Transparent(float ka, float kd, float rd, float gd, float bd, float ks, float rs, float gs, float bs, float ps, 
					   float kr, float rr, float gr, float br, float kt, float ior)
: Phong(ka, kd, rd, gd, bd, ks, rs, gs, bs, ps), reflection(new PerfectSpecular(kr, rr, gr, br)), transparency(new PerfectTransmitter(kt, ior)) {
	
}

Transparent::~Transparent(void) {
	
}


#pragma mark -
#pragma mark Info

void Transparent::showInfo(void) const {
	cout << "*** Transparent Material ***" << endl;
	cout << "Reflective BRDF" << endl;
	reflection->showInfo();
	cout << "Transparent BTDF" << endl;
	transparency->showInfo();
	Phong::showInfo();
}


#pragma mark -
#pragma mark Reflection

void Transparent::setKr(float kr) {
	reflection->setKr(kr);
}

float Transparent::getKr(void) {
	return reflection->getKr();
}

void Transparent::setCr(const vec3f& cr) {
	reflection->setCr(cr);
}

void Transparent::setCr(float r, float g, float b) {
	reflection->setCr(r, g, b);
}

vec3f Transparent::getCr(void) {
	return reflection->getCr();
}


#pragma mark -
#pragma mark Transparency

void Transparent::setKt(float kt) {
	transparency->setKt(kt);
}

float Transparent::getKt(void) {
	return transparency->getKt();
}

void Transparent::setIor(float ior) {
	transparency->setIor(ior);
}

float Transparent::getIor(void) {
	return transparency->getIor();
}


#pragma mark -
#pragma mark Shade

vec3f Transparent::shade(HitData& hd) {
	vec3f L(Phong::shade(hd));
	
	vec3f wo = -hd.getRay().getDirection();
	vec3f wi;
	
	vec3f fr = reflection->sample_f(hd, wo, wi);
	Ray refRay(hd.getHitPoint(), wi);

	World w = hd.getWorld();
	if (transparency->tir(hd)) {
		L += w.getTracer()->trace(refRay, hd.getDepth() + 1);
	} else {
		vec3f wt;
		vec3f ft = transparency->sample_f(hd, wo, wt);
		Ray transRay(hd.getHitPoint(), wt);
		
		L += fr * w.getTracer()->trace(refRay, hd.getDepth() + 1) * fabs(hd.getNormal().dot(wi));
		L += ft * w.getTracer()->trace(transRay, hd.getDepth() + 1) * fabs(hd.getNormal().dot(wt));
	}

	return L;
}