# Generated from src.pro.

#####################################################################
## qtadvanceddocking Generic Library:
#####################################################################

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

add_definitions(-DADS_SHARED_EXPORT -DQT_DEPRECATED_WARNINGS)

# Resources:
set(ads_resource_files
    "images/close-button-disabled.svg"
    "images/close-button-focused.svg"
    "images/close-button.svg"
    "images/detach-button-disabled.svg"
    "images/detach-button.svg"
    "images/maximize-button-focused.svg"
    "images/maximize-button.svg"
    "images/restore-button-focused.svg"
    "images/restore-button.svg"
    "images/tabs-menu-button.svg"
    "stylesheets/default.css"
    "stylesheets/default_linux.css"
    "stylesheets/focus_highlighting.css"
    "stylesheets/focus_highlighting_linux.css"
)

file(GLOB_RECURSE RESOURCES *.qrc)
set(SOURCES ${SOURCES} ${RESOURCES})

#### Keys ignored in scope 1:.:.:src.pro:<TRUE>:
# ADS_OUT_ROOT = "../../../../"
# DISTFILES = <EMPTY>
# INSTALLS = "headers" "target"
# TEMPLATE = "lib"
# headers.files = "$$HEADERS"
# headers.path = "$$PREFIX/include"
# target.path = "$$PREFIX/lib"

## Scopes:
#####################################################################

IF(GCC AND WIN32)
    add_compile_options(-Wall -Wextra -pedantic)
ENDIF()

IF(MSVC)
    add_compile_options(/utf-8)
ENDIF()

IF(UNIX AND NOT APPLE)
    set(SOURCES

            ${SOURCES}
            linux/FloatingWidgetTitleBar.cpp linux/FloatingWidgetTitleBar.h

        )

    find_package(Qt5 COMPONENTS X11Extras REQUIRED)
    include(FindX11)
ENDIF()

add_library(qtadvanceddocking SHARED
        DockAreaTabBar.cpp DockAreaTabBar.h
        DockAreaTitleBar.cpp DockAreaTitleBar.h DockAreaTitleBar_p.h
        DockAreaWidget.cpp DockAreaWidget.h
        DockComponentsFactory.cpp DockComponentsFactory.h
        DockContainerWidget.cpp DockContainerWidget.h
        DockFocusController.cpp DockFocusController.h
        DockManager.cpp DockManager.h
        DockOverlay.cpp DockOverlay.h
        DockSplitter.cpp DockSplitter.h
        DockWidget.cpp DockWidget.h
        DockWidgetTab.cpp DockWidgetTab.h
        DockingStateReader.cpp DockingStateReader.h
        ElidingLabel.cpp ElidingLabel.h
        FloatingDockContainer.cpp FloatingDockContainer.h
        FloatingDragPreview.cpp FloatingDragPreview.h
        IconProvider.cpp IconProvider.h
        ads_globals.cpp ads_globals.h
        ${SOURCES}
        )

target_link_libraries(qtadvanceddocking Qt5::X11Extras Qt5::Widgets)

target_include_directories(qtadvanceddocking PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#### Keys ignored in scope 6:.:.:src.pro:PREFIX_ISEMPTY:
# PREFIX = "../installed"
