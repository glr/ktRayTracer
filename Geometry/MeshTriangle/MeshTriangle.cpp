/*
 *  MeshTriangle.cpp
 *  ktRayTracer
 */

#include "MeshTriangle.h"

const float MeshTriangle::kEpsilon = 0.00001;

#pragma mark MeshTriangle

MeshTriangle::MeshTriangle(void) : model(NULL), tIndex(0) {
	
}

MeshTriangle::MeshTriangle(GLMmodel *model, unsigned int tIndex) : model(model), tIndex(tIndex) {
	
	setBoundBox();
}
	
MeshTriangle::MeshTriangle(Material *material) : Geometry(material), model(NULL), tIndex(0) {
	
	setBoundBox();
}

MeshTriangle::MeshTriangle(GLMmodel *model, unsigned int tIndex, Material *material) 
: Geometry(material), model(model), tIndex(tIndex) {
	
	
	
	setBoundBox();
}

MeshTriangle::~MeshTriangle(void) {
	
}


#pragma mark -
#pragma mark Info

void MeshTriangle::showInfo(void) const {
	cout << "*** Mesh Triangle Info ***" << endl;
	cout << "Triangle Index:  " << tIndex << endl;
	Geometry::showInfo();
	cout << endl << endl;
}


#pragma mark -
#pragma mark Model

void MeshTriangle::setModel(GLMmodel *model) {
	this->model = model;
}

GLMmodel *MeshTriangle::getModel(void) const {
	return model;
}


#pragma mark -
#pragma mark TIndex

void MeshTriangle::setTIndex(unsigned int tIndex) {
	this->tIndex = tIndex;
}

unsigned int MeshTriangle::getTIndex(void) const {
	return tIndex;
}


#pragma mark -
#pragma mark Hit

bool MeshTriangle::shadowHit(const Ray& ray, float& tmin) const {
	
	struct _GLMtriangle triangle = model->triangles[tIndex];
	
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
	return true;
}


#pragma mark -
#pragma mark Bounding Box

void MeshTriangle::setBoundBox(void) {
	
	struct _GLMtriangle triangle = model->triangles[tIndex];
	
	vec3f &p0 = *reinterpret_cast<vec3f *>(&model->vertices[3 * triangle.vindices[0]]);
	vec3f &p1 = *reinterpret_cast<vec3f *>(&model->vertices[3 * triangle.vindices[1]]);
	vec3f &p2 = *reinterpret_cast<vec3f *>(&model->vertices[3 * triangle.vindices[2]]);
	
	vec3f b0 = p0;
	b0 = vs_min(b0, p1);
	b0 = vs_min(b0, p2);
	
	vec3f b1 = p0;
	b1 = vs_max(b1, p1);
	b1 = vs_max(b1, p2);
	
	Geometry::setBoundBox(BoundBox(b0, b1));

}