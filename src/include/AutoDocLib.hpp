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
void auto_doc(string path, string path_for_safe);
p2i find_comment(string& doc, int number_comment);
void documentation_classes(string& doc, p2i position, string path_for_safe);
void documentation_functions(string& doc, p2i position, string path_for_safe);
void search_header_files(list<path>& paths, string rel_path_to_folder = "");
bool is_documenting(path file_path);
string append_description(string& doc, int end_short_description);
string append_short_description(string& doc, int position);
