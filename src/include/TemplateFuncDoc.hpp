#pragma once

#include <StructsForDoc.hpp>
#include <list>
#include <string>

class TemplateFuncDoc {
public:
    //Заполняет объект информацией о функции
    void
    set_func_info(string name, string short_desctiption, string description);

    //Генерирует html страницу по данным объекта
    void make_documentation(string path);

private:
    InfoForDoc info;
};