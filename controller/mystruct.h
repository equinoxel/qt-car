#ifndef MYSTRUCT_H
#define MYSTRUCT_H

#include <QtCore/QList>
#include <QtCore/QMetaType>
#include <QtDBus/QtDBus>

class MyStruct {
public:
	QString element1;
	qlonglong element2;
	QString element3;
};

Q_DECLARE_METATYPE(MyStruct)


inline void registerCommTypes() {
	qDBusRegisterMetaType<MyStruct>();
}

QDBusArgument &operator<<(QDBusArgument &argument, const MyStruct &mystruct);
const QDBusArgument &operator>>(const QDBusArgument &argument,
	MyStruct &mystruct);


#endif
