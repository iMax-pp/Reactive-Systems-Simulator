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

#ifndef INFORMATIONSBOX_H
#define INFORMATIONSBOX_H

#include "../simulator/GLViewer.h"
#include <QtGui>

class InformationsBox : public QListWidget {
        Q_OBJECT

    public:
        InformationsBox();
        ~InformationsBox();

        void setViewerPointer(Viewer* viewerPointer);

    public slots:
        void listSet(QStringList infos);
        void setCurrentItem(QTreeWidgetItem* ent, int col);
        void refreshBox(bool);

    private:
        Viewer* m_viewer;
        QTreeWidgetItem* m_currentItem;
};

#endif
