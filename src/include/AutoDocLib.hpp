#pragma once

#include <TemplateClassDoc.hpp>
#include <TemplateFuncDoc.hpp>

#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;
using namespace std::filesystem;

typedef pair<int, int> p2i;

//Создать документацию по коментариям в файле.
void auto_doc(string path, string save_path);
// TODO Предусмотреть работу в случае, если служебный комментарий содержит
// невалидный синтаксис.

//Записать пути до заголовочных файлов в заданной дирректории.
void write_header_file_paths(list<path>& paths, string rel_path_to_folder = "");

//Проверить, необходимо ли документировать файл.
bool is_documenting(path file_path);

//Найти границы коментариев.
p2i get_com_border(string& buff, int left_border);

//Найти границы определения класса.
p2i get_class_border(string& buff, int first_border);

//Получить описание из комментария с заданным диапозонами.
string get_description(string& buff, p2i border);
// TODO Предусмотреть работу в случае, если описание пусто.

//Получить краткое описание из комментария с заданным диапозоном.
string get_short_description(string& doc, p2i border);
// TODO Предусмотреть работу в случае, если краткое описание пусто.