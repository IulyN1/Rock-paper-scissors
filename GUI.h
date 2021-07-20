#pragma once
#include <qwidget.h>
#include <qpushbutton.h>
#include <qlabel.h>

class GUI: public QWidget
{
private:
	QLabel* computer = new QLabel;
	QPushButton* rockBtn = new QPushButton;
	QPushButton* paperBtn = new QPushButton;
	QPushButton* scissorsBtn = new QPushButton;
	QLabel* result = new QLabel;

	// Function that initializes the GUI components
	void initGui();

	// Function that connects the signals of the GUI components
	void connectSignals();

	// Function that sets the initial state of the GUI application
	void setInitialState();

	// Function that generates a random number between 1 and 3 and returns it
	//		1 - rock, 2 - paper, 3 - scissors
	int generate();

	// Function that delays the execution of the program with 0.5 seconds
	void delay();
public:
	GUI() {
		initGui();
		connectSignals();
		setInitialState();
	}
};

