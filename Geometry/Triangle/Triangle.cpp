/*
 *  Triangle.cpp
 *  ktRayTracer
 */

#include "Triangle.h"
#include "BoundBox.h"

const float Triangle::kEpsilon = 0.0001;

#pragma mark Triangle

Triangle::Triangle(void) : p0(vec3f(0, 0, 0)), p1(vec3f(0, 1, 0)), p2(vec3f(1, 0, 0)) {
	normal = cross((p1 - p0), (p2 - p0));
	normal.normalize();
	vec3f pMin = p0;
	vec3f pMax = p0;
	
	pMin = vs_min(pMin, p1);
	pMin = vs_min(pMin, p2);
	
	pMax = vs_max(pMax, p1);
	pMax = vs_max(pMax, p2);
	
	bv = new BoundBox(pMin, pMax);
}

Triangle::Triangle(const vec3f& p0, const vec3f& p1, const vec3f& p2) : p0(p0), p1(p1), p2(p2) {
	normal = cross((p1 - p0), (p2 - p0));
	normal.normalize();
	
	vec3f pMin = p0;
	vec3f pMax = p0;
	
	pMin = vs_min(pMin, p1);
	pMin = vs_min(pMin, p2);
	
	pMax = vs_max(pMax, p1);
	pMax = vs_max(pMax, p2);
	
	bv = new BoundBox(pMin, pMax);
}

Triangle::Triangle(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2)
: p0(vec3f(x0, y0, z0)), p1(vec3f(x1, y1, z1)), p2(vec3f(x2, y2, z2)) { 
	normal = cross((p1 - p0), (p2 - p0));
	normal.normalize();
	
	vec3f pMin = p0;
	vec3f pMax = p0;
	
	pMin = vs_min(pMin, p1);
	pMin = vs_min(pMin, p2);
	
	pMax = vs_max(pMax, p1);
	pMax = vs_max(pMax, p2);
	
	bv = new BoundBox(pMin, pMax);
}

Triangle::Triangle(Material *material) : Geometry(material), p0(vec3f(0, 0, 0)), p1(vec3f(0, 1, 0)), p2(vec3f(1, 0, 0)) {
	normal = cross((p1 - p0), (p2 - p0));
	normal.normalize();
	
	vec3f pMin = p0;
	vec3f pMax = p0;
	
	pMin = vs_min(pMin, p1);
	pMin = vs_min(pMin, p2);
	
	pMax = vs_max(pMax, p1);
	pMax = vs_max(pMax, p2);
	
	bv = new BoundBox(pMin, pMax);
}

Triangle::Triangle(const vec3f& p0, const vec3f& p1, const vec3f& p2, Material *material) : Geometry(material), p0(p0), p1(p1), p2(p2) {
	normal = cross((p1 - p0), (p2 - p0));
	normal.normalize();
	
	vec3f pMin = p0;
	vec3f pMax = p0;
	
	pMin = vs_min(pMin, p1);
	pMin = vs_min(pMin, p2);
	
	pMax = vs_max(pMax, p1);
	pMax = vs_max(pMax, p2);
	
	bv = new BoundBox(pMin, pMax);
}

Triangle::Triangle(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2, Material *material)
: Geometry(material), p0(vec3f(x0, y0, z0)), p1(vec3f(x1, y1, z1)), p2(vec3f(x2, y2, z2)) { 
	normal = cross((p1 - p0), (p2 - p0));
	normal.normalize();
	
	vec3f pMin = p0;
	vec3f pMax = p0;
	
	pMin = vs_min(pMin, p1);
	pMin = vs_min(pMin, p2);
	
	pMax = vs_max(pMax, p1);
	pMax = vs_max(pMax, p2);
	
	bv = new BoundBox(pMin, pMax);
}

Triangle::~Triangle(void) {
	
}


#pragma mark -
#pragma mark Info

void Triangle::showInfo(void) const {
	cout << "*** Triangle Info ***" << endl;
	cout << "p0:  " << p0 << endl;
	cout << "p1:  " << p1 << endl;
	cout << "p2:  " << p2 << endl;
	cout << "normal:  " << normal << endl;
	bv->showInfo();
	Geometry::showInfo();
	cout << endl << endl;
}


#pragma mark -
#pragma mark Hit

bool Triangle::hit(const Ray& ray, float& tmin, HitData& hd) const {
	
	vec3f rd = ray.getDirection();
	vec3f ro = ray.getOrigin();
	
	float a = p0[0] - p1[0], b = p0[0] - p2[0], c = rd[0], d = p0[0] - ro[0];
	float e = p0[1] - p1[1], f = p0[1] - p2[1], g = rd[1], h = p0[1] - ro[1];
	float i = p0[2] - p1[2], j = p0[2] - p2[2], k = rd[2], l = p0[2] - ro[2];
	
	float m = f * k - g * j, n = h * k - g * l, p = f * l - h * j;
	float q = g * i - e * k, s = e * j - f * i;
	
	float inv_denom  = 1.0 / (a * m + b * q + c * s);
	
	float e1 = d * m - b * n - c * p;
	float beta = e1 * inv_denom;
	
	if (beta <= 0.0) 
		return false;
	
	float r = e * l - h * i;
	float e2 = a * n + d * q + c * r;
	float gamma = e2 * inv_denom;
	
	if (gamma < 0.0)
	 	return false;
	
	if (beta + gamma > 1.0)
		return false;
	
	float e3 = a * p - b * r + d * s;
	float t = e3 * inv_denom;
	
	if (t < kEpsilon)
		return false;
	
	tmin = t;
	hd.setHitPoint(ray.getPoint(t));
	hd.setNormal(normal);
	return true;
}

bool Triangle::shadowHit(const Ray& ray, float& tmin) const {
	
	vec3f rd = ray.getDirection();
	vec3f ro = ray.getOrigin();
	
	float a = p0[0] - p1[0], b = p0[0] - p2[0], c = rd[0], d = p0[0] - ro[0];
	float e = p0[1] - p1[1], f = p0[1] - p2[1], g = rd[1], h = p0[1] - ro[1];
	float i = p0[2] - p1[2], j = p0[2] - p2[2], k = rd[2], l = p0[2] - ro[2];
	
	float m = f * k - g * j, n = h * k - g * l, p = f * l - h * j;
	float q = g * i - e * k, s = e * j - f * i;
	
	float inv_denom  = 1.0 / (a * m + b * q + c * s);

	float e1 = d * m - b * n - c * p;
	float beta = e1 * inv_denom;
	
	if (beta <= 0.0) 
		return false;
	
	float r = e * l - h * i;
	float e2 = a * n + d * q + c * r;
	float gamma = e2 * inv_denom;
	
	if (gamma < 0.0)
	 	return false;
	
	if (beta + gamma > 1.0)
		return false;
	
	float e3 = a * p - b * r + d * s;
	float t = e3 * inv_denom;
	
	if (t < kEpsilon)
		return false;
	
	tmin = t;
	return true;
}
