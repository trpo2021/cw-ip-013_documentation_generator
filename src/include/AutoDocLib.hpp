#pragma once
#include <StructsForDoc.hpp>
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
void auto_doc(string path, string save_path);
p2i find_comment(string& buff, int left_border);
void documentation_classes(string& buff, p2i border, string save_path);
void documentation_functions(string& buff, p2i border, string save_path);
void search_header_files(list<path>& paths, string rel_path_to_folder = "");
bool is_documenting(path file_path);
string get_description(string& buff, p2i border);
string get_short_description(string& doc, p2i border);
p2i find_class_border(string& buff, int first_border);