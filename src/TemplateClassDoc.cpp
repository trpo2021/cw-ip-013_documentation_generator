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
    ofstream file;
    file.open(path + "/Class/" + this->info.name + ".html");

    file << this->info.name << " - ";

    file << this->info.short_description << endl;

    file << this->info.description << endl;

    for (auto it = this->methods_info.begin(); it != this->methods_info.end();
         ++it) {
        file << it->name << " - " << it->short_description << endl;
    }

    for (auto it = this->vars_info.begin(); it != this->vars_info.end(); ++it) {
        file << it->name << " - " << it->short_description << endl;
    }
    file.close();
}