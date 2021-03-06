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

#include "informationsbox.h"

#include <string>

InformationsBox::InformationsBox()
    : m_currentItem(0)
{
}


InformationsBox::~InformationsBox()
{
}


void InformationsBox::setViewerPointer(Viewer* viewerPointer)
{
    m_viewer = viewerPointer;
}


void InformationsBox::listSet(QStringList infos)
{
    clear();
    addItems(infos);
}


void InformationsBox::setCurrentItem(QTreeWidgetItem* ent, int col)
{
    m_currentItem = ent;
    refreshBox(true);
}


void InformationsBox::refreshBox(bool)
{
    if (m_currentItem) {
        clear();
        std::string temp = m_currentItem->text(0).toStdString();

        if (temp == "Camera")
            addItems(m_viewer->camData());
        else {
            addItem(m_currentItem->text(0));
            addItem(tr("Sorry, no info on this :'("));
        }
    }
}
