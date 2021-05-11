#include <AutoDocLib.hpp>
#include <iostream>

using namespace std;
using namespace filesystem;

int main(int argc, char* argv[])
{
    list<string> class_names;
    list<string> func_names;
    list<path> files_for_docing;

    //Вычисление пути для сохраниния документации.
    path path_to_save;

    /* TODO #19 Добавить вывод сообщения с помощью в консоль, в случае, если
     * пользователь ввел некоректные параметры.*/
    if (argc == 2)
        path_to_save = argv[1];
    else
        return 1;

    /*TODO #20 Добавить проверку на существования для путя введенного
    пользователем.
     */

    path_to_save = path_to_save / "AutoDoc";

    //Удаляем старую AutoDoc дирректорию, если она существовала.
    remove_all(path_to_save);

    //Создаем директорию
    create_directory(path_to_save);
    create_directory(path_to_save / "Class");
    create_directory(path_to_save / "Func");

    // находим все заголовочные файлы
    write_header_file_paths(files_for_docing);

    //Документируем все необходимые файлы.
    for (auto it = files_for_docing.begin(); it != files_for_docing.end(); ++it)
        if (is_documenting(*it)) {
            try {
                auto_doc(*it, path_to_save, class_names, func_names);
                cout << "file " << *it << "is documented" << endl;
            } catch (string error_massage) {
                cout << error_massage;
            }
        }

    //создание index.html связывающего весь сайт с документацией
    add_index_html(path_to_save, class_names, func_names);
}