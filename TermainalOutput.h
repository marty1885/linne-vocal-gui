#ifndef TERMAINALOUTPUT_H
#define TERMAINALOUTPUT_H

#include <QMainWindow>
#include <QProcess>
#include <QColor>

#include <iostream>

namespace Ui {
class TermainalOutput;
}

class TermainalOutput : public QMainWindow
{
	Q_OBJECT

public:
	explicit TermainalOutput(QWidget *parent = 0);
	QString command;
	QStringList args;
	void execute();

	~TermainalOutput();

private:
	QProcess process;
	Ui::TermainalOutput *ui;
private slots:
	void onRead();
	void onProcessEnd();
};

#endif // TERMAINALOUTPUT_H
