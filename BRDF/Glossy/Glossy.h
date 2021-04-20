#ifndef GLOSSY_H
#define GLOSSY_H
/*
 *  Glossy.h
 *  ktRayTracer
 */

#include "BRDF.h"


class Glossy : public BRDF {
	
public:
	Glossy(void);
	Glossy(float ks, const vec3f& cs, float ps);
	Glossy(float ks, float r, float g, float b, float ps);
	
	~Glossy(void);
	
	virtual void showInfo(void) const;
	
	virtual vec3f f(const HitData& hd, const vec3f& wo, const vec3f& wi) const;
	
	virtual vec3f rho(const HitData& hd, const vec3f& wo) const;
	
	void setKs(float ks);
	float getKs(void);
	
	void setPs(float ps);
	float getPs(void);
	
	void setCs(const vec3f& cs);
	void setCs(float r, float g, float b);
	vec3f getCs(void);
	
private:
	float ks;
	vec3f cs;
	float ps;
	
};

#endif GLOSSY_H