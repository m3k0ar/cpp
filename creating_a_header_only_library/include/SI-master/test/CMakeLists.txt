cmake_minimum_required(VERSION 3.12)

add_executable(SI_detail_tests)
target_sources(
  SI_detail_tests
  PRIVATE
  src/Catch2Main.cc
  src/detail_tests/detail_tests.cc
  src/detail_tests/number_parser_tests.cc
  src/detail_tests/unit_t_operator_tests.cc
  src/detail_tests/unit_t_type_tests.cc
  src/detail_tests/unit_helper_functions_tests.cc
  src/detail_tests/streaming_operator_tests.cc)

target_include_directories(
  SI_detail_tests PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                          $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)

target_compile_features(SI_detail_tests PRIVATE cxx_std_17)
# TODO check for possibilities to use Catch2::Catch2 namespace
target_link_libraries(SI_detail_tests CONAN_PKG::Catch2)

# TODO Add flags for Appleclang as it is not catched by the generator expression
# below
target_compile_options(
  SI_detail_tests
  PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/std:c++17>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<CXX_COMPILER_ID:MSVC>:/WX>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-Wall>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-Werror>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-pedantic>
)

# add `-DCATCH_CONFIG_RUNTIME_STATIC_REQUIRE to switch to runtime only checks
# target_compile_definitions(SI_detail_tests PRIVATE
# CATCH_CONFIG_RUNTIME_STATIC_REQUIRE)

add_executable(SI_base_unit_tests)
target_sources(
  SI_base_unit_tests
  PRIVATE
  src/Catch2Main.cc
  src/base_unit_tests/mass_tests.cc
  src/base_unit_tests/time_tests.cc
  src/base_unit_tests/electric_current_tests.cc
  src/base_unit_tests/temperature_tests.cc
  src/base_unit_tests/substance_tests.cc
  src/base_unit_tests/luminosity_tests.cc
  src/base_unit_tests/length_tests.cc)

target_include_directories(
  SI_base_unit_tests
  PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
          $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)

target_compile_features(SI_base_unit_tests PRIVATE cxx_std_17)
target_link_libraries(SI_base_unit_tests CONAN_PKG::Catch2)

target_compile_options(
  SI_base_unit_tests
  PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/std:c++17>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<CXX_COMPILER_ID:MSVC>:/WX>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-Wall>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-Werror>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-pedantic>
)

# add `-DCATCH_CONFIG_RUNTIME_STATIC_REQUIRE to switch to runtime only checks
# target_compile_definitions(SI_base_unit_tests PRIVATE
# CATCH_CONFIG_RUNTIME_STATIC_REQUIRE)

add_executable(SI_derived_unit_tests)
target_sources(
  SI_derived_unit_tests
  PRIVATE
  src/Catch2Main.cc
  src/derived_unit_tests/area_tests.cc
  src/derived_unit_tests/frequency_tests.cc
  src/derived_unit_tests/electric_charge_tests.cc
  src/derived_unit_tests/electric_potential_tests.cc
  src/derived_unit_tests/electric_capacity_tests.cc
  src/derived_unit_tests/electric_conductance_tests.cc
  src/derived_unit_tests/electric_resistance_tests.cc
  src/derived_unit_tests/inductance_tests.cc
  src/derived_unit_tests/momentum_tests.cc
  src/derived_unit_tests/velocity_tests.cc
  src/derived_unit_tests/acceleration_tests.cc
  src/derived_unit_tests/force_tests.cc
  src/derived_unit_tests/pressure_tests.cc
  src/derived_unit_tests/energy_tests.cc
  src/derived_unit_tests/power_tests.cc
  src/derived_unit_tests/magnetic_flux_tests.cc
  src/derived_unit_tests/magnetic_field_tests.cc
  src/derived_unit_tests/luminous_flux_tests.cc
  src/derived_unit_tests/illuminance_tests.cc
  src/derived_unit_tests/radioactivity_tests.cc
  src/derived_unit_tests/absorbed_dose_tests.cc
  src/derived_unit_tests/equivalent_dose_tests.cc
  src/derived_unit_tests/catalytic_activity_tests.cc
  src/derived_unit_tests/angle_tests.cc
  src/derived_unit_tests/solid_angle_tests.cc)

target_include_directories(
  SI_derived_unit_tests
  PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
          $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)

target_compile_features(SI_derived_unit_tests PRIVATE cxx_std_17)
target_link_libraries(SI_derived_unit_tests CONAN_PKG::Catch2)

target_compile_options(
  SI_derived_unit_tests
  PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/std:c++17>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<CXX_COMPILER_ID:MSVC>:/WX>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-Wall>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-Werror>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-pedantic>
)

add_executable(SI_unit_benchmarks)
target_sources(SI_unit_benchmarks PRIVATE src/Catch2Main.cc
               src/benchmarks/unit_benchmarks.cc)

target_include_directories(
  SI_unit_benchmarks
  PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
          $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)

target_compile_features(SI_unit_benchmarks PRIVATE cxx_std_17)
target_link_libraries(SI_unit_benchmarks CONAN_PKG::Catch2)

target_compile_options(
  SI_unit_benchmarks
  PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/std:c++17>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<CXX_COMPILER_ID:MSVC>:/WX>
    $<$<CXX_COMPILER_ID:MSVC>:/DCATCH_CONFIG_ENABLE_BENCHMARKING>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-Wall>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-Werror>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-pedantic>
    $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>:-DCATCH_CONFIG_ENABLE_BENCHMARKING>
)

add_test(NAME SI_detail_tests COMMAND SI_detail_tests)
add_test(NAME SI_base_unit_tests COMMAND SI_base_unit_tests)
add_test(NAME SI_derived_unit_tests COMMAND SI_derived_unit_tests)
# add_test(NAME SI_unit_benchmarks COMMAND SI_unit_benchmarks)
