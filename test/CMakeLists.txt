cmake_minimum_required(VERSION 3.13)

#==========================#
# Configure gtest includes #
#==========================#

# [NOTE]:
#   By default, GoogleTest is static linked, since the project is dynamically linked.
#   Open this option to let GoogleTest link with dynamic library.
#   See: https://github.com/google/googletest/blob/master/googletest/README.md#visual-studio-dynamic-vs-static-runtimes
set(gtest_force_shared_crt ON)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

#===========#
# Add tests #
#===========#

add_subdirectory(support)
