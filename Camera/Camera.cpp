/*
 *  Camera.cpp
 *  ktRayTracer
 */

#include "Camera.h"
#include "Jittered.h"
#include "Regular.h"


#pragma mark Camera

Camera::Camera(void) 
: eye(vec3f(0, 0, 0)), lookat(vec3f(0, 1, 0)), up(vec3f(0, 0, 1)) {
	setONB();
	direction = lookat - eye;
	direction.normalize();
	sampler = new Regular(1);
}

Camera::Camera(const vec3f& eye, const vec3f& lookat, const vec3f& up, unsigned int samples) 
: eye(eye), lookat(lookat), up(up) {
	setONB();
	direction = lookat - eye;
	direction.normalize();
	if (samples == 1) {
		sampler = new Regular(samples);
	} else {
		sampler = new Jittered(samples);
	}
}

Camera::~Camera(void) {

}


#pragma mark -
#pragma mark Info

void Camera::showInfo(void) const {
	cout << "Eye:" << eye << endl;
	cout << "Lookat:  " << lookat << endl;
	cout << "Up:  " << up << endl;	
}


#pragma mark -
#pragma mark Eye

void Camera::setEye(const vec3f& eye) {
	this->eye = eye;
	setONB();
}

void Camera::setEye(float x, float y, float z) {
	this->eye = vec3f(x, y, z);
	setONB();
}

vec3f Camera::getEye(void) const {
	return eye;
}


#pragma mark -
#pragma mark Lookat

void Camera::setLookat(const vec3f& lookat) {
	this->lookat = lookat;
	setONB();
}

void Camera::setLookat(float x, float y, float z) {
	this->lookat = vec3f(x, y, z);
	setONB();
}

vec3f Camera::getLookat(void) const {
	return lookat;
}


#pragma mark -
#pragma mark Up

void Camera::setUp(const vec3f& up) {
	this->up = up;
	this->up.normalize();
	setONB();
}

void Camera::setUp(float x, float y, float z) {
	this->up = vec3f(x, y, z);
	this->up.normalize();
	setONB();
}

vec3f Camera::getUp(void) const {
	return up;
}


#pragma mark -
#pragma mark Sampler

void Camera::setSampler(Sampler *sampler) {
	this->sampler = sampler;
}


#pragma mark -
#pragma mark Ortho-Normal Basis

void Camera::setONB(void) {
	v = eye - lookat;
	v.normalize();
	
	u = cross(up, v);
	u.normalize();
	
	w = cross(v, u);
	w.normalize();
	
	//straight up
	if (eye[0] == lookat[0] && eye[1] == lookat[1] && eye[2] > lookat [2]) {
		u = vec3f(1, 0, 0);
		v = vec3f(0, 0, 1);
		w = vec3f(0, -1, 0);
	}
	
	// straight down
	if (eye[0] == lookat[0] && eye[2] == lookat[2] && eye[1] < lookat [1]) {
		u = vec3f(1, 0, 0);
		v = vec3f(0, 0, -1);
		w = vec3f(0, 1, 0);
	}
}

vec3f Camera::getU(void) const {
	return u;
}

vec3f Camera::getV(void) const {
	return v;
}

vec3f Camera::getW(void) const {
	return w;
}

vec<vec3f,3> Camera::getONB(void) const {
	return vec<vec3f,3>(u, v, w);
}
