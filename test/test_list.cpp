#include <AutoDocLib.hpp>
#include <StructsForDoc.hpp>
#include <TemplateClassDoc.hpp>
#include <gtest.h>

namespace fs = std::filesystem;

TEST(AutoDocLib, search_header_files)
{
    list<fs::path> paths;
    fs::path A("./example_folder/A.h"), B("./example_folder/B.hpp");
    bool a = 0, b = 0, c = 0;

    search_header_files(paths, "/test");
    a = A.compare(paths.front());
    b = B.compare(paths.back());
    paths.pop_back();
    paths.pop_front();
    c = paths.empty();

    EXPECT_TRUE(a);
    EXPECT_TRUE(b);
    EXPECT_TRUE(c);
}

TEST(AutoDocLib, find_comment)
{
    p2i EXP(0, 13);
    p2i REAL;
    ifstream file;
    file.open("./test/example_folder/A.h");

    ASSERT_TRUE(file.is_open());

    string doc;
    getline(file, doc, '\0');
    file.close();
    REAL = find_comment(doc, 0);

    ASSERT_EQ(EXP, REAL);
}

TEST(AutoDocLib, is_documenting)
{
    bool a = 0;
    bool b = 0;

    a = is_documenting("./test/example_folder/A.h");
    b = is_documenting("./test/example_folder/B.hpp");

    ASSERT_FALSE(a);
    ASSERT_TRUE(b);
}