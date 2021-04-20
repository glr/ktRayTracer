#ifndef PINHOLE_H
#define PINHOLE_H
/*
 *  Pinhole.h
 *  ktRayTracer
 */

#include "Camera.h"
#include "ImagePlane.h"
#include "GLWidget.h"
#include "World.h"


class Pinhole : public Camera {
	
public:
	Pinhole(void);
	Pinhole(float focalLength, float zoom, float width, float height, float wRes, float hRes);
	Pinhole(float focalLength, float zoom, float width, float height, float wRes, float hRes, 
			const vec3f& eye, const vec3f& lookat, const vec3f& up, unsigned int samples);
	
	~Pinhole(void);
	
	virtual void showInfo(void) const;
	
	void setFocalLength(float focalLength);
	float getFocalLength(void) const;
	
	void setZoom(float zoom);
	float getZoom(void) const;
	
	void setWidth(float width);
	float getWidth(void) const;
	
	void setHeight(float height);
	float getHeight(void) const;
	
	void setWRes(float wRes);
	float getWRes(void) const;
	
	void setHRes(float hRes);
	float getHRes(void) const;
	
	vec3f getDirection(const vec3f&point) const;
	
	virtual GLWidget *render(World& world) const;
	
private:
	float focalLength;
	float zoom;
	float width;
	float height;
	float wRes;
	float hRes;
	
	ImagePlane *ip;
	GLWidget *window;
};

#endif // PINHOLE_H