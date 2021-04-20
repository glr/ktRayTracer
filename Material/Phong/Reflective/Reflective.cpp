/*
 *  Reflective.cpp
 *  ktRayTracer
 */

#include "Reflective.h"
#include "World.h"
#include "Tracer.h"


#pragma mark Reflective

Reflective::Reflective(void) : Phong(), reflection(new PerfectSpecular()) {
	
}

Reflective::Reflective(float ka, float kd, const vec3f& cd, float ks, const vec3f& cs, float ps, float kr, const vec3f& cr)
: Phong(ka, kd, cd, ks, cs, ps), reflection(new PerfectSpecular(kr, cr)) {
	
}


Reflective::Reflective(float ka, float kd, float rd, float gd, float bd, float ks, float rs, float gs, float bs, float ps, 
		   float kr, float rr, float gr, float br)
: Phong(ka, kd, rd, gd, bd, ks, rs, gs, bs, ps), reflection(new PerfectSpecular(kr, rr, gr, br)) {
	
}

Reflective::~Reflective(void) {
	
}


#pragma mark -
#pragma mark Info

void Reflective::showInfo(void) const {
	cout << "*** Reflective Material ***" << endl;
	cout << "Reflective BRDF" << endl;
	reflection->showInfo();
	Phong::showInfo();
}


#pragma mark -
#pragma mark Reflection

void Reflective::setKr(float kr) {
	reflection->setKr(kr);
}

float Reflective::getKr(void) {
	return reflection->getKr();
}

void Reflective::setCr(const vec3f& cr) {
	reflection->setCr(cr);
}

void Reflective::setCr(float r, float g, float b) {
	reflection->setCr(r, g, b);
}

vec3f Reflective::getCr(void) {
	return reflection->getCr();
}

vec3f Reflective::shade(HitData& hd) {
	vec3f L(Phong::shade(hd));
	
	vec3f wo = -hd.getRay().getDirection();
	vec3f wi;
	
	vec3f fr = reflection->sample_f(hd, wo, wi);
	Ray refRay(hd.getHitPoint(), wi);
	
	World w = hd.getWorld();
	L += fr * w.getTracer()->trace(refRay, hd.getDepth() + 1) * (hd.getNormal().dot(wi));
	
	return L;
}
