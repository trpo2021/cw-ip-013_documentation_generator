#include <AutoDocLib.hpp>

void documentation_classes(string& buff, p2i border, string save_path);

void documentation_functions(string& buff, p2i border, string save_path);

void auto_doc(string path, string save_path)
{
    ifstream file;
    p2i border(0, 0);
    string buff;
    long unsigned int temp_pos;

    //Записываем файл в строку.
    file.open(path);
    getline(file, buff, '\0');
    file.close();

    //Поиск и обработка всех служебных коментариев в файле.
    while (true) {
        //Находим границы очередного коментария.
        border = get_com_border(buff, border.second);
        if (border.first == -1)
            break;

        //Находим первый символ сигнатуры сущности.
        temp_pos = buff.find('\n', border.second) + 1;
        temp_pos = buff.find_first_not_of(' ', temp_pos);

        //Вызываем соответствующую функцию для документирования сущности.
        if (buff.find("class", temp_pos) == temp_pos
            || buff.find("struct", temp_pos) == temp_pos)
            documentation_classes(buff, border, save_path);
        else
            documentation_functions(buff, border, save_path);
    }
}

void documentation_classes(string& buff, p2i border, string save_path)
{
    TemplateClassDoc class_doc;
    string name;
    string short_desctiption;
    string description;
    int temp_pos;
    p2i class_border;

    //Находим позицию первого символа сигнатуры класса.
    temp_pos = buff.find('\n', border.second) + 1;
    temp_pos = buff.find_first_not_of(' ', temp_pos);

    //Считываем сигнатуру функции.
    while (buff[temp_pos] != '{') {
        name += buff[temp_pos];
        temp_pos++;
    }

    //Считываем краткое описание
    short_desctiption = get_short_description(buff, border);

    // Cчитываеем описание
    description = get_description(buff, border);

    //Находим границы тела класса или структуры
    class_border = get_class_border(buff, temp_pos);

    //Заполняем информацию о классе
    class_doc.set_class_info(name, short_desctiption, description);

    //Ищем все методы и добавляем информацию о них в класс документации.
    temp_pos = buff.find("//#", class_border.first);
    while (temp_pos < class_border.second && temp_pos != -1) {
        name.clear();
        short_desctiption.clear();

        //Считывание имени метода.
        for (int i = temp_pos - 1; buff[i] != '\n'; i--) {
            if (buff[i] != ' ')
                name = buff[i] + name;
        }

        // Cчитывание краткого описания.
        for (int i = temp_pos + 3; buff[i] != '\n'; i++) {
            if (buff[i] != ' ')
                short_desctiption += buff[i];
        }

        //Добавляем запись о методе в класс
        class_doc.add_method_info(name, short_desctiption);

        temp_pos = buff.find("//#", temp_pos + 1);
    }

    //Ищем все поля и добавляем информацию о них в класс документации.
    temp_pos = buff.find("///", class_border.first);
    while (temp_pos < class_border.second && temp_pos != -1) {
        name.clear();
        short_desctiption.clear();

        //Считывание имени поля.
        for (int i = temp_pos - 1; buff[i] != '\n'; i--) {
            if (buff[i] != ' ')
                name = buff[i] + name;
        }

        //Считывание краткого описания.
        for (int i = temp_pos + 3; buff[i] != '\n'; i++) {
            if (buff[i] != ' ')
                short_desctiption += buff[i];
        }

        //Добавляем запись о поле в класс.
        class_doc.add_var_info(name, short_desctiption);

        temp_pos = buff.find("///", temp_pos + 1);
    }

    //Сохраняем файл документации.
    class_doc.make_documentation(save_path);
}

string get_short_description(string& buff, p2i border)
{
    string short_description;

    //Поиск начала краткого описания.
    int short_descr_pos = buff.find("#~", border.first) + 2;

    //Считывание краткого описания.
    while (buff[short_descr_pos] != '\n' && short_descr_pos < border.second)
        short_description += buff[short_descr_pos++];

    return short_description;
}

string get_description(string& buff, p2i border)
{
    string description;

    //Поиск начала описания.
    int temp_pos = buff.find("#~", border.first);
    temp_pos = buff.find('\n', temp_pos) + 1;

    // Cчитывание краткого описания.
    while (temp_pos < border.second - 2)
        description += buff[temp_pos++];

    return description;
}

//Возвращает пару,позиции границ первого коментария (включая !*/),
//идущего после left_border.
p2i get_com_border(string& buff, int left_border)
{
    int start_comment = buff.find("/*!", left_border);
    int end_comment = buff.find("!*/", left_border) + 2;
    return p2i(start_comment, end_comment);
}

p2i get_class_border(string& buff, int first_border)
{
    int pos = first_border + 1;
    int count_border = 1;
    while (count_border != 0) {
        if (buff[pos] == '}')
            count_border--;
        if (buff[pos] == '{')
            count_border++;
        pos++;
    }
    return p2i(first_border, pos);
}

void documentation_functions(string& buff, p2i border, string save_path)
{
    TemplateFuncDoc func_doc;
    string name;
    string short_desctiption;
    string description;
    int temp_pos;

    //Находим позицию первого симфола сигнатуры функции.
    temp_pos = buff.find('\n', border.second) + 1;
    temp_pos = buff.find_first_not_of(' ', temp_pos);

    //Считываем сигнатуру функции.
    while (buff[temp_pos] != ';') {
        name += buff[temp_pos++];
    }

    //Считываем краткое описание
    short_desctiption = get_short_description(buff, border);

    // Cчитываеем описание
    description = get_description(buff, border);

    func_doc.set_func_info(name, short_desctiption, description);

    //Создаем файл документации.
    func_doc.make_documentation(save_path);
}

void write_header_file_paths(list<path>& paths, string rel_path_to_folder)
{
    path curr_path = current_path().concat(rel_path_to_folder);

    //Рекурсивно перебираем все файлы, добовляя в список нужные.
    for (recursive_directory_iterator r_it(curr_path), end; r_it != end;
         ++r_it) {
        if ((r_it->path()).extension() == ".h"
            || (r_it->path()).extension() == ".hpp")
            paths.push_back(r_it->path());
    }
}

//Проверяет, содержит ли файл //$AutoDoc
bool is_documenting(path file_path)
{
    string input;
    ifstream file(file_path);
    if (!file.is_open())
        return 0;

    file >> input;

    return input == "//$AutoDoc";
}