/*
 *  MainWindow.cpp
 *  ktRayTracer
 */

#include <QtGui>

#include "MainWindow.h"
#include "FlatMeshTriangle.h"
#include "Phong.h"

#pragma mark MainWindow

MainWindow::MainWindow() {
	createMenu();
	createButton();
	
	setUnifiedTitleAndToolBarOnMac(true);
}

MainWindow::MainWindow(World& world) : world(world) {
	createMenu();
	createButton();
	
	setUnifiedTitleAndToolBarOnMac(true);
}

MainWindow::~MainWindow(void) {
	delete renderButton;
}


#pragma mark -
#pragma mark Render

void MainWindow::renderWorld(void) {
	cout << "Render!" << endl;
	world.render();
}


#pragma mark -
#pragma mark GUI Elements

void MainWindow::open(void) {
	QString filename = QFileDialog::getOpenFileName(this, "Open obj file", "", ".obj files (*.obj)");
	cout << "Filename:  " << filename.toStdString() << endl;

	objFileModel = glmReadOBJ((char *)filename.toStdString().c_str());
	glmUnitize(objFileModel);
	

	
	GLMgroup *groups = objFileModel->groups;
	while (groups) {
		for (unsigned int i = 0; i < groups->numtriangles; i++) {
			// make a mesh triangle and add it to the world
			world.addGeometry(new FlatMeshTriangle(objFileModel, groups->triangles[i], new Phong(0.2, 0.5, 1, .05, .05, .5, 1, .9, .9, 10)));
		}
		groups = groups->next;
	}
}

void MainWindow::quit(void) {
	exit(0);
}

void MainWindow::createButton(void) {
	renderButton = new QPushButton("Render!", this);
	setCentralWidget(renderButton);
	connect(renderButton, SIGNAL(pressed()), this, SLOT(renderWorld()));
}

void MainWindow::createMenu(void) {
	menuBar = new QMenuBar(0);
	fileMenu = new QMenu("&File");
	menuBar->addMenu(fileMenu);
	
	exitAction = new QAction("E&xit", this);
	exitAction->setShortcuts(QKeySequence::Quit);
	exitAction->setStatusTip("Exit the application");
	connect(exitAction, SIGNAL(triggered()), this, SLOT(quit()));

	openAction = new QAction("&Open", this);
	openAction->setShortcuts(QKeySequence::Open);
	openAction->setStatusTip("Open .obj file");
	connect(openAction, SIGNAL(triggered()), this, SLOT(open()));
	
	fileMenu->addAction(openAction);
	
	this->setMenuBar(menuBar);
}