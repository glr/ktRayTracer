#ifndef FRESNELTRANSMITTER_H
#define FRESNELTRANSMITTER_H
/*
 *  FresnelTransmitter.h
 *  ktRayTracer
 */

#include "BTDF.h"


class FresnelTransmitter : public BTDF {
	
public:
	FresnelTransmitter(void);
	FresnelTransmitter(float etaIn, float etaOut);
	
	~FresnelTransmitter(void);
	
	virtual void showInfo(void) const;
	
	virtual vec3f sample_f(const HitData& hd, const vec3f& wo, vec3f& wt) const;
	
	virtual bool tir(const HitData& hd) const;
	
	float fresnel(const HitData& hd) const;
	
	void setEtaIn(float etaIn);
	float getEtaIn(void);
	
	void setEtaOut(float etaOut);
	float getEtaOut(void);
	
private:
	float etaIn;
	float etaOut;
	
};

#endif // FRESNELTRANSMITTER_H