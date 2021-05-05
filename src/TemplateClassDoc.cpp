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

void TemplateClassDoc::make_documentation(string path, string path_to_template)
{
    ofstream fileout;
    ifstream filein;
    fileout.open(path + "/Class/" + this->info.name + ".html");
    filein.open(path_to_template + "/ClassName.html");

    std::string buff;
    std::getline(filein, buff, '\0');
    filein.close();

    int first_field = buff.find("#~");
    int last_field = buff.find("#~", first_field + 1);

    int first_method = buff.find("#*");
    int last_method = buff.find("#*", first_method + 2);

    for (int i = 0; i < first_field; i++) {
        if (buff[i] == '#') {
            switch (buff[i + 1]) {
            case '1':
                fileout << this->info.name;
                break;
            case '2':
                fileout << this->info.short_description;
                break;
            case '3':
                fileout << this->info.description;
                break;
            default:
                // throw 1;
                break;
            }
            i++;
            continue;
        }
        fileout << buff[i];
    }

    for (auto it = this->methods_info.begin(); it != this->methods_info.end();
         ++it) {
        for (int i = first_field + 2; i < last_field; i++) {
            if (buff[i] == '#') {
                switch (buff[i + 1]) {
                case '4':
                    fileout << it->name;
                    break;
                case '5':
                    fileout << it->short_description;
                    break;
                }
                i++;
                continue;
            }
            fileout << buff[i];
        }
    }

    for (int i = last_field + 2; i < first_method; i++) {
        fileout << buff[i];
    }

    for (auto it = this->vars_info.begin(); it != this->vars_info.end(); ++it) {
        for (int i = first_method; i < last_method; i++) {
            if (buff[i] == '#') {
                switch (buff[i + 1]) {
                case '6':
                    fileout << it->name;
                    break;
                case '7':
                    fileout << it->short_description;
                    break;
                }
                i++;
                continue;
            }
            fileout << buff[i];
        }
    }

    for (int i = last_method + 2; i < buff.size(); i++) {
        fileout << buff[i];
    }

    fileout.close();
}