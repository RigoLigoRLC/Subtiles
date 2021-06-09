# Subtiles meta project

# Sources
add_subdirectory(src)

# Unit tests
add_subdirectory(unittest)

# UIC files to look at
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Locate Qt
find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

# Qt Designer UI files for Subtiles Application
set(CMAKE_AUTOUIC_SEARCH_PATHS ui)

# Qt Resource files for Subtiles Application
set(APP_QRCFILE
        resources/largeimgs.qrc
        resources/theme.qrc
        resources/info.qrc
)

# FUCK AUTOUIC
qt_wrap_ui(APP_UIFILE
        ui/guest_uistyleshow.ui)

# App source files
set(APP_SRCFILE

        src/main.cpp

        inc/app/command.h src/app/command.cpp
        inc/app/commander.h src/app/commander.cpp
        inc/app/host.h src/app/host.cpp
        inc/app/mainframe.h src/app/mainframe.cpp
        inc/app/abstractguest.h

        inc/datatypes/STDataReader.h src/datatypes/STDataReader.cpp
        inc/datatypes/STDataOperator.h src/datatypes/STDataOperator.cpp
        inc/datatypes/STDialog.h src/datatypes/STDialog.cpp
        inc/datatypes/STTrack.h src/datatypes/STTrack.cpp
        inc/datatypes/STTimecode.h src/datatypes/STTimecode.cpp

        inc/guests/timeline.h src/guests/timeline.cpp
        inc/guests/uistyleshow.h src/guests/uistyleshow.cpp

        inc/gui/mainwindow.h src/gui/mainwindow.cpp
        
        inc/graphics/dialogtile.h src/graphics/dialogtile.cpp
        inc/graphics/timelineview.h src/graphics/timelineview.cpp

        inc/utils/convenience.h
        inc/utils/color.h

        inc/datatypes/STSnapTree.h

        src/datatypes/STSnapTree.cpp)

# All source code for Subtiles Application
set(APP_SOURCE
        ${APP_SRCFILE}
        ${APP_UIFILE}
        ${APP_QRCFILE})

add_executable(subtiles ${APP_SOURCE})
target_link_libraries(subtiles Qt5::Core Qt5::Widgets qtadvanceddocking)

target_include_directories(subtiles PRIVATE src/thirdparty/ads/src)
