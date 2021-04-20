#include <iostream>

#include <QtGui>

#include "MainWindow.h"

#include "glm.h"

#include "Pinhole.h"
#include "Plane.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Simple.h"
#include "Matte.h"
#include "Phong.h"
#include "Reflective.h"
#include "Transparent.h"
#include "Dielectric.h"
#include "Point.h"
#include "Ambient.h"
#include "World.h"
#include "GLWidget.h"
#include "Checker.h"
#include "PTexture.h"
#include "Image.h"
#include "FlatMeshTriangle.h"

#include "BVH.h"

using namespace std;


#pragma mark -
#pragma mark main

int main (int argc, char *argv[]) {
	QApplication rayTracer(argc, argv);	
	
	// single pixel camera for debugging
	Pinhole cameraD(1, 1, 2/512, 2/512, 512, 512, vec3f(0, 5, 3), vec3f(0.00, 4.00, 2.73), vec3f(0, 0, 1), 1);
	
	Pinhole camera(1, 2, 2, 2, 512, 512, vec3f(0, -2, -.5), vec3f(0, 0, 0), vec3f(0, 0, 1), 1);
//	Pinhole camera0(1, 1, 2, 2, 512, 512, vec3f(1, 5, 3), vec3f(0, 0, 0), vec3f(0, 0, 1), 4);
	Pinhole camera0(1, 1, 2, 2, 512, 512, vec3f(2.5, -3.8, 4), vec3f(2, -3.8, 0), vec3f(0, 0, 1), 16);
//	Pinhole camera0(1, 1, 2, 2, 512, 512, vec3f(0, 5, 3), vec3f(0, 0, 0), vec3f(0, 0, 1), 32);

	Simple pMatS(.05, .05, 1);
	Matte pMatM(0.2, 0.8, .05, .05, 1);
	Phong pMatP(0.2, 0.5, .05, .05, 1, .5, .2, .2, 1, 3);
	Checker *check = new Checker(0.25, 1.0, 1.0, 1.0, 0.80, 0.80, 0.80);
	PTexture pMatT(check);
	Reflective pMatR(0.25, 0.5, 0.05, 0.05, 0.05, 0.15, 0.2, 0.2, 0.2, 100, 0.75, 1.0, 1.0, 1.0);
	Plane p(0, 0, 0, 0, 0, 1, &pMatT);
	Plane ps(0, 0, 4, 0, 0, -1, &pMatT);
	
	Dielectric aMat(0.0, 0.0, 1.0, 0.05, 1.0, 0.5, 1.0, 0.9, 0.9, 2000, 1.0003, 1.8, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0);
	Dielectric gMat(0.0, 0.0, 1.0, 0.05, 1.0, 0.5, 1.0, 0.9, 0.9, 2000, 1.0003, 1.8, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0);
	Dielectric lMat(0.0, 0.0, 1.0, 0.05, 1.0, 0.5, 1.0, 0.9, 0.9, 2000, 1.0003, 1.8, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0);
	
	Point light0(1, 4, 4, 4, 1, 1, 1);
	Point light1(1, 0, -2, 3, 1, 1, 1);
	Point light2(1, -7, -2, 3, 1, 1, 1);
	Ambient ambient(1, 1, 1, 1);
	
	World world;
	
	world.setAmbient(&ambient);
	
	GLMmodel *obj;
	GLMgroup *groups;
	
	vector<const Geometry *> meshObj;
	
	FlatMeshTriangle *meshTri;
	BVH aBVH, gBVH, lBVH;
	
	world.addLight(&light1);
	world.addCamera(&camera0);
	world.addGeometry(&p);
	world.addGeometry(&ps);
	
	QString path;
	
	path = QFileDialog::getExistingDirectory(NULL, "Select directory where the AGL meshes reside", "", QFileDialog::ShowDirsOnly);
	
	if (path != NULL || !path.isEmpty()) {
	
	//A
/*
	obj = glmReadOBJ((char *)(path + QString("/a.obj")).toStdString().c_str());
	groups = obj->groups;
	while (groups) {		
		for (unsigned int i = 0; i < groups->numtriangles; i++) {
			meshTri = new FlatMeshTriangle(obj, groups->triangles[i], &aMat);
			meshObj.push_back(meshTri);
		}
		groups = groups->next;
	}
	aBVH = BVH(&meshObj[0], meshObj.size());
	aBVH.setMaterial(&aMat);
	world.addGeometry(&aBVH);
*/
		
/*	
	//G
	obj = glmReadOBJ((char *)(path + QString("/g.obj")).toStdString().c_str());
	groups = obj->groups;
	while (groups) {		
		for (unsigned int i = 0; i < groups->numtriangles; i++) {
			meshTri = new FlatMeshTriangle(obj, groups->triangles[i], &gMat);
			meshObj.push_back(meshTri);
		}
		groups = groups->next;
	}
	gBVH = BVH(&meshObj[0], meshObj.size());
	gBVH.setMaterial(&gMat);
	world.addGeometry(&gBVH);
*/
		obj = glmReadOBJ((char *)(path + QString("/bronto.obj")).toStdString().c_str());
		groups = obj->groups;
		while (groups) {		
			for (unsigned int i = 0; i < groups->numtriangles; i++) {
				meshTri = new FlatMeshTriangle(obj, groups->triangles[i], &gMat);
				meshObj.push_back(meshTri);
			}
			groups = groups->next;
		}
		gBVH = BVH(&meshObj[0], meshObj.size());
		gBVH.setMaterial(&gMat);
		world.addGeometry(&gBVH);
	
	// L
/*		
	obj = glmReadOBJ((char *)(path + QString("/l.obj")).toStdString().c_str());
	groups = obj->groups;
	while (groups) {		
		for (unsigned int i = 0; i < groups->numtriangles; i++) {
			meshTri = new FlatMeshTriangle(obj, groups->triangles[i], &lMat);
			meshObj.push_back(meshTri);
		}
		groups = groups->next;
	}
	lBVH = BVH(&meshObj[0], meshObj.size());
	lBVH.setMaterial(&lMat);
	world.addGeometry(&lBVH);
*/		
		
	unsigned int renderLoops = 1;
	cout << "Render Time:  " << world.render(renderLoops) << endl << endl;
	
	return rayTracer.exec();
	} else {
		return 0;
	}
}
