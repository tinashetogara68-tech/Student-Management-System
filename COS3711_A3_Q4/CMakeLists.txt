cmake_minimum_required(VERSION 3.5)

project(COS3711_A3_Q4 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Xml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Xml)

# Project source files
set(PROJECT_SOURCES
    main.cpp
    widget.cpp
    widget.h
    student.h
    student.cpp
    studentlist.h
    studentlist.cpp
    filewriter.h
    filewriter.cpp
)

# Create executable
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)

    qt_add_executable(COS3711_A3_Q4
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )

else()

    if(ANDROID)

        add_library(COS3711_A3_Q4 SHARED
            ${PROJECT_SOURCES}
        )

    else()

        add_executable(COS3711_A3_Q4
            ${PROJECT_SOURCES}
        )

    endif()

endif()

# Link Qt libraries
target_link_libraries(COS3711_A3_Q4 PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Xml
)

# Source directory definition
target_compile_definitions(COS3711_A3_Q4 PRIVATE
    SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}"
)

# Target properties
set_target_properties(COS3711_A3_Q4 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING
        ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Installation
include(GNUInstallDirs)

install(TARGETS COS3711_A3_Q4
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Qt 6 finalization
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(COS3711_A3_Q4)
endif()
