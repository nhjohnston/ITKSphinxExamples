cmake_minimum_required(VERSION 3.16.3)

project( DoDataParallelThreading )

find_package( ITK REQUIRED )
include( ${ITK_USE_FILE} )

add_executable( DoDataParallelThreading Code.cxx )
target_link_libraries( DoDataParallelThreading ${ITK_LIBRARIES} )

install( TARGETS DoDataParallelThreading
  DESTINATION bin/ITKSphinxExamples/Core/Common
  COMPONENT Runtime
)

install( FILES Code.cxx CMakeLists.txt
  DESTINATION share/ITKSphinxExamples/Code/Core/Common/DoDataParallelThreading
  COMPONENT Code
)

enable_testing()
add_test( NAME DoDataParallelThreadingTest
  COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/DoDataParallelThreading
)
