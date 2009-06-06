/*******************************************************************************************
 **
 **    Copyright 2008 Simon & Humphries
 **
 **    This file is part of the Reactive Systems Simulator.
 **
 **    The Reactive Systems Simulator is free software: you can redistribute it and/or modify
 **    it under the terms of the GNU General Public License as published by
 **    the Free Software Foundation, either version 3 of the License, or
 **    (at your option) any later version.
 **
 **    The Reactive Systems Simulator is distributed in the hope that it will be useful,
 **    but WITHOUT ANY WARRANTY; without even the implied warranty of
 **    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **    GNU General Public License for more details.
 **
 **    You should have received a copy of the GNU General Public License
 **    along with the Reactive Systems Simulator .  If not, see <http://www.gnu.org/licenses/>.
 **
 ********************************************************************************************/

#include "configdialog.h"

// Partie pages de configuration

ConfigurationPage::ConfigurationPage()
{	
	ProgramSettings * settings = new ProgramSettings();

	QVBoxLayout * programConfigLayout = new QVBoxLayout;

	QCheckBox * fullscreenCheckBox = new QCheckBox(tr("Set program fullscreen\n on startup."));
	fullscreenCheckBox->setChecked(settings->value("window/fullscreen").toBool());
	QObject::connect(fullscreenCheckBox, SIGNAL(stateChanged(int)), settings, SLOT(setFullscreen(int)));

	programConfigLayout->addWidget(fullscreenCheckBox);
	setLayout(programConfigLayout);
}


OpenGLPage::OpenGLPage()
{
	ProgramSettings * settings = new ProgramSettings();

	QGridLayout * openglConfigLayout = new QGridLayout();

	QLabel * shadingmodetitle = new QLabel(tr("Shading Mode (0-3)"));
	QSpinBox * shadingmode = new QSpinBox();
	shadingmode->setMaximum(3);
	shadingmode->setMinimum(0);
	shadingmode->setValue(settings->value("opengl/shadingmode").toInt());
	QObject::connect(shadingmode, SIGNAL(valueChanged(int)), settings, SLOT(setShadingMode(int)));

	QLabel * ambientlighttitle = new QLabel(tr("Ambient Light Intensity"));
	QSpinBox * ambientlight = new QSpinBox();
	ambientlight->setMaximum(100);
	ambientlight->setMinimum(0);
	ambientlight->setValue(settings->value("opengl/ambientlight").toInt());
	QObject::connect(ambientlight, SIGNAL(valueChanged(int)), settings, SLOT(setAmbientLight(int)));

	QLabel * backgroundcolortitle = new QLabel(tr("Background Color"));
	QComboBox * backgroundcolor = new QComboBox();
	backgroundcolor->addItem(tr("blue"));
	backgroundcolor->addItem(tr("red"));
	backgroundcolor->addItem(tr("green"));
	backgroundcolor->addItem(tr("brown"));
	backgroundcolor->setCurrentIndex(backgroundcolor->findText(settings->value("opengl/backgroundcolor").toString()));
	QObject::connect(backgroundcolor, SIGNAL(currentIndexChanged(QString)), settings, SLOT(setBackgroundColor(QString)));

	openglConfigLayout->addWidget(shadingmodetitle,1,1);
	openglConfigLayout->addWidget(shadingmode,1,2);
	openglConfigLayout->addWidget(ambientlighttitle,2,1);
	openglConfigLayout->addWidget(ambientlight,2,2);
	openglConfigLayout->addWidget(backgroundcolortitle,3,1);
	openglConfigLayout->addWidget(backgroundcolor,3,2);

	setLayout(openglConfigLayout);
}


#pragma mark -

// Partie boîte de configuration

ConfigDialog::ConfigDialog()
{
	contentsWidget = new QListWidget;
	contentsWidget->setViewMode(QListView::IconMode);
	contentsWidget->setIconSize(QSize(96, 84));
	contentsWidget->setMovement(QListView::Static);
	contentsWidget->setMaximumWidth(128);
	contentsWidget->setMinimumHeight(300);
	contentsWidget->setSpacing(12);

	pagesWidget = new QStackedWidget;
	pagesWidget->addWidget(new ConfigurationPage);
	pagesWidget->addWidget(new OpenGLPage);

	QPushButton *closeButton = new QPushButton(tr("Close"));

	createIcons();
	contentsWidget->setCurrentRow(0);

	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

	QHBoxLayout *horizontalLayout = new QHBoxLayout;
	horizontalLayout->addWidget(contentsWidget);
	horizontalLayout->addWidget(pagesWidget, 1);

	QHBoxLayout *buttonsLayout = new QHBoxLayout;
	buttonsLayout->addStretch(1);
	buttonsLayout->addWidget(closeButton);

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addLayout(horizontalLayout);
	mainLayout->addStretch(1);
	mainLayout->addSpacing(12);
	mainLayout->addLayout(buttonsLayout);
	setLayout(mainLayout);

	setWindowTitle(tr("Config Dialog"));
}


void ConfigDialog::createIcons()
{	
	QListWidgetItem *programConfigButton = new QListWidgetItem(contentsWidget);
	programConfigButton->setIcon(QIcon(":/images/systemsettings.png"));
	programConfigButton->setText(tr("Program\n Configuration"));
	programConfigButton->setTextAlignment(Qt::AlignHCenter);
	programConfigButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

	QListWidgetItem *openGLConfigButton = new QListWidgetItem(contentsWidget);
	openGLConfigButton->setIcon(QIcon(":/images/x.png"));
	openGLConfigButton->setText(tr("OpenGL\n Configuration"));
	openGLConfigButton->setTextAlignment(Qt::AlignHCenter);
	openGLConfigButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

	connect(contentsWidget,
			SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)),
			this, SLOT(changePage(QListWidgetItem *, QListWidgetItem*)));
}


void ConfigDialog::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
	if (!current)
		current = previous;

	pagesWidget->setCurrentIndex(contentsWidget->row(current));
}
