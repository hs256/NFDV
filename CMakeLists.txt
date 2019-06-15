CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
SET (CMAKE_CXX_STANDARD 14)
PROJECT(NFDV)

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

set(Z3_LINK_LIB -lz3)

set(antlr4_SRC
  ${PROJECT_SOURCE_DIR}/main.cpp
  ${PROJECT_SOURCE_DIR}/symbol.cpp
  ${PROJECT_SOURCE_DIR}/symboltable.cpp
  ${PROJECT_SOURCE_DIR}/instructions.cpp
  ${PROJECT_SOURCE_DIR}/trace.cpp
  ${PROJECT_SOURCE_DIR}/pkt.cpp
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

target_link_libraries(a.out ${Z3_LINK_LIB})

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

#z3
set(Z3_COMPONENT_CXX_DEFINES "")
set(Z3_COMPONENT_CXX_FLAGS "")
set(Z3_COMPONENT_EXTRA_INCLUDE_DIRS "")
set(Z3_DEPENDENT_LIBS "")
set(Z3_DEPENDENT_EXTRA_CXX_LINK_FLAGS "")


if ("${CMAKE_VERSION}" VERSION_LESS "3.1")
  # FIXME: Drop this when we upgrade to newer CMake versions.
  if (("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU") OR ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang"))
    z3_add_cxx_flag("-std=c++11" REQUIRED)
  else()
    message(AUTHOR_WARNING "Not setting C++ language version for compiler")
  endif()
else ()
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif ()

if ("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
  message(STATUS "Platform: Linux")
  list(APPEND Z3_COMPONENT_CXX_DEFINES "-D_LINUX_")
  if ("${TARGET_ARCHITECTURE}" STREQUAL "x86_64")
    list(APPEND Z3_COMPONENT_CXX_DEFINES "-D_USE_THREAD_LOCAL")
  endif()
elseif ("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")
  # Does macOS really not need any special flags?
  message(STATUS "Platform: Darwin")
elseif ("${CMAKE_SYSTEM_NAME}" MATCHES "FreeBSD")
  message(STATUS "Platform: FreeBSD")
  list(APPEND Z3_COMPONENT_CXX_DEFINES "-D_FREEBSD_")
elseif ("${CMAKE_SYSTEM_NAME}" MATCHES "NetBSD")
  message(STATUS "Platform: NetBSD")
  list(APPEND Z3_COMPONENT_CXX_DEFINES "-D_NetBSD_")
elseif ("${CMAKE_SYSTEM_NAME}" MATCHES "OpenBSD")
  message(STATUS "Platform: OpenBSD")
  list(APPEND Z3_COMPONENT_CXX_DEFINES "-D_OPENBSD_")
elseif (CYGWIN)
  message(STATUS "Platform: Cygwin")
  list(APPEND Z3_COMPONENT_CXX_DEFINES "-D_CYGWIN")
elseif (WIN32)
  message(STATUS "Platform: Windows")
  list(APPEND Z3_COMPONENT_CXX_DEFINES "-D_WINDOWS")
elseif (EMSCRIPTEN)
  message(STATUS "Platform: Emscripten")
  list(APPEND Z3_DEPENDENT_EXTRA_CXX_LINK_FLAGS
    "-Os"
    "-s ALLOW_MEMORY_GROWTH=1"
    "-s ASSERTIONS=0"
    "-s DISABLE_EXCEPTION_CATCHING=0"
    "-s ERROR_ON_UNDEFINED_SYMBOLS=1"
  )
else()
  message(FATAL_ERROR "Platform \"${CMAKE_SYSTEM_NAME}\" not recognised")
endif()

if (BUILD_LIBZ3_SHARED)
  if (NOT (MSVC OR MINGW OR WIN32))
    z3_add_cxx_flag("-fPIC" REQUIRED)
  endif()
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

include(CMakePackageConfigHelpers)
if ("${CMAKE_VERSION}" VERSION_LESS "3.0")
  export(TARGETS libz3
    NAMESPACE z3::
    FILE "${PROJECT_BINARY_DIR}/Z3Targets.cmake"
  )
endif()

