/*
 *  FresnelTransmitter.cpp
 *  ktRayTracer
 */

#include "FresnelTransmitter.h"
#include "HitData.h"


#pragma mark FresnelTransmitter

FresnelTransmitter::FresnelTransmitter(void) : etaIn(1), etaOut(1) {
	
}

FresnelTransmitter::FresnelTransmitter(float etaIn, float etaOut) : etaIn(etaIn), etaOut(etaOut) {
	
}

FresnelTransmitter::~FresnelTransmitter(void) {
	
}


#pragma mark -
#pragma mark Info

void FresnelTransmitter::showInfo(void) const {
	cout << "*** FresnelTransmitter BTDF ***" << endl;
	cout << "eta in:  " << etaIn << endl;
	cout << "eta out:  " << etaOut << endl << endl;
}


#pragma mark -
#pragma mark f

vec3f FresnelTransmitter::sample_f(const HitData& hd, const vec3f& wo, vec3f& wt) const {
	vec3f n(hd.getNormal());
	float cosThetaI = n.dot(wo);
	float eta = etaIn / etaOut;
	
	if (cosThetaI < 0.0) {
		cosThetaI = -cosThetaI;
		n = -n;
		eta = 1.0 / eta;
	}
	
	float tmp = (1.0 - (1.0 - cosThetaI * cosThetaI) / (eta * eta));
	float cosTheta2 = sqrt(tmp);
	wt = -wo / eta - n * (cosTheta2 - cosThetaI / eta);
	
	return ((vec3f(1,1,1) * (fresnel(hd) / (eta * eta))) / fabs(n.dot(wt)));
}


#pragma mark -
#pragma mark Total Internal Reflection

bool FresnelTransmitter::tir(const HitData& hd) const {
	vec3f wo(-(hd.getRay().getDirection()));
	float cosThetaI = hd.getNormal().dot(wo);
	float eta = etaIn / etaOut;
	
	if (cosThetaI < 0.0) {
		eta = 1.0 / eta;
	}
	
	return (1.0 - (1.0 - cosThetaI * cosThetaI) / (eta * eta) < 0.0);
}


#pragma mark - 
#pragma mark Fresnel

float FresnelTransmitter::fresnel(const HitData& hd) const {
	vec3f n(hd.getNormal());
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
	
	return (1.0 - (0.5 * (rPar * rPar + rPerp * rPerp)));
}

void FresnelTransmitter::setEtaIn(float etaIn) {
	this->etaIn = etaIn;
}

float FresnelTransmitter::getEtaIn(void) {
	return etaIn;
}

void FresnelTransmitter::setEtaOut(float etaOut) {
	this->etaOut = etaOut;
}

float FresnelTransmitter::getEtaOut(void) {
	return etaOut;
}