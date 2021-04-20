#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*
 *  MainWindow.h
 *  ktRayTracer
 */

#include <QMainWindow>

#include "glm.h"

#include "World.h"


class QPushButton;
class QMenu;
class QAction;

class MainWindow : public QMainWindow {

	Q_OBJECT
	
public:
	MainWindow(void);
	MainWindow(World& world);
	~MainWindow(void);

private slots:
	void renderWorld(void);
	void open(void);
	void quit(void);
	
private:
	GLMmodel *objFileModel;
	
	World world;
	
	QPushButton *renderButton;
	
	QMenuBar *menuBar;
	QMenu *fileMenu;
	QAction *exitAction;
	QAction *openAction;
	
	void createButton(void);
	void createMenu(void);
	
};

#endif // MAINWINDOW_H