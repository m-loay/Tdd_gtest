cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(kf)

# Set Paths
set(APP_INCLIDE_DIR ${CMAKE_SOURCE_DIR}/src/App)
set(TEST_CASES_INCLIDE_DIR ${CMAKE_SOURCE_DIR}/src/testCases)

# Use simulation  testing mode or Unit testing
option (USE_APP_MODE "Use APP Mode" OFF )
option (USE_UNIT_TESTING "Use Unit testing Mode" ON)

# #set build type to debug and C++ standard to 11
set(CMAKE_CXX_STANDARD 11) 

# add the binary tree to the search path for include files
# so that we will find KalmanConfig.h
include_directories ("${APP_INCLIDE_DIR}")
include_directories ("${TEST_CASES_INCLIDE_DIR}")

if(USE_APP_MODE)
    message("Use APP Mode")

    #Add kfApp sub-directory
    add_subdirectory(${KFAPP_INCLIDE_DIR})
    list(APPEND EXTRA_LIBS App)
    list(APPEND EXTRA_INCLUDES "${APP_INCLIDE_DIR}")

    #compile the source code and link it with external libraries
    add_executable(kf src/main.cpp)
    target_include_directories(kf PUBLIC ${EXTRA_INCLUDES})
    target_link_libraries (kf PUBLIC ${EXTRA_LIBS})
    
elseif(USE_UNIT_TESTING)
    message("Use unit testing Mode")
    enable_testing()

    #Find Gtest lib and include the directories
    find_package(GTest REQUIRED)
    include_directories(${GTEST_INCLUDE_DIRS})

    #Add kfApp sub-directory
    add_subdirectory(${APP_INCLIDE_DIR})
    list(APPEND EXTRA_LIBS App)
    list(APPEND EXTRA_INCLUDES "${APP_INCLIDE_DIR}")

    # #Add kfApp sub-directory
    # add_subdirectory(${TEST_CASES_INCLIDE_DIR})
    # list(APPEND EXTRA_LIBS testCases)
    # list(APPEND EXTRA_INCLUDES "${TEST_CASES_INCLIDE_DIR}")

	#compile the source code and link it with external libraries
    add_executable(gtest src/main_test.cpp)
    target_include_directories(gtest PUBLIC ${EXTRA_INCLUDES})
    # target_link_libraries (gtest PUBLIC testCases)
    target_link_libraries (gtest PUBLIC App)
    target_link_libraries(gtest PUBLIC ${GTEST_BOTH_LIBRARIES})
    
    #add the testing
    add_test(NAME gtest COMMAND gtest)
endif()