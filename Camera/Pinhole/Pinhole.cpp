/*
 *  Pinhole.cpp
 *  ktRayTracer
 */

#include <QString>

#include "Pinhole.h"
#include "HitData.h"
#include "RayCast.h"
#include "Whitted.h"

using namespace std;


#pragma mark Pinhole

Pinhole::Pinhole(void) 
: Camera(), focalLength(1), zoom (1), width(1), height(1), wRes(512), hRes(512) {
	vec3f w = cross(up, direction);
	ip = new ImagePlane(eye + direction * focalLength * zoom, width, height, w, cross(w, direction), wRes, hRes);
	window = new GLWidget(ip);
}

Pinhole::Pinhole(float focalLength, float zoom, float width, float height, float wRes, float hRes) 
: Camera(), focalLength(focalLength), zoom(zoom), width(width), height(height), wRes(wRes), hRes(hRes) {
	vec3f w = cross(up, direction);
	ip = new ImagePlane(eye + direction * focalLength * zoom, width, height, w, cross(w, direction), wRes, hRes);
	window = new GLWidget(ip);
}

Pinhole::Pinhole(float focalLength, float zoom, float width, float height, float wRes, float hRes, const vec3f& eye, const vec3f& lookat, const vec3f& up, unsigned int samples) 
: Camera(eye, lookat, up, samples), focalLength(focalLength), zoom(zoom), width(width), height(height), wRes(wRes), hRes(hRes) {
	vec3f w = cross(direction, up);
	ip = new ImagePlane(eye + direction * focalLength * zoom, width, height, w, cross(w, direction), wRes, hRes);
	window = new GLWidget(ip);
}

Pinhole::~Pinhole(void) {
	delete window;
	delete ip;
}


#pragma mark -
#pragma mark Info

void Pinhole::showInfo(void) const {
	cout << "*** Pinhole Camera Info ***" << endl;
	cout << "Focal Length:" << focalLength << endl;
	cout << "Zoom:  " << zoom << endl;
	Camera::showInfo();
	cout << endl;
}


#pragma mark -
#pragma mark Focal Length

void Pinhole::setFocalLength(float focalLength) {
	this->focalLength = focalLength;
}

float Pinhole::getFocalLength(void) const {
	return focalLength;
}


#pragma mark -
#pragma mark Zoom

void Pinhole::setZoom(float zoom) {
	this->zoom = zoom;
}

float Pinhole::getZoom(void) const {
	return zoom;
}


#pragma mark -
#pragma mark Dimensions

void Pinhole::setWidth(float width) {
	this->width = width;
}

float Pinhole::getWidth(void) const {
	return width;
}

void Pinhole::setHeight(float height) {
	this->height = height;
}

float Pinhole::getHeight(void) const {
	return height;
}


#pragma mark -
#pragma mark Resolutions

void Pinhole::setWRes(float wRes) {
	this->wRes = wRes;
}

float Pinhole::getWRes(void) const {
	return wRes;
}

void Pinhole::setHRes(float hRes) {
	this->hRes = hRes;
}

float Pinhole::getHRes(void) const {
	return hRes;
}


#pragma mark -
#pragma mark Ray Direction

vec3f Pinhole::getDirection(const vec3f&point) const {
	vec3f d = point - eye;
	d.normalize();
	return d;
}


#pragma mark -
#pragma mark Render

GLWidget *Pinhole::render(World& world) const {
	vec3f aimpoint;

	Ray r;
	r.setOrigin(eye);
	
	for (unsigned int i = 0; i < wRes; i++) {
		for (unsigned int j = 0; j < hRes; j++) {
			vec3f col(0, 0, 0);
			for (unsigned int k = 0; k < sampler->getSampleCount(); k++) {
				vec2f sample = sampler->nextSample();
				aimpoint = ip->getPixelLocation(i, j);
				aimpoint[0] += (sample[0] * ip->getPixelWidth());
				aimpoint[1] += (sample[1] * ip->getPixelHeight());
				
				r.setDirection(getDirection(aimpoint));
				
				col += world.getTracer()->trace(r);
			}

			col /= sampler->getSampleCount();
			ip->setPixelColor(i, j, col);
		}
	}
	
	QString title = QString("Pinhole Camera Render - %1x%2 - %3 samples per pixel").arg(wRes).arg(hRes).arg(sampler->getSampleCount());
	
	window->setWindowTitle(title);
	window->setWorld(&world);
	window->show();
	return window;
}


