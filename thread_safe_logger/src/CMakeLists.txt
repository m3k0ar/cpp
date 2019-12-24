project(logger)

#set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE C CXX)
add_library(${PROJECT_NAME}
            empty.cpp
           utils.h
)
