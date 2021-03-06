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

#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QListWidget>
#include <QString>
#include <QTime>
#include <QWidget>
#include <QtGui>

class LogWidget : public QListWidget {
        Q_OBJECT

    public:
        LogWidget();
        ~LogWidget();

        void newMsg(QString message);

    signals:
        void sigMsg(const QString message);

    public slots:
        void slotMsg(const QString message);

    private:
        //QListWidget* m_console;
};

#endif
