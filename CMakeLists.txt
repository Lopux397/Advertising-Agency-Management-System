cmake_minimum_required(VERSION 3.19)
project(Advertising-Agency-Management-System LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

qt_add_executable(Advertising-Agency-Management-System
    WIN32 MACOSX_BUNDLE
    sources/main.cpp
    sources/mainwindow.cpp
    headers/mainwindow.h
    forms/mainwindow.ui
    headers/client.h
    sources/client.cpp
    headers/specialist.h
    sources/specialist.cpp
    headers/budget.h
    sources/budget.cpp
    headers/advertisingCampaign.h
    sources/advertisingCampaign.cpp
    headers/date.h
    sources/date.cpp
    headers/service.h
    sources/service.cpp
    headers/designService.h
    sources/designService.cpp
)

target_link_libraries(Advertising-Agency-Management-System
    PRIVATE
        Qt::Core
        Qt::Widgets
)

target_compile_definitions(Advertising-Agency-Management-System PRIVATE
    QT_NEEDS_QMAIN
)

install(TARGETS Advertising-Agency-Management-System
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Advertising-Agency-Management-System
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
