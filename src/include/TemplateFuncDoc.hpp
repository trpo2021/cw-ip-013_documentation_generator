#pragma once
#include <StructsForDoc.hpp>
#include <string>

class TemplateFuncDoc {
public:
    void
    set_func_info(string name, string short_desctiption, string description);

    void make_documentation(string path); // TODO покрыть тестами

    static list<string> names;

    static string path_to_template;

protected:
    InfoForDoc info;
};