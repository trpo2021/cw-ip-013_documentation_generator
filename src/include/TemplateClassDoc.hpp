#pragma once
#include <StructsForDoc.hpp>
#include <list>

class TemplateClassDoc {
public:
    //Заполняет информацию о классе
    void
    set_class_info(string name, string short_desctiption, string description);

    //Добавляет запись о методе в список
    void add_method_info(string name, string short_description);

    //Добавляет запись о поле в список
    void add_var_info(string name, string short_description);

    //Генерирует html страницу по данным объекта
    void make_documentation(string path);

protected:
    InfoForDoc info;
    list<MemberInfo> methods_info;
    list<MemberInfo> vars_info;
};