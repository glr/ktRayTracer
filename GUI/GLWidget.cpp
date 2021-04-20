/*
 *  glwidget.cpp
 *  QRayTracer
 */

#include <iostream>

#include <QtGui>
#include <QtOpenGL>

#include "GLWidget.h"


using namespace std;


GLWidget::GLWidget(QWidget *parent) : QGLWidget(parent), ip(NULL), world(NULL) {
	this->setFixedSize(ip->getWRes(), ip->getHRes());
}

GLWidget::GLWidget(ImagePlane *ip, QWidget *parent) : QGLWidget(parent), ip(ip), world(NULL) {
	this->setFixedSize(ip->getWRes(), ip->getHRes());
}

GLWidget::GLWidget(ImagePlane *ip, World *world, QWidget *parent) : QGLWidget(parent), ip(ip), world(world) {
	this->setFixedSize(ip->getWRes(), ip->getHRes());
}

GLWidget::~GLWidget(void) {
	makeCurrent();
}

void GLWidget::setImagePlane(ImagePlane *ip) {
	this->ip = ip;
}

ImagePlane *GLWidget::getImagePlane(void) {
	return ip;
}

void GLWidget::setWorld(World *world) {
	this->world = world;
}

World *GLWidget::getWorld(void) {
	return world;
}

void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, width(), 0.0, height());
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2i(0, 0);
	
    glDrawPixels(ip->getWRes(), ip->getHRes(), GL_RGB, GL_FLOAT, ip->getPixelBuffer());
}

void GLWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() & Qt::LeftButton) {
		int x = event->x();
		int ycor = height() - event->y();
		vec3f pix = ip->getPixelColor(x, ycor);
		cout << "pixel:  x=" << x << ", y=" << ycor;
		cout << ", r=" << pix[0] << ", g=" << pix[1] << ", b=" << pix[2] << endl;
		cout << "pixel world coordinates:  " << ip->getPixelLocation(x, ycor) << endl;
    }
}

void GLWidget::keyPressEvent(QKeyEvent *event) {
	switch(event->key()) {
		case Qt::Key_Q:
			exit(0);
			break;
		case Qt::Key_C:
			if (world) {
				world->showInfo();
			}
            break;
		default:
            QGLWidget::keyPressEvent(event);
            break;
	}	
}