# logger
add_library(logger
    core/logger/logger.hpp
    core/logger/logger.cpp
)

# config
add_library(config
    core/config/config.hpp
    core/config/config.cpp
    core/config/config_parser.hpp
    core/config/config_parser.cpp
)

add_dependencies(config logger)
target_include_directories(config PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/core/logger)
target_link_libraries(config logger)