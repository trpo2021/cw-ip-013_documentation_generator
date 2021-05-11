#pragma once

#include <TemplateClassDoc.hpp>
#include <TemplateFuncDoc.hpp>

#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <list>

class MyException : public exception {
private:
    const char* m_error;

public:
    MyException(const char* m_error) : m_error(m_error){};

    const char* what() const noexcept override
    {
        return m_error;
    };
};

using namespace std;
using namespace std::filesystem;

typedef pair<int, int> p2i;

//Создать документацию по коментариям в файле.
void auto_doc(
        string path,
        string save_path,
        list<string>& class_names,
        list<string>& func_names);

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

//Получить краткое описание из комментария с заданным диапозоном.
string get_short_description(string& doc, p2i border);

//Получить имя сущности.
string get_name(string& buff, int& start_pos);

//Добавляет файл index.html связывающий все страницы с документацией
void add_index_html(
        string path, list<string>& class_names, list<string>& func_names);