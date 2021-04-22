#include <AutoDocLib.hpp>
#include <iostream>

// Правила наименований:

// lower_case_with_underscores: переменные, функции

// UpperCamelCase: структуры, объединения, перечисления

// UPPER_CASE_WITH_UNDERSCORES: макросы

// Общие рекомендации:

// Не создавать композированных классов

// Использовать protected вместо public (Необходимо для тестирования)

using namespace std;

int main(int argc, char* argv[])
{
    path path_to_save;
    if (argc > 1) {
        path_to_save = argv[1];
        path_to_save.concat("/AutoDoc");
    } else {
        path_to_save = "./AutoDoc";
    }

    list<path> files_for_docing;
    search_header_files(files_for_docing);

    for (auto it = files_for_docing.begin(); it != files_for_docing.end();
         ++it) {
        if (is_documenting(*it)) {
            auto_doc(*it, path_to_save);
            cout << "file " << *it << " documenting" << endl;
        }
    }
}