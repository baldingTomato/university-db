cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FLAGS_COMMON -Wall)
set(FLAGS_LINUX -Wextra -Werror -Wconversion -pedantic)
set(FLAGS_WINDOWS /W4 /WX /we)

set(SOURCES src/database.cpp src/student.cpp)

project(university-db)

add_executable(${PROJECT_NAME} src/main.cpp ${SOURCES})

if(UNIX)
    target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS_COMMON} ${FLAGS_LINUX})
elseif(WIN32)
    target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS_COMMON} ${FLAGS_WINDOWS})
endif()


