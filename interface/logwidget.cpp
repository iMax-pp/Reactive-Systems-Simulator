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

#include "logwidget.h"

LogWidget::LogWidget()
{
}


LogWidget::~LogWidget()
{
}


void LogWidget::newMsg(QString message)
{
    QTime t;
    t.start();

    QListWidgetItem* newItem = new QListWidgetItem(message.prepend(t.toString(QString("[hh.mm.ss] "))));

    addItem(newItem);
    scrollToItem(newItem);
}


void LogWidget::slotMsg(const QString message)
{
    newMsg(message);
}
