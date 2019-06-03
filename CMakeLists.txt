CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
SET (CMAKE_CXX_STANDARD 14)
#add_executable(nfdv antlr.cpp)

#include(ExternalAntlr4Cpp)
#set(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/antlr/antlr-4.7.2-complete.jar)
#include_directories( ${ANTLR4CPP_INCLUDE_DIRS} )
#link_directories( ${ANTLR4CPP_LIBS} )
#message(STATUS "Found antlr4cpp libs: ${ANTLR4CPP_LIBS} and includes: ${ANTLR4CPP_INCLUDE_DIRS} ")

#antlr4cpp_process_grammar(demo NFCompiler
#  ${PROJECT_SOURCE_DIR}/parser/NFCompiler.g4
#  include_directories(${antlr4cpp_include_dirs_NFCompiler})
  
#add_executable(nfdv antlr.cpp ${antlr4cpp_src_files_NFCompiler})
#add_dependencies(nfdv antlr4cpp antlr4cpp_generation_NFCompiler)
#target_link_libraries(nfdv antlr4-runtime)

set(antlr4-GENERATED_SRC
  ${PROJECT_SOURCE_DIR}/parser/NFCompilerLexer.cpp
  ${PROJECT_SOURCE_DIR}/parser/NFCompilerParser.cpp
  #${PROJECT_SOURCE_DIR}/parser/NFCompilerBaseVisitor.cpp
  ${PROJECT_SOURCE_DIR}/parser/NFCompilerVisitor.cpp
)

foreach( src_file ${antlr4-GENERATED_SRC} )
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          GENERATED TRUE
          )
endforeach( src_file ${antlr4-GENERATED_SRC} )

include_directories(
  ${PROJECT_SOURCE_DIR}/antlr/
  ${PROJECT_SOURCE_DIR}/antlr/misc
  ${PROJECT_SOURCE_DIR}/antlr/atn
  ${PROJECT_SOURCE_DIR}/antlr/dfa
  ${PROJECT_SOURCE_DIR}/antlr/tree
  ${PROJECT_SOURCE_DIR}/antlr/support
  ${PROJECT_SOURCE_DIR}/
  ${PROJECT_SOURCE_DIR}/libs/
)

set(antlr4_SRC
  ${PROJECT_SOURCE_DIR}/main.cpp
  ${PROJECT_SOURCE_DIR}/symbol.cpp
  ${PROJECT_SOURCE_DIR}/symboltable.cpp
  ${antlr4-GENERATED_SRC}
)

if (NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  set (flags_1 "-Wno-overloaded-virtual")
else()
  set (flags_1 "-MP /wd4251")
endif()

foreach( src_file ${antlr_SRC} )
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          COMPILE_FLAGS "${COMPILE_FLAGS} ${flags_1}"
          )
endforeach( src_file ${antlr4_SRC} )
add_executable(a.out ${antlr4_SRC})

if(WIN32)
  target_link_libraries(a.out "${PROJECT_SOURCE_DIR}/libs/antlr4-runtime.lib")
endif()

if(APPLE)
  target_link_libraries(a.out "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.dylib")
elseif(UNIX)
  target_link_libraries(a.out "${PROJECT_SOURCE_DIR}/libantlr4-runtime.so")
endif()

target_link_libraries(a.out ${SYSTEM_LIBS})

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
add_custom_command(TARGET a.out POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/libantlr4-runtime.so"
  $<TARGET_FILE_DIR:a.out>)
endif()

if(WIN32)
add_custom_command(TARGET antlr4 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/libs/antlr4-runtime.dll"
  $<TARGET_FILE_DIR:antlr4>)
endif()

if(APPLE)
add_custom_command(TARGET antlr4 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${PROJECT_SOURCE_DIR}/libs/antlr4-runtime.dylib"
  $<TARGET_FILE_DIR:antlr4>)
endif()


