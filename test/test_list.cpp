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