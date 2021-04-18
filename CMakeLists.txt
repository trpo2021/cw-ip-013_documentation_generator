cmake_minimum_required(VERSION 3.16)

project(AutoDoc)

add_compile_options(-Wall -Wextra)

#Build gtest
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/gtest"
"google test"
)

#Main target
add_executable(AutoDoc
src/main.cpp
)

#Test target
add_executable(test_list
test/test_list.cpp
)

#Lib target
add_library(AutoDocLib STATIC
src/AutoDocLib.cpp
src/TemplateClassDoc.cpp
src/TemplateFuncDoc.cpp
src/include/AutoDocLib.hpp
src/include/StructsForDoc.hpp
src/include/TemplateClassDoc.hpp
src/include/TemplateFuncDoc.hpp
)

#Add app-source's to test target 
target_include_directories(
test_list PRIVATE 
"${CMAKE_CURRENT_SOURCE_DIR}/src"
)

#Add link to lib for test target
target_link_libraries(
test_list PRIVATE
gtest 
gtest_main 
AutoDocLib
)

#Add link to lib for main target
target_link_libraries(
AutoDoc PRIVATE
AutoDocLib
)

#Add path to heders
include_directories(
src/include 
gtest/googletest/include
)

