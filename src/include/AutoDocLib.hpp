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
void auto_doc(string path);
p2i find_comment(string& doc, int number_comment);
void documentation_classes(string& doc, p2i position);
void documentation_functions(string& doc, p2i position);
void search_header_files(list<path>& paths, string rel_path_to_folder = "");
