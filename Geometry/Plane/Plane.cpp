/*
 *  Plane.cpp
 *  ktRayTracer
 */

#include "Plane.h"


const float Plane::kEpsilon = 0.0001;

#pragma mark Plane

Plane::Plane(void) : point(vec3f(0, 0, 0)), normal(vec3f(0, 0, 1)) {
	this->normal.normalize();
}

Plane::Plane(const vec3f& point, const vec3f& normal) : point(point), normal(normal) {
	this->normal.normalize();
}

Plane::Plane(float x, float y, float z, const vec3f& normal) : point(vec3f(x, y, z)), normal(normal) {
	this->normal.normalize();
}

Plane::Plane(const vec3f& point, float u, float v, float w)  : point(point), normal(vec3f(u, v, w)) {
	normal.normalize();
}

Plane::Plane(float x, float y, float z, float u, float v, float w) : point(vec3f(x, y, z)), normal(vec3f(u, v, w)) {
	normal.normalize();
}

Plane::Plane(Material *material) : Geometry(material), point(vec3f(0, 0, 0)), normal(vec3f(0, 0, 1)) {
	normal.normalize();
}

Plane::Plane(const vec3f& point, const vec3f& normal, Material *material) : Geometry(material), point(point), normal(normal) {
	this->normal.normalize();
}

Plane::Plane(float x, float y, float z, const vec3f& normal, Material *material) : Geometry(material), point(vec3f(x, y, z)), normal(normal) {
	this->normal.normalize();
}

Plane::Plane(const vec3f& point, float u, float v, float w, Material *material)  : Geometry(material), point(point), normal(vec3f(u, v, w)) {
	normal.normalize();
}

Plane::Plane(float x, float y, float z, float u, float v, float w, Material *material) : Geometry(material), point(vec3f(x, y, z)), normal(vec3f(u, v, w)) {
	normal.normalize();
}

Plane::~Plane(void) {
	
}


#pragma mark -
#pragma mark Info

void Plane::showInfo(void) const {
	cout << "*** Plane Info ***" << endl;
	cout << "Point:  " << point << endl;
	cout << "Normal:  " << normal << endl;
	Geometry::showInfo();
	cout << endl << endl;
}


#pragma mark -
#pragma mark Hit

bool Plane::hit(const Ray& ray, float& tmin, HitData& hd) const {
	float t = normal.dot(point - ray.getOrigin()) / normal.dot(ray.getDirection());
	
	if (t > kEpsilon) {
		tmin = t;
		hd.setNormal(normal);
		hd.setHitPoint(ray.getPoint(t));
		return true;
	}
	return false;
}

bool Plane::shadowHit(const Ray& ray, float& tmin) const {
	float t = normal.dot(point - ray.getOrigin()) / normal.dot(ray.getDirection());
	
	if (t > kEpsilon){
		tmin = t;
		return true;
	} else
		return false;
}
