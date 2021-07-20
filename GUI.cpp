#include "GUI.h"
#include <qboxlayout.h>
#include <time.h>
#include <qapplication.h>
#include <qtimezone.h>

void GUI::initGui() {
	QVBoxLayout* ly = new QVBoxLayout;
	QHBoxLayout* lyBtn = new QHBoxLayout;
	setLayout(ly);
	ly->addWidget(computer);
	
	lyBtn->addStretch();
	lyBtn->addWidget(rockBtn);
	lyBtn->addStretch();
	lyBtn->addWidget(paperBtn);
	lyBtn->addStretch();
	lyBtn->addWidget(scissorsBtn);
	lyBtn->addStretch();

	ly->addLayout(lyBtn);
	ly->addWidget(result);
}

void GUI::delay() {
	QTime wait = QTime::currentTime().addMSecs(500);
	while (QTime::currentTime() < wait) {
		QCoreApplication::processEvents(QEventLoop::AllEvents, 500);
	}
}

int GUI::generate() {
	int num = rand() % 3 + 1;
	return num;
}

void GUI::connectSignals() {
	srand(time(NULL));

	QObject::connect(rockBtn, &QPushButton::clicked, this, [=]() {
		int nr = generate();
		if (nr == 1) {
			computer->setText("choosing...");
			delay();
			QPixmap rock("resources/rock.png");
			computer->setPixmap(rock.scaled(150,200));
			result->setText("Result: It's a draw!");
		}
		else if (nr == 2) {
			computer->setText("choosing...");
			delay();
			QPixmap paper("resources/paper.png");
			computer->setPixmap(paper.scaled(150, 200));
			result->setText("Result: You lost!");
		}
		else if (nr == 3) {
			computer->setText("choosing...");
			delay();
			QPixmap scissors("resources/scissors.png");
			computer->setPixmap(scissors.scaled(150, 200));
			result->setText("Result: You won!");
		}
		});

	QObject::connect(paperBtn, &QPushButton::clicked, this, [=]() {
		int nr = generate();
		if (nr == 1) {
			computer->setText("choosing...");
			delay();
			QPixmap rock("resources/rock.png");
			computer->setPixmap(rock.scaled(150, 200));
			result->setText("Result: You won!");
		}
		else if (nr == 2) {
			computer->setText("choosing...");
			delay();
			QPixmap paper("resources/paper.png");
			computer->setPixmap(paper.scaled(150, 200));
			result->setText("Result: It's a draw!");
		}
		else if (nr == 3) {
			computer->setText("choosing...");
			delay();
			QPixmap scissors("resources/scissors.png");
			computer->setPixmap(scissors.scaled(150, 200));
			result->setText("Result: You lost!");
		}
		});

	QObject::connect(scissorsBtn, &QPushButton::clicked, this, [=]() {
		int nr = generate();
		if (nr == 1) {
			computer->setText("choosing...");
			delay();
			QPixmap rock("resources/rock.png");
			computer->setPixmap(rock.scaled(150, 200));
			result->setText("Result: You lost!");
		}
		else if (nr == 2) {
			computer->setText("choosing...");
			delay();
			QPixmap paper("resources/paper.png");
			computer->setPixmap(paper.scaled(150, 200));
			result->setText("Result: You won!");
		}
		else if (nr == 3) {
			computer->setText("choosing...");
			delay();
			QPixmap scissors("resources/scissors.png");
			computer->setPixmap(scissors.scaled(150, 200));
			result->setText("Result: It's a draw!");
		}
		});
}

void GUI::setInitialState() {
	QPixmap rock("resources/rock.png");
	QIcon rockIcon(rock);
	rockBtn->setIcon(rockIcon);
	QSize rockSize = rock.rect().size() / 4;
	rockBtn->setIconSize(rockSize);
	
	QPixmap paper("resources/paper.png");
	QIcon paperIcon(paper);
	paperBtn->setIcon(paperIcon);
	QSize paperSize = paper.rect().size() / 4;
	paperBtn->setIconSize(paperSize);

	QPixmap scissors("resources/scissors.png");
	QIcon scissorsIcon(scissors);
	scissorsBtn->setIcon(scissorsIcon);
	QSize scissorsSize = scissors.rect().size() / 4;
	scissorsBtn->setIconSize(scissorsSize);

	computer->setText("Here will appear the computer's choice");
	computer->setStyleSheet("QLabel{ font-size: 20px; display: block; margin: auto;}");
	result->setText("Result:");
	result->setStyleSheet("QLabel{ font-size: 20px; display: block; margin: auto;}");
}