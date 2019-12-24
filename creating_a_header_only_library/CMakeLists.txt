### setting up the project ###
cmake_minimum_required( VERSION 3.12 )

project( "SI" VERSION 1.0.1
              DESCRIPTION "A header only c++ library that provides 
                           type safety and user defined literals for 
                           handling pyhsical values defined 
                           in the International System of Units." 
        )      

# provides us with a set of variables containing installation directories 
# for various artifacts. 
# The variables will be used later.
include( GNUInstallDirs )

### Defining how to “build” the header-only library ###
add_library( ${PROJECT_NAME} INTERFACE )

target_include_directories( 
        ${PROJECT_NAME}
        INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_features( ${PROJECT_NAME} INTERFACE cxx_std_17 )

### Installation instructions ###
install( TARGETS ${PROJECT_NAME}
         EXPORT ${PROJECT_NAME}_Targets
         ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
         LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
         RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        )

# cmake package containing the macros parsing versions
include(CMakePackageConfigHelpers)
# generate the configuration file which cmake uses for using an installed package
write_basic_package_version_file("${PROJECT_NAME}ConfigVersion.cmake"
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY SameMajorVersion)
configure_package_config_file(
        "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
        "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        INSTALL_DESTINATION
        ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)
                     
### Selecting targets and files to install ###
install(EXPORT ${PROJECT_NAME}_Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/SI DESTINATION include)
