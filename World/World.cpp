/*
 *  World.cpp
 *  ktRayTracer
 */

#include <QTime>

#include "World.h"
#include "RayCast.h"
#include "Whitted.h"


#pragma mark World

World::World(void) {
//	tracer = new RayCast(this);
	tracer = new Whitted(this);
}

World::~World(void) {

}


#pragma mark -
#pragma mark Info

void World::showInfo(void) const {
	ambient->showInfo();
	for (unsigned int i = 0; i < lights.size(); i++) {
		lights[i]->showInfo();
	}
	for (unsigned int j = 0; j < cameras.size(); j++) {
		cameras[j]->showInfo();
	}
	for (unsigned int k = 0; k < this->objects.size(); k++) {
		objects[k]->showInfo();
	}
}


#pragma mark -
#pragma mark Lights

void World::addLight(Light *light) {
	lights.push_back(light);
}

vector<Light *> World::getLights(void) {
	return lights;
}

void World::setAmbient(Light *ambient) {
	this->ambient = ambient;
}

Light *World::getAmbient(void) {
	return ambient;
}

#pragma mark -
#pragma mark Cameras

void World::addCamera(const Camera *camera) {
	cameras.push_back(camera);
}


#pragma mark -
#pragma mark Objects

void World::addGeometry(const Geometry *object) {
	objects.push_back(object);
}

vector<const Geometry *> World::getGeometry(void) {
	return objects;
}

HitData World::hitObjects(const Ray& ray) const {
	HitData hd(*this);
	float t;
	vec3f norm;
	vec3f hitPoint;
	float tlow = 1000000;
	unsigned int objs = objects.size();
	
	for (unsigned int i = 0; i < objs; i++) {
		if (objects[i]->hit(ray, t, hd) && (t < tlow)) {
			hd.setHit(true);
			tlow = t;
			hd.setMaterial(objects[i]->getMaterial());
			norm = hd.getNormal();
			hitPoint = hd.getHitPoint();
		}
	}
	if (hd.getHit()) {
		hd.setT(tlow);
		hd.setNormal(norm);
		hd.setHitPoint(hitPoint);
	}
	return hd;
}


#pragma mark -
#pragma mark Render

Tracer *World::getTracer(void) {
	return tracer;
}

void World::render(void){
	for (unsigned int i = 0; i < cameras.size(); i++) {
		cameras[i]->render(*this);
	}
}

float World::render(unsigned int loops) {
	QTime t;
	float elapsed = 0.0;
	cout << "Rendering";
	for (unsigned int i = 0; i < loops; i++) {
		cout << ".";
		t.restart();
		this->render();
		elapsed += t.elapsed();
	}
	cout << endl;
	return (elapsed / (float)loops);
}
