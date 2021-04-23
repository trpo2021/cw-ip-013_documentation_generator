#pragma once
#include <StructsForDoc.hpp>
#include <list>

class TemplateClassDoc {
public:
    void
    set_class_info(string name, string short_desctiption, string description);

    void add_method_info(string name, string short_description);

    void add_var_info(string name, string short_description);

    void make_documentation(string path); // TODO покрыть тестами

    static list<string> names;

    static string path_to_template;

protected:
    InfoForDoc info;
    list<MemberInfo> methods_info;
    list<MemberInfo> vars_info;
};