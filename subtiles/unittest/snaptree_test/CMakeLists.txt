project(snaptree_test)

include_directories(../../inc/datatypes)
find_package(Qt5 COMPONENTS Core Test Gui REQUIRED)
add_executable(snaptree_test
        snaptree_test.cpp
        ../../inc/datatypes/STSnapTree.h
        ../../inc/datatypes/STTimecode.h
        ../../inc/datatypes/STDialog.h
        ../../src/datatypes/STSnapTree.cpp
        ../../src/datatypes/STTimecode.cpp
        ../../src/datatypes/STDialog.cpp
        )
target_link_libraries(snaptree_test Qt5::Core Qt5::Test Qt5::Gui)
add_test(SnapTreeTest snaptree_test)
