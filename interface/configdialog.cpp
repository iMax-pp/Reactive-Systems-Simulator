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
