#include <TemplateFuncDoc.hpp>

void TemplateFuncDoc::make_documentation(string path)
{
    // TODO Семену, написать функцию вывода html шаблона с подставленными
    // значениями в файл.
    // TODO Предусмотреть очищение полей после создания документации.
}

void TemplateFuncDoc::set_func_info(
        string name, string short_desctiption, string description)
{
    this->info.name = name;
    this->info.short_description = short_desctiption;
    this->info.description = description;
}