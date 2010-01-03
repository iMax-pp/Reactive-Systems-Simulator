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
    m_fullscreenCheckBox = new QCheckBox(tr("Set program fullscreen\n on startup."));

    m_fullscreenCheckBox->setChecked(settings->isFullscreen());
    QObject::connect(m_fullscreenCheckBox, SIGNAL(stateChanged(int)),
                     settings, SLOT(setFullscreen(int)));

    programConfigLayout->addWidget(m_fullscreenCheckBox);

    setLayout(programConfigLayout);
}


void ConfigurationPage::reset(ProgramSettings* settings)
{
    m_fullscreenCheckBox->setChecked(settings->isFullscreen());
}


OpenGLPage::OpenGLPage(ProgramSettings* settings)
{
    QGridLayout* openglConfigLayout = new QGridLayout();
    QLabel* shadingmodetitle = new QLabel(tr("Shading Mode (0-3)"));
    m_shadingmode = new QSpinBox();

    m_shadingmode->setMaximum(3);
    m_shadingmode->setMinimum(0);
    m_shadingmode->setValue(settings->shadingMode());
    QObject::connect(m_shadingmode, SIGNAL(valueChanged(int)),
                     settings, SLOT(setShadingMode(int)));

    QLabel* ambientlighttitle = new QLabel(tr("Ambient Light Intensity"));
    m_ambientlight = new QSpinBox();

    m_ambientlight->setMaximum(100);
    m_ambientlight->setMinimum(0);
    m_ambientlight->setValue(settings->ambientLight());
    QObject::connect(m_ambientlight, SIGNAL(valueChanged(int)),
                     settings, SLOT(setAmbientLight(int)));

    QLabel* backgroundcolortitle = new QLabel(tr("Background Color"));
    m_backgroundcolor = new QComboBox();

    m_backgroundcolor->addItem(tr("blue"));
    m_backgroundcolor->addItem(tr("red"));
    m_backgroundcolor->addItem(tr("green"));
    m_backgroundcolor->addItem(tr("black"));
    m_backgroundcolor->setCurrentIndex(m_backgroundcolor->findText(settings->backgroundColor()));
    QObject::connect(m_backgroundcolor, SIGNAL(currentIndexChanged(QString)),
                     settings, SLOT(setBackgroundColor(QString)));

    openglConfigLayout->addWidget(shadingmodetitle, 1, 1);
    openglConfigLayout->addWidget(m_shadingmode, 1, 2);
    openglConfigLayout->addWidget(ambientlighttitle, 2, 1);
    openglConfigLayout->addWidget(m_ambientlight, 2, 2);
    openglConfigLayout->addWidget(backgroundcolortitle, 3, 1);
    openglConfigLayout->addWidget(m_backgroundcolor, 3, 2);

    setLayout(openglConfigLayout);
}


void OpenGLPage::reset(ProgramSettings* settings)
{
    m_shadingmode->setValue(settings->shadingMode());
    m_ambientlight->setValue(settings->ambientLight());
    m_backgroundcolor->setCurrentIndex(m_backgroundcolor->findText(settings->backgroundColor()));
}


#pragma mark -

// Partie boîte de configuration

ConfigDialog::ConfigDialog(ProgramSettings* settings)
    : m_contentsWidget(new QListWidget)
    , m_pagesWidget(new QStackedWidget)
    , m_settings(settings)
    , m_configurationPage(new ConfigurationPage(m_settings))
    , m_openGLPage(new OpenGLPage(m_settings))
{
    m_contentsWidget->setViewMode(QListView::IconMode);
    m_contentsWidget->setIconSize(QSize(96, 84));
    m_contentsWidget->setMovement(QListView::Static);
    m_contentsWidget->setMaximumWidth(128);
    m_contentsWidget->setMinimumHeight(300);
    m_contentsWidget->setSpacing(12);

    m_pagesWidget->addWidget(m_configurationPage);
    m_pagesWidget->addWidget(m_openGLPage);

    QPushButton* applyButton = new QPushButton(tr("Apply"));
    QPushButton* revertButton = new QPushButton(tr("Revert"));

    createIcons();
    m_contentsWidget->setCurrentRow(0);
    connect(applyButton, SIGNAL(clicked()), this, SLOT(apply()));
    connect(revertButton, SIGNAL(clicked()), this, SLOT(revert()));

    QHBoxLayout* horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(m_contentsWidget);
    horizontalLayout->addWidget(m_pagesWidget, 1);

    QHBoxLayout* buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(applyButton);
    buttonsLayout->addWidget(revertButton);

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


void ConfigDialog::apply()
{
    m_settings->save();
    close();
}


void ConfigDialog::revert()
{
    m_settings->reset();
    m_configurationPage->reset(m_settings);
    m_openGLPage->reset(m_settings);
}
