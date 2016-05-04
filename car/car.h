/****************************************************************************
**
** Copyright (C) 2006-2007 Trolltech ASA. All rights reserved.
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

#ifndef CAR_H
#define CAR_H

#include <QGraphicsItem>
#include <QObject>
#include <QBrush>
#include "mystruct.h"

class Car : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Car();
    QRectF boundingRect() const;

public Q_SLOTS:
    void accelerate();
    void decelerate();
    void turnLeft();
    void turnRight();
    MyStruct structer(qlonglong &out1);

Q_SIGNALS:
    void crashed();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    void timerEvent(QTimerEvent *event);

private:
    QBrush color;
    qreal wheelsAngle; // used when applying rotation
    qreal speed; // delta movement along the body axis
};

#endif // CAR_H
