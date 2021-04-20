/*
 *  Dielectric.cpp
 *  ktRayTracer
 */

#include "Dielectric.h"
#include "World.h"
#include "Tracer.h"
#include "FresnelReflector.h"
#include "FresnelTransmitter.h"


#pragma mark Dielectric

Dielectric::Dielectric(void) : Phong(), cfIn(vec3f(1, 1, 1)), cfOut(vec3f(1, 1, 1)), reflection(new FresnelReflector()), translucency(new FresnelTransmitter()) {
	
}

Dielectric::Dielectric(float ka, float kd, const vec3f& cd, float ks, const vec3f& cs, float ps, float etaIn, float etaOut, const vec3f& cfIn, const vec3f& cfOut)
: Phong(ka, kd, cd, ks, cs, ps), cfIn(cfIn), cfOut(cfOut), reflection(new FresnelReflector(etaIn, etaOut)), translucency(new FresnelTransmitter(etaIn, etaOut)) {
	
}

Dielectric::Dielectric(float ka, float kd, float rd, float gd, float bd, float ks, float rs, float gs, float bs, float ps, 
		  float etaIn, float etaOut, float rfi, float gfi, float bfi, float rfo, float gfo, float bfo)  
: Phong(ka, kd, rd, gd, bd, ks, rs, gs, bs, ps), cfIn(vec3f(rfi, gfi, bfi)), cfOut(vec3f(rfo, gfo, bfo)), reflection(new FresnelReflector(etaIn, etaOut)), translucency(new FresnelTransmitter(etaIn, etaOut)) {
	
}

Dielectric::~Dielectric(void) {
	
}


#pragma mark -
#pragma mark Info

void Dielectric::showInfo(void) const {
	cout << "*** Dielectric Material ***" << endl;
	cout << "Fresnel BRDF" << endl;
	reflection->showInfo();
	cout << "Fresnel BTDF" << endl;
	translucency->showInfo();
	Phong::showInfo();
}


#pragma mark -
#pragma mark Fresnel

void Dielectric::setEtaIn(float etaIn) {
	translucency->setEtaIn(etaIn);
	reflection->setEtaIn(etaIn);
}

float Dielectric::getEtaIn(void) {
	return translucency->getEtaIn();
}

void Dielectric::setEtaOut(float etaOut) {
	translucency->setEtaOut(etaOut);
	reflection->setEtaOut(etaOut);
}

float Dielectric::getEtaOut(void) {
	return translucency->getEtaOut();
}

void Dielectric::setCfIn(const vec3f& cfIn) {
	this->cfIn = cfIn;
}

void Dielectric::setCfIn(float r, float g, float b) {
	cfIn = vec3f(r, g, b);
}

vec3f Dielectric::getCfIn(void) {
	return cfIn;
}

void Dielectric::setCfOut(const vec3f& cfOut) {
	this->cfOut = cfOut;
}

void Dielectric::setCfOut(float r, float g, float b) {
	cfOut = vec3f(r, g, b);
}

vec3f Dielectric::getCfOut(void) {
	return cfOut;
}


#pragma mark -
#pragma mark Shade

vec3f Dielectric::shade(HitData& hd) {
	vec3f L(Phong::shade(hd));

	vec3f wo = -hd.getRay().getDirection();
	vec3f wi;
	
	vec3f fr = reflection->sample_f(hd, wo, wi);
	Ray refRay(hd.getHitPoint(), wi);
	
	World w = hd.getWorld();
	
	float t;
	vec3f Lr, Lt;
	float ndotwi = hd.getNormal().dot(wi);
	
	if (translucency->tir(hd)) {
		Lr = w.getTracer()->trace(refRay, t, hd.getDepth() + 1);
		//Lr = w.getTracer()->trace(refRay, hd.getDepth() +1);  // for debug
		if (ndotwi < 0.0) {
			L += powc(cfIn, t) * Lr;
			//L += Lr;  // for debug
		} else {
			L += powc(cfOut, t) * Lr;
			//L += Lr; // for debug
		}
	} else {
		vec3f wt;
		vec3f ft = translucency->sample_f(hd, wo, wt);
		Ray transRay(hd.getHitPoint(), wt);
		float ndotwt = hd.getNormal().dot(wt);
		Lr = fr * w.getTracer()->trace(refRay, t, hd.getDepth() + 1) * fabs(ndotwi);
		Lt = ft * w.getTracer()->trace(transRay, t, hd.getDepth() + 1) * fabs(ndotwt);
		//Lr = fr * w.getTracer()->trace(refRay, hd.getDepth() + 1) * fabs(ndotwi); // for debug
		//Lt = ft * w.getTracer()->trace(transRay, hd.getDepth() + 1) * fabs(ndotwt); // for debug
		if (ndotwi < 0.0) {
			L += powc(cfIn, t) * Lr;
			L += powc(cfOut, t) * Lt;
			//L += Lr; // debug
			//L += Lt; // debug
		} else {
			L += powc(cfOut, t) * Lr;
			L += powc(cfIn, t) * Lt;
			L += Lr; // debug
			L += Lt; // debug
		}
	}
	return L;
}


#pragma mark -
#pragma mark Utility

vec3f Dielectric::powc(const vec3f& v, float p) {
	return vec3f(pow(v[0], p), pow(v[1], p), pow(v[2], p));
}
