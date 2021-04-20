#ifndef FRESNELREFLECTOR_H
#define FRESNELREFLECTOR_H
/*
 *  FresnelReflector.h
 *  ktRayTracer
 */

#include "BRDF.h"


class FresnelReflector : public BRDF {
	
public:
	FresnelReflector(void);
	FresnelReflector(float etaIn, float etaOut);
	
	~FresnelReflector(void);
	
	virtual void showInfo(void) const;
	
	virtual vec3f sample_f(const HitData& hd, const vec3f& wo, vec3f& wi) const;
	
	float fresnel(const HitData& hd) const;
	
	void setEtaIn(float etaIn);
	float getEtaIn(void);
	
	void setEtaOut(float etaOut);
	float getEtaOut(void);
	
private:
	float etaIn;
	float etaOut;
	
};

#endif // FRESNELREFLECTOR_H