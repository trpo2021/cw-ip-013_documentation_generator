#include <AutoDocLib.hpp>
#include <iostream>

using namespace std;
using namespace filesystem;

void syntax_help();

int main(int argc, char* argv[])
{
    list<string> class_names;
    list<string> func_names;
    list<path> files_for_docing;

    //Вычисление пути для сохраниния документации.
    path path_to_save;

    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-')
            if (argv[i][1] == 'h') {
                syntax_help();
                return 0;
            }
    }

    if (argc == 2)
        path_to_save = argv[1];
    else {
        cout << argv[0] << " path_to_save" << endl;
        return 1;
    }
    path_to_save = path_to_save / "AutoDoc";

    //Удаляем старую AutoDoc дирректорию, если она существовала.
    remove_all(path_to_save);

    //Создаем директорию
    try {
        create_directory(path_to_save);
        create_directory(path_to_save / "Class");
        create_directory(path_to_save / "Func");
    } catch (exception& err) {
        cout << err.what() << endl;
        cout << argv[0] << " path_to_save" << endl;
        return 2;
    }

    // находим все заголовочные файлы
    write_header_file_paths(files_for_docing);

    //Документируем все необходимые файлы.
    try {
        for (auto it = files_for_docing.begin(); it != files_for_docing.end();
             ++it)
            if (is_documenting(*it)) {
                try {
                    auto_doc(*it, path_to_save, class_names, func_names);
                    cout << "file " << *it << "is documented" << endl;
                } catch (MyException& excep) {
                    cout << excep.what() << endl;
                    syntax_help();
                    return 1;
                }
            }
    } catch (MyException& err) {
        cout << err.what() << endl;
        return 3;
    }
    //создание index.html связывающего весь сайт с документацией
    add_index_html(path_to_save, class_names, func_names);
}

void syntax_help()
{
    cout << R"!(
The first line of the header file must contain a comment: //$AutoDoc

All service comments for classes and functions should be placed above them,
without empty lines, otherwise the program may not work correctly:

    /*!
    #~ short description
    description
    ...
    !*/
    class/func{}()
    
* /*!...!*/ - Service Comment boundaries.

* #~ - The short description designation, the entire contents of the line are placed
       in the "Short Description" section of the documentation page.

* All remaining text contained in /*!...!*/ is placed in the section " Detailed description”

For class members:

* /// - The next line is placed in the documentation after the field signature in the same
        line.(only for fields)

* //# - The next line is placed in the documentation after the signature of the class methods
        in the same line.(only a brief description of the method)
)!";
}