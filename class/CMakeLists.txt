cmake_minimum_required(VERSION 3.16)

project(class LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(class
  main.cpp
  animal.h
  animal.cpp
  laptop.h laptop.cpp
  mamal.h mamal.cpp
  adog.h adog.cpp
  acat.h acat.cpp
  ToasterInterface.h
  FreezerInterface.h
  MicrowaveInterface.h
  appliance.h appliance.cpp
)
target_link_libraries(class Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS class
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
