#include "user.h"
#include "../gamers/computergamer.h"

User::User() : field(QVector<QVector<Field::FieldPlace>>())
{
    emptyField = false;
    field = AlliedField(ComputerGamer::randomBuildField());

}


const QString &User::getName() const
{
    return name;
}

void User::setName(const QString &newName)
{
    name = newName;
}



bool User::isEmptyField()
{
    return emptyField;
}

const AlliedField &User::getField()
{
    emptyField = true;
    return field;
}

void User::setField(const AlliedField &newField)
{
    emptyField = false;
    field = newField;
}
