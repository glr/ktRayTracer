#ifndef DIELECTRIC_H
#define DIELECTRIC_H
/*
 *  Dielectric.h
 *  ktRayTracer
 */

#include "Phong.h"


class FresnelReflector;
class FresnelTransmitter;


class Dielectric : public Phong {

public:
	Dielectric(void);
	Dielectric(float ka, float kd, const vec3f& cd, float ks, const vec3f& cs, float ps, float etaIn, float etaOut, const vec3f& cfIn, const vec3f& cfOut);
	Dielectric(float ka, float kd, float rd, float gd, float bd, float ks, float rs, float gs, float bs, float ps, 
				float etaIn, float etaOut, float rfi, float gfi, float bfi, float rfo, float gfo, float bfo);
	
	~Dielectric(void);
	
	virtual void showInfo(void) const;
	
	void setEtaIn(float etaIn);
	float getEtaIn(void);
	
	void setEtaOut(float etaOut);
	float getEtaOut(void);
	
	void setCfIn(const vec3f& cfIn);
	void setCfIn(float r, float g, float b);
	vec3f getCfIn(void);
	
	void setCfOut(const vec3f& cfOut);
	void setCfOut(float r, float g, float b);
	vec3f getCfOut(void);
	
	virtual vec3f shade(HitData& hd);
	
private:
	vec3f cfIn;
	vec3f cfOut;
	
	FresnelReflector *reflection;
	FresnelTransmitter *translucency;
	
	vec3f powc(const vec3f& v, float p);
	
};

#endif // DIELECTRIC_H