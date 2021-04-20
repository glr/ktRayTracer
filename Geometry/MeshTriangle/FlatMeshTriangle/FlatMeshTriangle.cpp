/*
 *  FlatMeshTriangle.cpp
 *  ktRayTracer
 */

#include "FlatMeshTriangle.h"


#pragma mark FlatMeshTriangle

FlatMeshTriangle::FlatMeshTriangle(void) : MeshTriangle() {
	
}

FlatMeshTriangle::FlatMeshTriangle(GLMmodel *model, unsigned int tIndex) : MeshTriangle(model, tIndex) {
	
}

FlatMeshTriangle::FlatMeshTriangle(Material *material) : MeshTriangle(material) {
	
}

FlatMeshTriangle::FlatMeshTriangle(GLMmodel *model, unsigned int tIndex, Material *material) : MeshTriangle(model, tIndex, material) {
	
}

FlatMeshTriangle::~FlatMeshTriangle(void) {
	
}


#pragma mark -
#pragma mark Hit

bool FlatMeshTriangle::hit(const Ray& ray, float& tmin, HitData& hd) const {
	
	GLMtriangle triangle = model->triangles[tIndex];
	
	vec3f &p0 = *reinterpret_cast<vec3f *>(&model->vertices[3 * triangle.vindices[0]]);
	vec3f &p1 = *reinterpret_cast<vec3f *>(&model->vertices[3 * triangle.vindices[1]]);
	vec3f &p2 = *reinterpret_cast<vec3f *>(&model->vertices[3 * triangle.vindices[2]]);
	
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
	
	vec3f normal = cross(p1-p0, p2-p0);
	normal.normalize();
	hd.setNormal(normal);
	return true;
}