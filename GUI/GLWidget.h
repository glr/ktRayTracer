#ifndef GLWIDGET_H
#define GLWIDGET_H
/*
 *  glwidget.h
 *  QRayTracer
 */

#include <QGLWidget>

#include "ImagePlane.h";
#include "World.h"

class GLWidget : public QGLWidget {
    Q_OBJECT

public:
	GLWidget(QWidget *parent = 0);
	GLWidget(ImagePlane *ip, QWidget *parent = 0);
	GLWidget(ImagePlane *ip, World *world, QWidget *parent = 0);
	
	~GLWidget(void);
	
	void setImagePlane(ImagePlane *ip);
	ImagePlane *getImagePlane(void);

	void setWorld(World *world);
	World *getWorld(void);
	
protected:
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
	
private:
	ImagePlane *ip;
	World *world;
};

#endif // GLWIDGET_H