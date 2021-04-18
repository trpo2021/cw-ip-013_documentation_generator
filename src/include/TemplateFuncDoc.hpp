#include <FuncInfo.hpp>

class TemplateFuncDoc {
public:
    void
    set_func_info(string name, string short_desctiption, string description);

    void make_documentation(string path);

private:
    FuncInfo info;
};