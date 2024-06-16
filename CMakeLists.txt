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
FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.2  # You can specify a version tag here
)

FetchContent_MakeAvailable(fmt SFML nlohmann_json)

add_executable(DashKing main.cpp
        Utils.cpp
        Utils.h
        Player.h
        Player.cpp
        MapsConnector.cpp
        MapsConnector.h
        GameObject.cpp
        GameObject.h
        Platform.cpp
        Platform.h
        Collectible.cpp
        Collectible.h
        Collectible.cpp
        Platform.cpp
        Spike.cpp
        Spike.h
        Map.cpp
        Map.h
        Enemy.cpp
        Enemy.h
        MapsConnector.cpp
        MainMenu.cpp
        MainMenu.h
        Shop.cpp
        Shop.h
)

target_link_libraries(DashKing PUBLIC sfml-graphics)
target_link_libraries(DashKing PRIVATE fmt nlohmann_json::nlohmann_json)
target_compile_features(DashKing PRIVATE cxx_std_17)

# Copy OpenAL DLL on Windows
if(WIN32)
    add_custom_command(
            TARGET DashKing
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:DashKing>
            VERBATIM)
endif()

install(TARGETS DashKing)
