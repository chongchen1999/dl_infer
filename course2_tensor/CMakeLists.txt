cmake_minimum_required(VERSION 3.16)
project(course2_tensor)
set(CMAKE_CXX_STANDARD 17)
find_package(OpenMP REQUIRED)
find_package(Armadillo REQUIRED)
find_package(glog REQUIRED)
find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)
find_package(GTest REQUIRED)

set(link_lib glog::glog GTest::gtest)
if (!WIN32)
    set(link_lib "${link_lib} pthread")
endif ()
set(link_math_lib ${ARMADILLO_LIBRARIES} ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES})
aux_source_directory(./test DIR_TEST_ARMA)
aux_source_directory(./source DIR_SOURCE_ARMA)

add_executable(course2_tensor  main.cpp ${DIR_TEST_ARMA} ${DIR_SOURCE_ARMA})
target_link_libraries(course2_tensor  ${link_lib} ${link_math_lib} OpenMP::OpenMP_CXX)

target_include_directories(course2_tensor PUBLIC ${glog_INCLUDE_DIR})
target_include_directories(course2_tensor PUBLIC ${GTest_INCLUDE_DIR})
target_include_directories(course2_tensor PUBLIC ${Armadillo_INCLUDE_DIR})
target_include_directories(course2_tensor PUBLIC ./include)

enable_testing()
