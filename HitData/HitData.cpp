/*
 *  HitData.cpp
 *  ktRayTracer
 */

#include "HitData.h"


#pragma mark HitData

HitData::HitData(const World& world) 
: hit(false), material(NULL), hitPoint(), texHitPoint(), normal(), ray(), depth(0), t(0), world(world) {
	
}

HitData::HitData(const HitData& hd)
: hit(hd.getHit()), material(hd.getMaterial()), hitPoint(hd.getHitPoint()), 
texHitPoint(hd.getTexHitPoint()), normal(hd.getNormal()), ray(hd.getRay()), 
depth(hd.getDepth()), t(hd.getT()), world(hd.getWorld()) {
	
}

HitData::~HitData(void) {
	
}


#pragma mark -
#pragma mark Hit

void HitData::setHit(bool hit) {
	this->hit = hit;
}

bool HitData::getHit(void) const {
	return hit;
}


#pragma mark -
#pragma mark Material

void HitData::setMaterial(Material *material) {
	this->material = material;
}

Material *HitData::getMaterial(void) const {
	return material;
}


#pragma mark -
#pragma mark Hit Points

void HitData::setHitPoint(const vec3f& point) {
	hitPoint = point;
}

vec3f HitData::getHitPoint(void) const {
	return hitPoint;
}

void HitData::setTexHitPoint(const vec3f& point) {
	texHitPoint = point;
}

vec3f HitData::getTexHitPoint(void) const {
	return texHitPoint;
}


#pragma mark -
#pragma mark Normal

void HitData::setNormal(const vec3f& normal) {
	this->normal = normal;
}

vec3f HitData::getNormal(void) const {
	return normal;
}


#pragma mark -
#pragma mark Ray

void HitData::setRay(const Ray& ray) {
	this->ray = ray;
}

Ray HitData::getRay(void) const {
	return ray;
}


#pragma mark -
#pragma mark Depth

void HitData::setDepth(unsigned int depth) {
	this->depth = depth;
}

unsigned int HitData::getDepth(void) const {
	return depth;
}


#pragma mark -
#pragma mark T

void HitData::setT(float t) {
	this->t = t;
}

float HitData::getT(void) const {
	return t;
}


#pragma mark -
#pragma mark World

const World& HitData::getWorld(void) const {
	return world;
}
