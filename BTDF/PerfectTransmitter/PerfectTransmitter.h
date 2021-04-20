#ifndef PERFECTTRANSMITTER_H
#define PERFECTTRANSMITTER_H
/*
 *  PerfectTransmitter.h
 *  ktRayTracer
 */

#include "BTDF.h"


class PerfectTransmitter : public BTDF {

public:
	PerfectTransmitter(void);
	PerfectTransmitter(float kt, float ior);
	
	~PerfectTransmitter(void);
	
	virtual void showInfo(void) const;
	
	virtual vec3f sample_f(const HitData& hd, const vec3f& wo, vec3f& wt) const;
	
	virtual bool tir(const HitData& hd) const;
	
	void setKt(float kt);
	float getKt(void);
	
	void setIor(float ior);
	float getIor(void);
	
private:
	float kt;
	float ior;
	
};

#endif // PERFECTTRANSMITTER_H