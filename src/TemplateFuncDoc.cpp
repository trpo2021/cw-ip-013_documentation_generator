#include <TemplateFuncDoc.hpp>

#include <StructsForDoc.hpp>

void TemplateFuncDoc::make_documentation(
        string path, string path_to_template) //покрыть тестами.
{
    ofstream fout;
    ifstream fin;
    fout.open(path + "/Func/" + this->info.name + ".html");
    fin.open(path_to_template + "/FuncName.html");
    std::string buff;
    std::getline(fin, buff, '\0');
    fin.close();

    for (int i = 0; i < (int)buff.size(); i++) {
        if (buff[i] == '#') {
            switch (buff[i + 1]) {
            case '1':
                fout << this->info.name;
                break;
            case '2':
                fout << this->info.short_description;
                break;
            case '3':
                fout << this->info.description;
                break;
            default:
                throw 1;
                break;
            }
            i++;
            continue;
        }
        fout << buff[i];
    }
    fout.close();
}

void TemplateFuncDoc::set_func_info(
        string name, string short_desctiption, string description)
{
    this->info.name = name;
    this->info.short_description = short_desctiption;
    this->info.description = description;
}