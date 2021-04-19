#include <string>

using namespace std;

struct InfoForDoc {
    string name;
    string short_description;
    string description;
};

struct MemberInfo {
    MemberInfo(string name, string short_description)
    {
        this->name = name;
        this->short_description = short_description;
    }

    string name;
    string short_description;
};