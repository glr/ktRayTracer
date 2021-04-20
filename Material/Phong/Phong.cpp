/*
 *  Phong.cpp
 *  ktRayTracer
 */

#include "Phong.h"
#include "World.h"
#include "Light.h"

#pragma mark Phong

Phong::Phong(void) : Material(), ambient(new Lambert()), diffuse(new Lambert()), specular(new Glossy()) {
	
}

Phong::Phong(float ka, float kd, const vec3f& cd, float ks, const vec3f& cs, float ps) 
: Material(), ambient(new Lambert(ka, cd)), diffuse(new Lambert(kd, cd)), specular(new Glossy(ks, cs, ps)) {
	
}

Phong::Phong(float ka, float kd, float rd, float gd, float bd, float ks, float rs, float gs, float bs, float ps) 
: Material(), ambient(new Lambert(ka, rd, gd, bd)), diffuse(new Lambert(kd, rd, gd, bd)), specular(new Glossy(ks, rs, gs, bs, ps)) {
	
}

Phong::~Phong(void) {
	if (ambient) {
		delete ambient;
		ambient = NULL;
	}
	
	if (diffuse) {
		delete diffuse;
		diffuse = NULL;
	}
}

#pragma mark -
#pragma mark Info

void Phong::showInfo(void) const {
	cout << "*** Phong Material ***" << endl;
	cout << "Ambient BRDF" << endl;
	ambient->showInfo();
	cout << "Diffuse BRDF" << endl;
	diffuse->showInfo();
	cout << "Specular BRDF" << endl;
	specular->showInfo();
	cout << endl;
}


#pragma mark -
#pragma mark  Ambient

void Phong::setKa(float ka) {
	ambient->setKd(ka);
}

float Phong::getKa(void) {
	return ambient->getKd();
}

#pragma mark -
#pragma mark Diffuse

void Phong::setKd(float kd) {
	diffuse->setKd(kd);
}

float Phong::getKd(void) {
	return diffuse->getKd();
}

void Phong::setCd(const vec3f& cd) {
	ambient->setCd(cd);
	diffuse->setCd(cd);
}

void Phong::setCd(float r, float g, float b) {
	ambient->setCd(r, g, b);
	diffuse->setCd(r, g, b);
}

vec3f Phong::getCd(void) {
	return diffuse->getCd();
}


#pragma mark -
#pragma mark Specular

void Phong::setKs(float ks) {
	specular->setKs(ks);
}

float Phong::getKs(void) {
	return specular->getKs();
}


void Phong::setPs(float ps) {
	specular->setPs(ps);
}

float Phong::getPs(void) {
	return specular->getPs();
}	
	
void Phong::setCs(const vec3f& cs) {
	specular->setCs(cs);
}

void Phong::setCs(float r, float g, float b) {
	specular->setCs(r, g, b);
}

vec3f Phong::getCs(void) {
	return specular->getCs();
}


#pragma mark -
#pragma mark Shade

vec3f Phong::shade(HitData& hd) {
	World w = hd.getWorld();
	vec3f wo = -(hd.getRay().getDirection());
	
	vec3f L	= ambient->rho(hd, wo) * w.getAmbient()->L(hd);
	
	vector <Light *>l = w.getLights();
	unsigned int numLights = l.size();
	
	for (unsigned int i = 0; i < numLights; i++) {
		vec3f wi = l[i]->getDirection(hd);
		float ndotwi = hd.getNormal().dot(wi);
		
		if (ndotwi > 0.0) {
			bool shadow = false;
			
			Ray sray(hd.getHitPoint(), wi);
			shadow = l[i]->shadow(sray, hd);
			
			if (!shadow) 
				L += (diffuse->f(hd, wo, wi) + specular->f(hd, wo, wi)) * (l[i]->L(hd)) * ndotwi;
		}
	}
	
	return L;
}
