#pragma once
#include <StructsForDoc.hpp>
#include <TemplateClassDoc.hpp>
#include <TemplateFuncDoc.hpp>
#include <exception>
#include <fstream>
typedef pair<int, int> p2i;
void auto_doc(string path);
p2i find_comment(string& doc, int number_comment);
void documentation_classes(string& doc, int position);
void documentation_functions(string& doc, int position);