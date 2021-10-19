#ifndef USER_H
#define USER_H

#include <QString>
#include "../field/alliedfield.h"

class User
{
public:
    User();
    const QString &getName() const;
    void setName(const QString &newName);

    bool isEmptyField();
    const AlliedField &getField();
    void setField(const AlliedField &newField);

private:
    QString name;

    AlliedField field;
    bool emptyField;
};

#endif // USER_H
