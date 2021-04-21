#include <AutoDocLib.hpp>

namespace fs = std::filesystem;

void auto_doc(string path)
{
    ifstream file;
    file.open(path);
    try {
        string doc;
        char symbol;
        while (!file.eof()) {
            file >> symbol;
            doc += symbol;
        }
        file.close();
        p2i position;
        long unsigned int number_comment = 0;
        do {
            position = find_comment(doc, number_comment);
            number_comment = position.second + 1;
            if (doc.find("Class", number_comment) == number_comment
                || doc.find("Struct", number_comment) == number_comment) {
            } else {
            }

        } while (position != p2i(-1, -1));

    } catch (const std::exception& e) {
    }
}

p2i find_comment(string& doc, int number_comment)
{
    int start_comment = doc.find("/*", number_comment);
    int end_comment = doc.find("*/", number_comment);

    return p2i(start_comment, end_comment);
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