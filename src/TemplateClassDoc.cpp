#include <TemplateClassDoc.hpp>

void TemplateClassDoc::set_class_info(
        string name, string short_desctiption, string description)
{
    this->info.name = name;
    this->info.description = description;
    this->info.short_description = short_desctiption;
}

void TemplateClassDoc::add_method_info(string name, string short_description)
{
    this->methods_info.emplace_back(name, short_description);
}

void TemplateClassDoc::add_var_info(string name, string short_description)
{
    this->vars_info.emplace_back(name, short_description);
}

void TemplateClassDoc::make_documentation(string path)
{
    //Подготовка потокового вывода в файл
    ofstream fileout;
    fileout.open(path + "/Class/" + this->info.name + ".html");

    //Вывод шаблона в файл с подставленными значениями
    fileout << R"!(<!DOCTYPE html>
<html>
    <head>
        <title>Documentation class</title>
        <style type="text/css">
            h1{
                text-align: center;
                font-size: 150%;
                color:darkgoldenrod;
                width: 100%;
                border-style: hidden;
                padding-top: 20px;
                padding-bottom: 20px;
            }
            p {
                text-align: center;
                font-size: large;
                font-family: Arial, Helvetica, sans-serif;
                border-color: black;
                width: 100%;
                border-style: hidden;
            }
            p.field {
                text-align: center;
                font-size: large;
                font-family: Arial, Helvetica, sans-serif;
                color: black;
                width: 100%;
                border-style: hidden;
            }
            p.method{
                text-align: center;
                font-size: large;
                color: black;
                width: 100%;
                border-style: hidden;
            }
            .colortext{
                color: darkgoldenrod
            }
            div {
                border-width: 2px;
                width: 70%;
                margin-left: 15%;
                border-style: solid;
                border: solid black;
                border-radius: 10px;
                background-color: cornsilk;
            }
        </style>
    </head>
    <body>
        <div>
            <p class="g"><a href="../index.html">Вернуться к списку</a></p>
            <h1>Имя класса - краткое описание:<br />)!"
            << this->info.name << "-" << this->info.short_description <<
            R"!(</h1>
            <hr />
            <p><span class="colortext">Полное описание:</span><br />)!"
            << this->info.short_description <<
            R"!(</p><hr />
            <p class="field"><span class="colortext">Поля - краткое описание:</span>)!";

    //Вывод информации о полях
    for (auto it = this->vars_info.begin(); it != this->vars_info.end(); ++it) {
        fileout << R"!(<br />)!" << it->name << " - " << it->short_description
                << "\n";
    }

    fileout << R"!(</p>
            <hr />
            <p class="method"><span class="colortext">Методы - краткое описание:</span>)!";

    //Вывод информации о методах
    for (auto it = this->methods_info.begin(); it != this->methods_info.end();
         ++it) {
        fileout << R"!(<br />)!" << it->name << " - " << it->short_description
                << "\n";
    }

    fileout << R"!( </p>
        </div>
    </body>
</html>)!";

    fileout.close();
}