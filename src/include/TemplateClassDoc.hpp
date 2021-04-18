#include <StructsForDoc.hpp>
#include <list>

class TemplateClassDoc {
public:
    void set_class_info(
            string name,
            string short_desctiption,
            string description); // TODO покрыть тестами

    void add_method_info(
            string name, string short_description); // TODO покрыть тестами

    void
    add_var_info(string name, string short_description); // TODO покрыть тестами

    void make_documentation(string path);

protected:
    InfoForDoc info;
    list<MemberInfo> methods_info;
    list<MemberInfo> vars_info;
};