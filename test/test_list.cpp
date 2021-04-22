#include <AutoDocLib.hpp>
#include <StructsForDoc.hpp>
#include <TemplateClassDoc.hpp>
#include <gtest.h>

namespace fs = std::filesystem;

using namespace fs;

TEST(AutoDocLib, write_header_file_paths)
{
    // Arrange
    list<fs::path> paths;

    path a(current_path().string()
           + "/test/example_folder/write_header_file_paths/A.h");
    path b(current_path().string()
           + "/test/example_folder/write_header_file_paths/B.hpp");
    path c(current_path().string()
           + "/test/example_folder/write_header_file_paths/subdir/C.hpp");

    bool a_found = 0, b_found = 0, c_found = 0;
    const long unsigned int EXP_SIZE = 3;
    long unsigned int REAL_SIZE;

    // Act
    write_header_file_paths(
            paths, "/test/example_folder/write_header_file_paths");

    for (auto it = paths.begin(); it != paths.end(); ++it) {
        if ((*it) == a)
            a_found = true;

        if ((*it) == b)
            b_found = true;

        if ((*it) == c)
            c_found = true;
    }

    REAL_SIZE = paths.size();

    // Assert
    EXPECT_EQ(REAL_SIZE, EXP_SIZE);
    EXPECT_TRUE(a_found);
    EXPECT_TRUE(b_found);
    EXPECT_TRUE(c_found);
}

TEST(AutoDocLib, get_com_border)
{
    // Arrange
    p2i exp_border_first_com(12, 32);
    p2i real_border_first_com;
    p2i exp_border_second_com(59, 66);
    p2i real_border_second_com;
    p2i exp_border_if_not_com(-1, -1);
    p2i real_border_if_not_com;
    ifstream file;
    string doc;
    file.open("./test/example_folder/get_com_border/A.h");
    ASSERT_TRUE(file.is_open());
    getline(file, doc, '\0');
    file.close();

    // Act
    real_border_first_com = get_com_border(doc, 0);
    real_border_second_com = get_com_border(doc, real_border_first_com.second);
    real_border_if_not_com = get_com_border(doc, real_border_second_com.second);

    // Assert
    EXPECT_EQ(exp_border_first_com, real_border_first_com);
    EXPECT_EQ(exp_border_second_com, real_border_second_com);
    EXPECT_EQ(exp_border_if_not_com, real_border_if_not_com);
}

TEST(AutoDocLib, is_documenting)
{
    // Arrange
    bool is_not_at_first_string = 0;
    bool is_at_first_string = 0;
    bool is_not = 0;

    // Act
    is_not_at_first_string
            = is_documenting("./test/example_folder/is_documenting/A.hpp");
    is_at_first_string
            = is_documenting("./test/example_folder/is_documenting/B.hpp");
    is_not = is_documenting("./test/example_folder/is_documenting/C.hpp");

    // Assert
    EXPECT_FALSE(is_not_at_first_string);
    EXPECT_TRUE(is_at_first_string);
    EXPECT_FALSE(is_not);
}