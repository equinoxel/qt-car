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

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ui_controller.h"

class CarInterface;

class Controller : public QWidget
{
    Q_OBJECT

public:
    Controller(QWidget *parent = 0);

protected:
    void timerEvent(QTimerEvent *event);

private slots:
    void on_accelerate_clicked();
    void on_decelerate_clicked();
    void on_left_clicked();
    void on_right_clicked();
    void on_structer_clicked();
    
private:
    Ui::Controller ui;
    CarInterface *car;
};

#endif

