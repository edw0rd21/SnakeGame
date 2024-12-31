cmake_minimum_required(VERSION 3.10)

project(Snake-Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/)

include_directories(include)

add_subdirectory(vendor/SFML)

file(GLOB SOURCE_FILES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

set(SFML_DLLS
    "${CMAKE_SOURCE_DIR}/vendor/SFML/bin/sfml-graphics-2.dll"
    "${CMAKE_SOURCE_DIR}/vendor/SFML/bin/sfml-window-2.dll"
    "${CMAKE_SOURCE_DIR}/vendor/SFML/bin/sfml-system-2.dll"
)

set(ASSET_PATH "${CMAKE_SOURCE_DIR}/AssetFile")

 add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${SFML_DLLS}
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${ASSET_PATH}
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
)
