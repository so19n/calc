cmake_minimum_required(VERSION 3.16)

project(untitled1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_add_resources(RESOURCES resources.qrc)

qt_add_executable(appuntitled1
    main.cpp
    processcalculating.cpp
    ${RESOURCES}
)

qt_add_qml_module(appuntitled1
    URI untitled1
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES Display.qml
        QML_FILES Key.qml
        QML_FILES Buttons.qml
        QML_FILES Status.qml
        RESOURCES resources.qrc
        SOURCES
        SOURCES
        SOURCES
        SOURCES
        SOURCES processcalculating.h processcalculating.cpp
        RESOURCES qml.qrc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appuntitled1 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appuntitled1
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appuntitled1
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appuntitled1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
