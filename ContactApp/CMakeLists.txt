cmake_minimum_required(VERSION 3.5)

project(ContactApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)


set(PROJECT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/contact.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/contactdatabase.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/task.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/taskservice.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/contactservice.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/contact.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/contactdatabase.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/task.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/taskservice.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/contactservice.h
)

set(UIS
    ${CMAKE_CURRENT_SOURCE_DIR}/UI/login.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/UI/displayContacts.ui
    ${CMAKE_CURRENT_SOURCE_DIR}/UI/home.ui
)

set(RESOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/resources.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ContactApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        src/sqlite3.h

        UI/login.h UI/login.cpp UI/login.ui UI/displayContacts.ui
        src/contact.h src/contact.cpp src/contactdatabase.h src/contactdatabase.cpp src/task.h src/task.cpp src/taskservice.h src/taskservice.cpp src/contactservice.h src/contactservice.cpp
        src/main.cpp src/displayContacts.cpp src/displayContacts.h
        UI/home.h UI/home.cpp UI/home.ui
        resources.qrc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ContactApp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ContactApp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ContactApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Include directory for SQLite3 header
include_directories(${PROJECT_SOURCE_DIR}/include)

# Link Against Qt Libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)

target_link_libraries(ContactApp PRIVATE ${PROJECT_SOURCE_DIR}/lib/sqlite3.lib)

install(DIRECTORY resources/fonts/ DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/resources/fonts)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ContactApp)
endif()
set_target_properties(ContactApp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ContactApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ContactApp)
endif()


