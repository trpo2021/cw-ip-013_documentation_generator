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
        long unsigned int number_comment = 0;
        while (1) {
            position = find_comment(doc, number_comment);
            if (position == p2i(-1, 2))
                break;
            number_comment = position.second;
            if (doc.find("Class", number_comment) == number_comment
                || doc.find("Struct", number_comment) == number_comment) {
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
}

p2i find_comment(string& doc, int number_comment)
{
    int start_comment = doc.find("/*!", number_comment);
    int end_comment = doc.find("!*/", number_comment) + 3;
    end_comment = doc.find_first_not_of(' ', end_comment);

    return p2i(start_comment, end_comment);
}

void documentation_functions(string& doc, p2i position)
{
    TemplateFuncDoc func_doc;
    string name;
    string short_desctiption;
    string description;
    int end_name_pos = doc.find(';', position.second);
    name.append(doc, position.second, end_name_pos - position.second);

    int short_descr_pos = doc.find("#~", position.first) + 2;
    while (doc[short_descr_pos != '\n']) {
        short_desctiption.push_back(doc[short_descr_pos]);
        short_descr_pos++;
    }
    short_descr_pos++;
    int end_comment = doc.find("!*/", position.first) - 1;
    description.append(doc, short_descr_pos, end_comment - short_descr_pos);

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