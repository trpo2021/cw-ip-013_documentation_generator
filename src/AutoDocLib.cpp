#include <AutoDocLib.hpp>

namespace fs = std::filesystem;

void auto_doc(string path)
{
    ifstream file;
    file.open(path);
    try {
        string doc;
        getline(file, doc, '\0');
        file.close();
        p2i position;
        long unsigned int last_com_simbol_pos = 0;
        while (1) {
            position = find_comment(doc, last_com_simbol_pos);
            if (position.first == -1)
                break;
            last_com_simbol_pos = position.second;
            if (doc.find("class", last_com_simbol_pos) == last_com_simbol_pos
                || doc.find("struct", last_com_simbol_pos)
                        == last_com_simbol_pos) {
                documentation_classes(doc, position);
            } else {
                documentation_functions(doc, position);
            }
        }

    } catch (const std::exception& e) {
    }
}

void documentation_classes(string& doc, p2i position)
{
    TemplateClassDoc func_doc;
    string name;
    string short_desctiption;
    string description;
    int end_name_pos = doc.find('{', position.second) - 1;
    name.append(doc, position.second + 1, end_name_pos - position.second);

    short_desctiption = append_short_description(doc, position.first);

    int end_short_descr = doc.find('\n', doc.find("#~", position.first)) + 1;

    description = append_description(doc, end_short_descr);

    int position_var = position.second;
    while (doc.find("};", position.second) > doc.find("///", position_var)) {
        string name_var;
        string var_description;
        int position_var = doc.find("///", position_var);
        int end_short_descr = doc.find('\n', position_var);
        var_description.append(
                doc, position_var + 3, end_short_descr - position_var - 3);
        int
    }
}
string append_short_description(string& doc, int position)
{
    string short_desctiption;
    int short_descr_pos = doc.find("#~", position) + 2;
    while (doc[short_descr_pos] != '\n') {
        short_desctiption.push_back(doc[short_descr_pos]);
        short_descr_pos++;
    }
    return short_desctiption;
}
string append_description(string& doc, int end_short_description)
{
    string description;
    int end_comment = doc.find("!*/", end_short_description) - 1;
    description.append(
            doc, end_short_description, end_comment - end_short_description);
    return description;
}

p2i find_comment(string& doc, int last_com_simbol_pos)
{
    int start_comment = doc.find("/*!", last_com_simbol_pos);
    int end_comment = doc.find("!*/", last_com_simbol_pos) + 3;
    end_comment = doc.find_first_not_of(' ', doc.find('\n', end_comment));

    return p2i(start_comment, end_comment);
}

void documentation_functions(string& doc, p2i position)
{
    TemplateFuncDoc func_doc;
    string name;
    string short_desctiption;
    string description;
    int end_name_pos = doc.find(';', position.second);
    name.append(doc, position.second + 1, end_name_pos - position.second);

    short_desctiption = append_short_description(doc, position.first);

    int end_short_descr = doc.find('\n', doc.find("#~", position.first)) + 1;

    description = append_description(doc, end_short_descr);

    func_doc.set_func_info(name, short_desctiption, description);
}

void search_header_files(list<path>& paths, string rel_path_to_folder)
{
    path curr_path = current_path().concat(rel_path_to_folder);
    for (recursive_directory_iterator r_it(curr_path), end; r_it != end;
         ++r_it) {
        if ((r_it->path()).extension() == ".h"
            || (r_it->path()).extension() == ".hpp")
            paths.push_back(r_it->path());
    }
}