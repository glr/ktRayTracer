/*
 *  Sphere.cpp
 *  ktRayTracer
 */

#include "Sphere.h"


const float Sphere::kEpsilon = 0.0001;

#pragma mark Sphere

Sphere::Sphere(void) : center(vec3f(0, 0, 0)), radius(1) {
	Geometry::setBoundBox(BoundBox(center-radius, center+radius));
}

Sphere::Sphere(const vec3f& center, float radius) : center(center), radius(radius) {
	Geometry::setBoundBox(BoundBox(center-radius, center+radius));
}

Sphere::Sphere(float x, float y, float z, float radius) : center(vec3f(x, y, z)), radius(radius) {
	Geometry::setBoundBox(BoundBox(center-radius, center+radius));
}

Sphere::Sphere(Material *material) : Geometry(material), center(vec3f(0, 0, 0)), radius(1) {
	Geometry::setBoundBox(BoundBox(center-radius, center+radius));
}

Sphere::Sphere(const vec3f& center, float radius, Material *material) : Geometry(material), center(center), radius(radius) {
	Geometry::setBoundBox(BoundBox(center-radius, center+radius));
}

Sphere::Sphere(float x, float y, float z, float radius, Material *material) : Geometry(material), center(vec3f(x, y, z)), radius(radius) {
	Geometry::setBoundBox(BoundBox(center-radius, center+radius));
}

Sphere::~Sphere(void) {
	Geometry::setBoundBox(BoundBox(center-radius, center+radius));
}


#pragma mark -
#pragma mark Info

void Sphere::showInfo(void) const {
	cout << "*** Sphere Info ***" << endl;
	cout << "Center:  " << center << endl;
	cout << "Radius:  " << radius << endl;
	Geometry::showInfo();
	cout << endl <<  endl;
}


#pragma mark -
#pragma mark Hit

bool Sphere::hit(const Ray& ray, float& tmin, HitData& hd) const {
	vec3f tmp = ray.getOrigin() - center;
	vec3f rd = ray.getDirection();
	vec3f ntmp;
	
	double a = rd.dot(rd);
	double b = 2 * rd.dot(tmp);
	double c = tmp.dot(tmp) - radius * radius;
	
	double disc = b * b - 4 * a * c;
	
	if (disc >= 0) {

		double e = sqrt(disc);
		double d = 2 * a;
		
		double t = (-b - e) / d;
		if (t < kEpsilon) {
			t = (-b + e) / d;
			if (t < kEpsilon) {
				return false;
			}
		}
		tmin = t;
		ntmp = (ray.getPoint(t) - center);
		ntmp.normalize();
		hd.setNormal(ntmp);
		hd.setHitPoint(ray.getPoint(t));
		
		float theta = acosf(ntmp[2]);
		float phi = atan2f(ntmp[1], ntmp[0]);
		
		if (phi < 0) {
			phi += (M_PI * 2);
		}
		
		hd.setTexHitPoint(vec3f(phi / (M_PI * 2), (M_PI - theta) / M_PI, 0));
		return true;
	}
	return false;
}

bool Sphere::shadowHit(const Ray& ray, float& tmin) const {
	vec3f tmp = ray.getOrigin() - center;
	vec3f rd = ray.getDirection();
	
	double a = rd.dot(rd);
	double b = 2 * rd.dot(tmp);
	double c = tmp.dot(tmp) - radius * radius;
	
	double disc = b * b - 4 * a * c;
	
	if (disc >= 0) {
		
		double e = sqrt(disc);
		double d = 2 * a;
		
		double t = (-b - e) / d;
		if (t > kEpsilon) {
			tmin = t;
			return true;
		}
		
		t = (-b + e) / d;
		if (t > kEpsilon) {
			tmin = t;
			return true;
		}
	}
	return false;
}
