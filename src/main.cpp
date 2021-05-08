#include <AutoDocLib.hpp>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    list<string> class_names;
    list<string> func_names;

    //Вычисление пути для сохраниния документации.
    path path_to_save;

    if (argc == 2)
        path_to_save = argv[1];
    else
        return 1;

    path_to_save = path_to_save.concat("/AutoDoc");
    remove_all(path_to_save);
    //Создаем директорию
    std::filesystem::create_directory(path_to_save.string());
    std::filesystem::create_directory(path_to_save.string() + "/Class");
    std::filesystem::create_directory(path_to_save.string() + "/Func");

    // находим все заголовочные файлы
    list<path> files_for_docing;
    write_header_file_paths(files_for_docing);

    //Документируем все необходимые файлы.
    for (auto it = files_for_docing.begin(); it != files_for_docing.end();
         ++it) {
        if (is_documenting(*it)) {
            try {
                auto_doc(*it, path_to_save, class_names, func_names);
                cout << "file " << *it << " documenting" << endl;
            } catch (string a) {
                cout << a;
            }
        }
    }

    add_index_html(path_to_save, class_names, func_names);
}