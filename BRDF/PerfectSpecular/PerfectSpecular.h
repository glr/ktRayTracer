#ifndef PERFECTSPECULAR_H
#define PERFECTSPECULAR_H
/*
 *  PerfectSpecular.h
 *  ktRayTracer
 */

#include "BRDF.h"


class PerfectSpecular : public BRDF {
	
public:
	PerfectSpecular(void);
	PerfectSpecular(float kr, const vec3f& cr);
	PerfectSpecular(float kr, float r, float g, float b);
	
	~PerfectSpecular(void);
	
	virtual void showInfo(void) const;

	virtual vec3f sample_f(const HitData& hd, const vec3f& wo, vec3f& wi) const;
	
	void setKr(float kr);
	float getKr(void);
	
	void setCr(const vec3f& cr);
	void setCr(float r, float g, float b);
	vec3f getCr(void);
	
private:
	float kr;
	vec3f cr;
	
};

#endif // PERFECTSPECULAR_H