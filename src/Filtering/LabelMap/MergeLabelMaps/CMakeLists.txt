cmake_minimum_required(VERSION 3.16.3)

project(MergeLabelMaps)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})


add_executable(MergeLabelMaps Code.cxx)
target_link_libraries(MergeLabelMaps ${ITK_LIBRARIES})

install(TARGETS MergeLabelMaps
  DESTINATION bin/ITKSphinxExamples/Filtering/LabelMap
  COMPONENT Runtime
  )

install(FILES Code.cxx CMakeLists.txt
  DESTINATION share/ITKSphinxExamples/Code/Filtering/LabelMap/MergeLabelMaps/
  COMPONENT Code
  )


enable_testing()
add_test(NAME MergeLabelMapsTest
  COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/MergeLabelMaps)

