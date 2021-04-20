/*
 *  PerfectTransmitter.cpp
 *  ktRayTracer
 */

#include "PerfectTransmitter.h"
#include "HitData.h"


#pragma mark PerfectTransmitter

PerfectTransmitter::PerfectTransmitter(void) : kt(1.0), ior(1.0) {
	
}

PerfectTransmitter::PerfectTransmitter(float kt, float ior) : kt(kt), ior(ior) {
	
}

PerfectTransmitter::~PerfectTransmitter(void) {
	
}


#pragma mark -
#pragma mark Info

void PerfectTransmitter::showInfo(void) const {
	cout << "*** PerfectTransmitter BTDF ***" << endl;
	cout << "k transmittance:  " << kt << endl;
	cout << "index of refraction:  " << ior << endl << endl;
}


#pragma mark -
#pragma mark f

vec3f PerfectTransmitter::sample_f(const HitData& hd, const vec3f& wo, vec3f& wt) const {
	vec3f n(hd.getNormal());
	float cosThetaI = n.dot(wo);
	float eta = ior;
	
	if (cosThetaI < 0.0) {
		cosThetaI = -cosThetaI;
		n = -n;
		eta = 1.0 / eta;
	}
	
	float tmp = (1.0 - (1.0 - cosThetaI * cosThetaI) / (eta * eta));
	float cosTheta2 = sqrt(tmp);
	wt = -wo / eta - n * (cosTheta2 - cosThetaI / eta);
	
	return ((vec3f(1, 1, 1) * (kt / (eta * eta))) / fabs(n.dot(wt)));
}


#pragma mark -
#pragma mark Total Internal Reflection

bool PerfectTransmitter::tir(const HitData& hd) const {
	vec3f wo(-(hd.getRay().getDirection()));
	float cosThetaI = hd.getNormal().dot(wo);
	float eta = ior;
	
	if (cosThetaI < 0.0) {
		eta = 1.0 / eta;
	}
	
	return (1.0 - (1.0 - cosThetaI * cosThetaI) / (eta * eta) < 0.0);
}


#pragma mark -
#pragma mark Transmittance

void PerfectTransmitter::setKt(float kt) {
	this->kt = kt;
}

float PerfectTransmitter::getKt(void) {
	return kt;
}


#pragma mark -
#pragma mark Index of Refraction

void PerfectTransmitter::setIor(float ior) {
	this->ior = ior;
}

float PerfectTransmitter::getIor(void) {
	return ior;
}
