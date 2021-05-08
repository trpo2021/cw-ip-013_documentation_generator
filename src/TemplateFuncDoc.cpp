#include <TemplateFuncDoc.hpp>

#include <StructsForDoc.hpp>

void TemplateFuncDoc::make_documentation(string path) //покрыть тестами.
{
    ofstream fout;
    ifstream fin;
    fout.open(path + "/Func/" + this->info.name + ".html");
    fout << R"!(<!DOCTYPE html>
<html>
    <head>
        <title>Documentation function</title>
        <style type="text/css">
            h2{
                text-align: center;
                font-size: 150%;
                color: darkgoldenrod;
                width: 100%;
                border-style: hidden;
                padding-bottom: 20px;
                padding-top: 20px;
            }
            p{
                text-align: center;
                font-size: large;
                font-family: Arial, Helvetica, sans-serif;
                border-color: black;
                width: 100%;
                border-style: hidden;
            }
            .colortext{
                color:darkgoldenrod;
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
            <h2>Func:<br />)!"
         << this->info.name << "-" << this->info.short_description <<
            R"!(</h2>
            <hr />
            <p><span class="colortext">Desctiption:</span><br />)!"
         << this->info.description <<
            R"!(</p>
        </div>
    </body>
</html>)!";
    fout.close();
}

void TemplateFuncDoc::set_func_info(
        string name, string short_desctiption, string description)
{
    this->info.name = name;
    this->info.short_description = short_desctiption;
    this->info.description = description;
}