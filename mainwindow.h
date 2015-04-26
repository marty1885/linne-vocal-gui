#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QShortcut>

#include <iostream>
#include <string>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sxdb.h>

#include "TermainalOutput.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_btnRun_clicked();
	void on_actionSafe_triggered();
	void on_actionOpen_triggered();
	void on_actionAbout_triggered();

	void on_actionBrowse_XVSQ_triggered();

	void on_actionSet_As_Default_triggered();

private:
	Ui::MainWindow *ui;
	QShortcut *saveShortCut;
	QShortcut *openShortCut;

	TermainalOutput terminal;

	int load(QString path);
	int save(QString path);
};

#endif // MAINWINDOW_H
