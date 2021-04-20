#include <AutoDocLib.hpp>
using namespace std;

void auto_doc(string path)
{
    ifstream file;
    file.open(path, ios::binary);
    try {
        string doc;
        char symbol;
        while (!file.eof()) {
            file >> symbol;
            doc += symbol;
        }
        file.close();
        p2i position;
        do {
            position = find_comment(doc, i);
        } while (position != p2i(-1, -1));

    } catch (const std::exception& e) {
    }
}

p2i find_comment(string& doc, int number_comment)
{
    int start_comment = doc.find("/*", number_comment);
    int end_comment = doc.find("*/", number_comment);

    return p2i(start_comment, end_comment);
}