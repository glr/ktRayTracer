/*
 *  Matte.cpp
 *  ktRayTracer
 */

#include "Matte.h"
#include "World.h"
#include "Light.h"

#pragma mark Matte

Matte::Matte(void) : Material(), ambient(new Lambert()), diffuse(new Lambert()) {
	
}

Matte::Matte(float ka, float kd, const vec3f& cd) : Material(), ambient(new Lambert(ka, cd)), diffuse(new Lambert(kd, cd)) {
	
}

Matte::Matte(float ka, float kd, float r, float g, float b) : Material(), ambient(new Lambert(ka, r, g, b)), diffuse(new Lambert(kd, r, g, b)) {
	
}

Matte::~Matte(void) {
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

void Matte::showInfo(void) const {
	cout << "*** Matte Material ***" << endl;
	cout << "Ambient BRDF" << endl;
	ambient->showInfo();
	cout << "Diffuse BRDF" << endl;
	diffuse->showInfo();
	cout << endl;
}


#pragma mark -
#pragma mark  Ambient

void Matte::setKa(float ka) {
	ambient->setKd(ka);
}

float Matte::getKa(void) {
	return ambient->getKd();
}

#pragma mark -
#pragma mark Diffuse

void Matte::setKd(float kd) {
	diffuse->setKd(kd);
}

float Matte::getKd(void) {
	return diffuse->getKd();
}

void Matte::setCd(const vec3f& cd) {
	ambient->setCd(cd);
	diffuse->setCd(cd);
}

void Matte::setCd(float r, float g, float b) {
	ambient->setCd(r, g, b);
	diffuse->setCd(r, g, b);
}

vec3f Matte::getCd(void) {
	return diffuse->getCd();
}


#pragma mark -
#pragma mark Shade

vec3f Matte::shade(HitData& hd) {
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
				L += diffuse->f(hd, wo, wi) * (l[i]->L(hd)) * ndotwi;
		}
	}
	
	return L;
}