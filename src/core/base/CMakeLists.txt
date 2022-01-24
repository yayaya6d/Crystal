# logger
add_library(logger
    logger/logger.hpp
    logger/logger.cpp
)

# config
add_library(config
    config/config.hpp
    config/config.cpp
    config/config_parser.hpp
    config/config_parser.cpp
)

add_dependencies(config logger)
target_include_directories(config PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/logger)
target_link_libraries(config logger)