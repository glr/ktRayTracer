#ifndef TRANSPARENT_H
#define TRANSPARENT_H
/*
 *  Transparent.h
 *  ktRayTracer
 */

#include "Phong.h"
#include "PerfectSpecular.h"
#include "PerfectTransmitter.h"


class Transparent : public Phong {

public:
	Transparent(void);
	Transparent(float ka, float kd, const vec3f& cd, float ks, const vec3f& cs, float ps, float kr, const vec3f& cr, float kt, float ior);
	Transparent(float ka, float kd, float rd, float gd, float bd, float ks, float rs, float gs, float bs, float ps, 
			   float kr, float rr, float gr, float br, float kt, float ior);
	
	~Transparent(void);
	
	virtual void showInfo(void) const;
	
	void setKr(float kr);
	float getKr(void);
	
	void setCr(const vec3f& cr);
	void setCr(float r, float g, float b);
	vec3f getCr(void);
	
	void setKt(float kt);
	float getKt(void);
	
	void setIor(float ior);
	float getIor(void);
	
	virtual vec3f shade(HitData& hd);
	
private:
	PerfectSpecular *reflection;
	PerfectTransmitter *transparency;
	
};

#endif // TRANSPARENT_H