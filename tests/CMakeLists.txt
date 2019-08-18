set(tests_dir ${CMAKE_CURRENT_SOURCE_DIR})

# Get the list of test categories to build
# All test categories are built unless a test filter was given

# create separate targets for each test project
    set(test_projects_dir_list "")
    file(GLOB subdirectories RELATIVE ${tests_dir} ${tests_dir}/*)
    foreach(dir ${subdirectories})
        if(${dir} MATCHES "common")
            # The common folder is always included
            continue()
        endif()
        if(EXISTS "${tests_dir}/${dir}/CMakeLists.txt")
            list(APPEND test_projects_dir_list ${dir})
        endif()
    endforeach()
list(REMOVE_DUPLICATES test_projects_dir_list)

# create test executable targets for each test project using the build_sycl function
function(add_cpp_test)
  get_filename_component(test_dir ${CMAKE_CURRENT_SOURCE_DIR} NAME)
  set(test_exe_name test_${test_dir})
  message(STATUS "Adding test: " ${test_exe_name})
  add_executable(${test_exe_name} ${ARGN})
  target_include_directories(${test_exe_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
  target_link_libraries(${test_exe_name} PRIVATE gtest_main)
endfunction()


foreach(dir ${test_projects_dir_list})
    add_subdirectory(${dir})
endforeach()