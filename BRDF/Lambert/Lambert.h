#ifndef LAMBERT_H
#define LAMBERT_H
/*
 *  Lambert.h
 *  ktRayTracer
 */

#include "BRDF.h"


class Lambert: public BRDF {

public:
	Lambert(void);
	Lambert(float kd, const vec3f& cd);
	Lambert(float kd, float r, float g, float b);
	
	~Lambert(void);
	
	virtual void showInfo(void) const;
	
	virtual vec3f f(const HitData& hd, const vec3f& wo, const vec3f& wi) const;
	
	virtual vec3f rho(const HitData& hd, const vec3f& wo) const;
	
	void setKd(float kd);
	float getKd(void);
	
	void setCd(const vec3f& cd);
	void setCd(float r, float g, float b);
	vec3f getCd(void);
	
private:
	float kd;
	vec3f cd;
	
};

#endif // LAMBERT_H