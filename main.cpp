#include "abstractsinglefield.h"
#include <QApplication>
#include "mainmenu.h"
#include "graphicfieldview.h"
#include "fieldmodel.h"
#include "builderfield.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    QVector<QVector<Field::FieldPlace> > vector;
    FieldModel* model = new FieldModel(vector);
    GraphicFieldView view(model);
//    view.show();
    MainMenu menu;
    BuilderField builder;
    builder.show();
//    menu.show();
//    SingleField field;
//    field.show();
    return a.exec();
}
