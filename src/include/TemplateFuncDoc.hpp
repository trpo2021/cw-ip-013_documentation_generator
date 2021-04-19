#include <StructsForDoc.hpp>

class TemplateFuncDoc {
public:
    void
    set_func_info(string name, string short_desctiption, string description);

    void make_documentation(string path); // TODO покрыть тестами

protected:
    InfoForDoc info;
};