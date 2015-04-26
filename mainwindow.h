#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>

#include <iostream>
#include <string>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sxdb.h>

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

private:
	Ui::MainWindow *ui;
	int load(QString path);
};

#endif // MAINWINDOW_H
