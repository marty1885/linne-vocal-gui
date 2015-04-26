#include "TermainalOutput.h"
#include "ui_TermainalOutput.h"

using namespace std;

TermainalOutput::TermainalOutput(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::TermainalOutput)
{
	ui->setupUi(this);
	ui->tedTerminal->setTextColor(QColor("white"));
	ui->tedTerminal->setTextBackgroundColor(QColor("black"));
	ui->tedTerminal->setStyleSheet("QTextEdit { background-color: rgb(0,0,0)}");

	QObject::connect(&process,SIGNAL(readyReadStandardError()),this,SLOT(onRead()));
	QObject::connect(&process,SIGNAL(finished(int)),this,SLOT(onProcessEnd()));

	setWindowTitle("Console Output");
}

void TermainalOutput::execute()
{
	ui->tedTerminal->clear();
	//cout << command.toLocal8Bit().data() << endl;
	process.start(command);
	process.waitForStarted(-1);
}

TermainalOutput::~TermainalOutput()
{
	delete ui;
}

void TermainalOutput::onRead()
{
	ui->tedTerminal->append(process.readAllStandardError().toStdString().c_str());
}

void TermainalOutput::onProcessEnd()
{
	if(process.exitCode() == 0)
		ui->tedTerminal->append("\n\nSynthesis success!\n");
	else
		ui->tedTerminal->append("\n\nFailed!\n");
}
