project(datatypes_test)
find_package(Qt5 COMPONENTS Core Test Gui REQUIRED)

include_directories(../../inc/datatypes)

add_executable(datatypes_test
        ../../src/datatypes/STTimecode.cpp
        ../../inc/datatypes/STTimecode.h
        tst_datatypes_test.cpp)
target_link_libraries(datatypes_test Qt5::Core Qt5::Test Qt5::Gui)
add_test(DataTypesTest datatypes_test)
