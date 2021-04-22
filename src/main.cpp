#include <AutoDocLib.hpp>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    //Вычисление пути для сохраниния документации.
    path path_to_save;
    if (argc > 1) {
        path_to_save = argv[1];
    } else {
        path_to_save = std::filesystem::current_path();
    }

    //Создаем директорию
    std::filesystem::create_directory(path_to_save.string() + "/AutoDoc");
    std::filesystem::create_directory(path_to_save.string() + "/AutoDoc/Class");
    std::filesystem::create_directory(path_to_save.string() + "/AutoDoc/Func");
    path_to_save = path_to_save.concat("/AutoDoc");

    // находим все заголовочные файлы
    list<path> files_for_docing;
    write_header_file_paths(files_for_docing);

    //Документируем все необходимые файлы.
    for (auto it = files_for_docing.begin(); it != files_for_docing.end();
         ++it) {
        if (is_documenting(*it)) {
            auto_doc(*it, path_to_save);
            cout << "file " << *it << " documenting" << endl;
        }
    }

    // TODO добавить вывод файла index.html для связки всех файлов.
}