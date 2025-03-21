cmake_minimum_required(VERSION 3.27)
project(DashKing)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY  https://github.com/fmtlib/fmt
        GIT_TAG         10.2.1
)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
    )


FetchContent_MakeAvailable(fmt SFML)

add_executable(DashKing main.cpp
        Player.cpp
        Player.h
        GameObject.cpp
        GameObject.h
        Scene.cpp
        Scene.h
        NPC.cpp
        NPC.h
        PlayerAnimations.cpp
        PlayerAnimations.h
        PlayerInterface.cpp
        PlayerInterface.h
        Platform.cpp
        Platform.h
)

target_link_libraries(DashKing PUBLIC sfml-graphics)
target_link_libraries(DashKing PRIVATE fmt)
target_compile_features(DashKing PRIVATE cxx_std_17)

#to tutaj poniżej ustawia domyślną ścieżkę w cmake-build-debug/bin
if(WIN32)
    add_custom_command(
        TARGET DashKing
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:DashKing>
        VERBATIM)
endif()

install(TARGETS DashKing)