#include <TemplateClassDoc.hpp>

void TemplateClassDoc::set_class_info(
        string name, string short_desctiption, string description)
{
    this->info.name = name;
    this->info.description = description;
    this->info.short_description = short_desctiption;
}

void TemplateClassDoc::make_documentation(string path)
{
    // TODO Семену, написать функцию вывода html шаблона со значениями в файл.
    // TODO Предусмотреть очищение полей после создания документации.
}

void TemplateClassDoc::add_method_info(string name, string short_description)
{
    MemberInfo method_info;
    method_info.name = name;
    method_info.short_description = short_description;

    this->methods_info.push_back(method_info);
}

void TemplateClassDoc::add_var_info(string name, string short_description)
{
    MemberInfo var_info;
    var_info.name = name;
    var_info.short_description = short_description;

    this->vars_info.push_back(var_info);
}