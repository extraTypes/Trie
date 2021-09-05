set(TARGET_NAME Trie)

add_library(
        ${TARGET_NAME}
        INTERFACE
        trie.hpp
)

target_include_directories(${TARGET_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})