#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;
using namespace Sxdb;

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setWindowTitle("Linne Vocal GUI 0.01");
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_btnRun_clicked()
{
	QString command = tr("java -jar %1 %2 %3 %4 %5 %6 %7").arg(ui->ledVexPath->text(),ui->ledEfbgwPath->text(),ui->ledWavtPath->text(),ui->ledOtoPath->text(),
						 ui->ledCsvPath->text(),ui->ledXvsqPath->text(),ui->ledOutPath->text());
	//cout << command.toLocal8Bit().data() <<endl;
	int result = system(command.toLocal8Bit().data());
	if(result != 0)
		QMessageBox::warning(this,"Error","Something is wrong while synthesis",QMessageBox::Yes);
}

void MainWindow::on_actionSafe_triggered()
{
	QString homePath = QDir::homePath();
	QString file2Name = QFileDialog::getSaveFileName(this,
		 tr("Save Linne Syntheisier setting"), homePath, tr("LSS Files (*.lss)"));

	DbDoc doc;
	doc.addData("xvsqExec",ui->ledVexPath->text().toLocal8Bit().data());
	doc.addData("efbfw",ui->ledEfbgwPath->text().toLocal8Bit().data());
	doc.addData("wavetool",ui->ledWavtPath->text().toLocal8Bit().data());
	doc.addData("oto",ui->ledOtoPath->text().toLocal8Bit().data());
	doc.addData("csv",ui->ledCsvPath->text().toLocal8Bit().data());
	doc.addData("xvsq",ui->ledXvsqPath->text().toLocal8Bit().data());
	doc.addData("out",ui->ledOutPath->text().toLocal8Bit().data());

	const char* str = file2Name.toLocal8Bit().data();
	int length = strlen(str);
	if(length < 4)
		file2Name.append(".lss");
	else if(str[length-3] != '.' && str[length-2] != 'l' && str[length-1] != 's' && str[length] != 's')
		file2Name.append(".lss");

	doc.save(file2Name.toLocal8Bit().data());
}

void MainWindow::on_actionOpen_triggered()
{
	QString homePath = QDir::homePath();
	QString file2Name = QFileDialog::getOpenFileName(this,
		 tr("Open Linne Syntheisier setting"), homePath, tr("LSS Files (*.lss)"));
	load(file2Name);
}

int MainWindow::load(QString path)
{
	DbDoc doc;
	doc.load(path.toLocal8Bit().data());
	ui->ledVexPath->setText(doc.getStringData("xvsqExec").c_str());
	ui->ledEfbgwPath->setText(doc.getStringData("efbfw").c_str());
	ui->ledWavtPath->setText(doc.getStringData("wavetool").c_str());
	ui->ledOtoPath->setText(doc.getStringData("oto").c_str());
	ui->ledCsvPath->setText(doc.getStringData("csv").c_str());
	ui->ledXvsqPath->setText(doc.getStringData("xvsq").c_str());
	ui->ledOutPath->setText(doc.getStringData("out").c_str());

	return 1;
}

void MainWindow::on_actionAbout_triggered()
{
	QMessageBox::information(this,
"About","Linne Synthesiser GUI 0.01\n\
Copyright Marty CHang 2015.\n\
Released under MIT lisence"
				 ,QMessageBox::Yes);
}
