/*
 *    Copyright 2010 Humhpries & Simon
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 *
 */

#include "configdialog.h"

// Partie pages de configuration

ConfigurationPage::ConfigurationPage(ProgramSettings* settings)
{
    QVBoxLayout* programConfigLayout = new QVBoxLayout;
    QCheckBox* fullscreenCheckBox = new QCheckBox(tr("Set program fullscreen\n on startup."));

    fullscreenCheckBox->setChecked(settings->isFullscreen());
    QObject::connect(fullscreenCheckBox, SIGNAL(stateChanged(int)),
                     settings, SLOT(setFullscreen(int)));

    programConfigLayout->addWidget(fullscreenCheckBox);

    setLayout(programConfigLayout);
}


OpenGLPage::OpenGLPage(ProgramSettings* settings)
{
    QGridLayout* openglConfigLayout = new QGridLayout();
    QLabel* shadingmodetitle = new QLabel(tr("Shading Mode (0-3)"));
    QSpinBox* shadingmode = new QSpinBox();

    shadingmode->setMaximum(3);
    shadingmode->setMinimum(0);
    shadingmode->setValue(settings->shadingMode());
    QObject::connect(shadingmode, SIGNAL(valueChanged(int)),
                     settings, SLOT(setShadingMode(int)));

    QLabel* ambientlighttitle = new QLabel(tr("Ambient Light Intensity"));
    QSpinBox* ambientlight = new QSpinBox();

    ambientlight->setMaximum(100);
    ambientlight->setMinimum(0);
    ambientlight->setValue(settings->ambientLight());
    QObject::connect(ambientlight, SIGNAL(valueChanged(int)),
                     settings, SLOT(setAmbientLight(int)));

    QLabel* backgroundcolortitle = new QLabel(tr("Background Color"));
    QComboBox* backgroundcolor = new QComboBox();

    backgroundcolor->addItem(tr("blue"));
    backgroundcolor->addItem(tr("red"));
    backgroundcolor->addItem(tr("green"));
    backgroundcolor->addItem(tr("black"));
    backgroundcolor->setCurrentIndex(backgroundcolor->findText(settings->backgroundColor()));
    QObject::connect(backgroundcolor, SIGNAL(currentIndexChanged(QString)),
                     settings, SLOT(setBackgroundColor(QString)));

    openglConfigLayout->addWidget(shadingmodetitle, 1, 1);
    openglConfigLayout->addWidget(shadingmode, 1, 2);
    openglConfigLayout->addWidget(ambientlighttitle, 2, 1);
    openglConfigLayout->addWidget(ambientlight, 2, 2);
    openglConfigLayout->addWidget(backgroundcolortitle, 3, 1);
    openglConfigLayout->addWidget(backgroundcolor, 3, 2);

    setLayout(openglConfigLayout);
}


#pragma mark -

// Partie boîte de configuration

ConfigDialog::ConfigDialog(ProgramSettings* settings)
    : m_contentsWidget(new QListWidget)
    , m_pagesWidget(new QStackedWidget)
    , m_settings(settings)
{
    m_contentsWidget->setViewMode(QListView::IconMode);
    m_contentsWidget->setIconSize(QSize(96, 84));
    m_contentsWidget->setMovement(QListView::Static);
    m_contentsWidget->setMaximumWidth(128);
    m_contentsWidget->setMinimumHeight(300);
    m_contentsWidget->setSpacing(12);

    m_pagesWidget->addWidget(new ConfigurationPage(m_settings));
    m_pagesWidget->addWidget(new OpenGLPage(m_settings));

    QPushButton* saveButton = new QPushButton(tr("Save"));
    QPushButton* closeButton = new QPushButton(tr("Close"));

    createIcons();
    m_contentsWidget->setCurrentRow(0);
    connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(closeConfig()));

    QHBoxLayout* horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(m_contentsWidget);
    horizontalLayout->addWidget(m_pagesWidget, 1);

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(saveButton);
    buttonsLayout->addWidget(closeButton);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(horizontalLayout);
    mainLayout->addStretch(1);
    mainLayout->addSpacing(12);
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);
    setWindowTitle(tr("Configuration"));
}


void ConfigDialog::changePage(QListWidgetItem* current, QListWidgetItem* previous)
{
    if (!current)
        current = previous;

    m_pagesWidget->setCurrentIndex(m_contentsWidget->row(current));
}


void ConfigDialog::createIcons()
{
    QListWidgetItem* programConfigButton = new QListWidgetItem(m_contentsWidget);

    programConfigButton->setIcon(QIcon(":/images/systemsettings.png"));
    programConfigButton->setText(tr("Program\n Configuration"));
    programConfigButton->setTextAlignment(Qt::AlignHCenter);
    programConfigButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    QListWidgetItem* openGLConfigButton = new QListWidgetItem(m_contentsWidget);

    openGLConfigButton->setIcon(QIcon(":/images/x.png"));
    openGLConfigButton->setText(tr("OpenGL\n Configuration"));
    openGLConfigButton->setTextAlignment(Qt::AlignHCenter);
    openGLConfigButton->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

    connect(m_contentsWidget, SIGNAL(currentItemChanged(QListWidgetItem*, QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*, QListWidgetItem*)));
}


void ConfigDialog::save()
{
    m_settings->save();
    close();
}


void ConfigDialog::closeConfig()
{
    m_settings->reset();
    close();
}
