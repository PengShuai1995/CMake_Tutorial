cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.0)

#specify the C++ standard
set(CMAKE_CXX_STANDARD 18)
set(CMAKE_CXX_STANDARD_REQUIRED True)


#should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)



configure_file(TutorialConfig.h.in TutorialConfig.h)


#add the MathFuntions library
if(USE_MYMATH)
{
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")

}

add_executable(Tutorial tutorial.cxx)

target_link_libraries(Tutorial PUBLIC ${EXTER_LIBS})

target_include_directories(Tutorial PUBLIC 
                           "${PROJECT_BINARY_DIR}" 
                           ${EXTER_LIBS}                         
 )                           