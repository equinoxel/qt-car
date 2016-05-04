/****************************************************************************
**
** Copyright (C) 2005-2007 Trolltech ASA. All rights reserved.
**
** This file is part of the example classes of the Qt Toolkit.
**
** This file may be used under the terms of the GNU General Public
** License version 2.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of
** this file.  Please review the following information to ensure GNU
** General Public Licensing requirements will be met:
** http://www.trolltech.com/products/qt/opensource.html
**
** If you are unsure which license is appropriate for your use, please
** review the following information:
** http://www.trolltech.com/products/qt/licensing.html or contact the
** sales department at sales@trolltech.com.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
****************************************************************************/

#include <QtGui>
#include "mystruct.h"
#include "controller.h"
#include "car_interface_p.h"

Controller::Controller(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	registerCommTypes();
	
    car = new CarInterface("com.trolltech.CarExample", "/Car",
                           QDBusConnection::sessionBus(), this);
    startTimer(1000);
}

void Controller::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    if (car->isValid())
        ui.label->setText("connected");
    else
        ui.label->setText("disconnected");
}

void Controller::on_accelerate_clicked()
{
    car->accelerate();
}

void Controller::on_decelerate_clicked()
{
    car->decelerate();
}

void Controller::on_left_clicked()
{
    car->turnLeft();
}

void Controller::on_right_clicked()
{
    car->turnRight();
}


void Controller::on_structer_clicked()
{
	qlonglong r2;
    QDBusReply<MyStruct> r1 = car->structer(r2);
    printf(">>>>>> %d\n", r2);
}
