#ifndef CAMERA_H
#define CAMERA_H
/*
 *  Camera.h
 *  ktRayTracer
 */

#include <iostream>

#include "vec.h"
#include"Sampler.h"


using namespace std;
using namespace gutz;


class World;
class GLWidget;


class Camera {
	
public:
	Camera(void);
	
	Camera(const vec3f& eye, const vec3f& lookat, const vec3f& up, unsigned int samples);
	
	~Camera(void);
	
	virtual void showInfo(void) const;
	
	void setEye(const vec3f& eye);
	void setEye(float x, float y, float z);
	vec3f getEye(void) const;
	
	void setLookat(const vec3f& lookat);
	void setLookat(float x, float y, float z);
	vec3f getLookat(void) const;
	
	void setUp(const vec3f& up);
	void setUp(float x, float y, float z);
	vec3f getUp(void) const;
	
	void setONB(void);
	vec3f getU(void) const;
	vec3f getV(void) const;
	vec3f getW(void) const;
	vec<vec3f,3> getONB(void) const;
	
	void setSampler(Sampler *sampler);
	
	virtual GLWidget *render(World& world) const = 0;
	
protected:
	vec3f eye;
	vec3f lookat;
	vec3f up;
	vec3f u, v, w;
	vec3f direction;
	
	Sampler *sampler;
	
};

#endif // CAMERA_H