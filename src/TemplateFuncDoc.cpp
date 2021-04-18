#include <TemplateFuncDoc.hpp>

void TemplateFuncDoc::make_documentation(string path)
{
    // TODO Семену, написать функцию вывода html шаблона в файл.
}

void TemplateFuncDoc::set_func_info(
        string name, string short_desctiption, string description)
{
    this->info.name = name;
    this->info.short_description = short_desctiption;
    this->info.description = description;
}