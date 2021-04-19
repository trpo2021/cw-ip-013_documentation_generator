#include <TemplateClassDoc.hpp>

void TemplateClassDoc::set_class_info(
        string name, string short_desctiption, string description)
{
    this->info.name = name;
    this->info.description = description;
    this->info.short_description = short_desctiption;
}

void TemplateClassDoc::add_method_info(string name, string short_description)
{
    this->methods_info.emplace_back(name, short_description);
}

void TemplateClassDoc::add_var_info(string name, string short_description)
{
    this->vars_info.emplace_back(name, short_description);
}

void TemplateClassDoc::make_documentation(string path)
{
    // TODO Семену, написать функцию вывода html шаблона со значениями в файл.
    // TODO Предусмотреть очищение полей после создания документации.
}