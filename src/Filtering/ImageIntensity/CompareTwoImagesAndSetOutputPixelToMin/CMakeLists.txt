cmake_minimum_required(VERSION 3.16.3)

project(CompareTwoImagesAndSetOutputPixelToMin)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})


add_executable(CompareTwoImagesAndSetOutputPixelToMin Code.cxx)
target_link_libraries(CompareTwoImagesAndSetOutputPixelToMin ${ITK_LIBRARIES})

install(TARGETS CompareTwoImagesAndSetOutputPixelToMin
  DESTINATION bin/ITKSphinxExamples/Filtering/ImageIntensity
  COMPONENT Runtime
  )

install(FILES Code.cxx CMakeLists.txt
  DESTINATION share/ITKSphinxExamples/Code/Filtering/ImageIntensity/CompareTwoImagesAndSetOutputPixelToMin/
  COMPONENT Code
  )


enable_testing()
add_test(NAME CompareTwoImagesAndSetOutputPixelToMinTest
  COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/CompareTwoImagesAndSetOutputPixelToMin)
