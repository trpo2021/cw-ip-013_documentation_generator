#include <TemplateFuncDoc.hpp>

#include <StructsForDoc.hpp>

// TODO Добавить шаблон документации в вывод.
void TemplateFuncDoc::make_documentation(string path) //покрыть тестами.
{
    ofstream file;
    file.open(path + "/Func/" + this->info.name + ".html");

    file << this->info.name << " - ";

    file << this->info.short_description << endl;

    file << this->info.description << endl;
    file.close();
}

void TemplateFuncDoc::set_func_info(
        string name, string short_desctiption, string description)
{
    this->info.name = name;
    this->info.short_description = short_desctiption;
    this->info.description = description;
}