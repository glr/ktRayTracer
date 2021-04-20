/*
 *  FresnelReflector.cpp
 *  ktRayTracer
 */

#include "FresnelReflector.h"
#include "HitData.h"


#pragma mark FresnelReflector

FresnelReflector::FresnelReflector(void) : BRDF(), etaIn(1), etaOut(1) {
	
}

FresnelReflector::FresnelReflector(float etaIn, float etaOut) : BRDF(), etaIn(etaIn), etaOut(etaOut) {
	
}

FresnelReflector::~FresnelReflector(void) {
	
}


#pragma mark -
#pragma mark Info

void FresnelReflector::showInfo(void) const {
	cout << "*** FresnelReflector BRDF ***" << endl;
	cout << "eta in:  " << etaIn << endl;
	cout << "eta out:  " << etaOut << endl<< endl;
}


#pragma mark -
#pragma mark f

vec3f FresnelReflector::sample_f(const HitData& hd, const vec3f& wo, vec3f& wi) const {
	float ndotwo = hd.getNormal().dot(wo);
	wi = -wo + hd.getNormal() * ndotwo * 2.0;
	
	return (vec3f(1,1,1) * fresnel(hd) / (hd.getNormal().dot(wi)));
}


#pragma mark - 
#pragma mark Fresnel

float FresnelReflector::fresnel(const HitData& hd) const {
	vec3f n = hd.getNormal();
	float ndotd = (-n).dot(hd.getRay().getDirection());
	float eta;
	
	if (ndotd < 0.0) {
		n = -n;
		eta = etaOut / etaIn;
	} else {
		eta = etaIn / etaOut;
	}
	
	float cosThetaI = (-n).dot(hd.getRay().getDirection());
	float tmp = 1.0 - (1.0 - cosThetaI * cosThetaI) / (eta * eta);
	float cosThetaT = sqrt(tmp);
	
	float rPar = (eta * cosThetaI - cosThetaT) / (eta * cosThetaI + cosThetaT);
	float rPerp = (cosThetaI - eta * cosThetaT) / (cosThetaI + eta * cosThetaT);

	return (0.5 * (rPar * rPar + rPerp * rPerp));
}

void FresnelReflector::setEtaIn(float etaIn) {
	this->etaIn = etaIn;
}

float FresnelReflector::getEtaIn(void) {
	return etaIn;
}

void FresnelReflector::setEtaOut(float etaOut) {
	this->etaOut = etaOut;
}

float FresnelReflector::getEtaOut(void) {
	return etaOut;
}
