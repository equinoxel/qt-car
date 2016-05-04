#include "mystruct.h"

// Marshall the MyStructure data into a D-BUS argument
QDBusArgument &operator<<(QDBusArgument &argument, const MyStruct &mystruct)
{
    argument.beginStructure();
    argument << mystruct.element1 << mystruct.element2 << mystruct.element3;
    argument.endStructure();
    return argument;
}

// Retrieve the MyStructure data from the D-BUS argument
const QDBusArgument &operator>>(const QDBusArgument &argument, MyStruct &mystruct)
{
    argument.beginStructure();
    argument >> mystruct.element1 >> mystruct.element2 >> mystruct.element3;
    argument.endStructure();
    return argument;
}
