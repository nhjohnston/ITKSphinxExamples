cmake_minimum_required(VERSION 3.16.3)

project(ConvertLabelMapToImage)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})


add_executable(ConvertLabelMapToImage Code.cxx)
target_link_libraries(ConvertLabelMapToImage ${ITK_LIBRARIES})

install(TARGETS ConvertLabelMapToImage
  DESTINATION bin/ITKSphinxExamples/Filtering/LabelMap
  COMPONENT Runtime
  )

install(FILES Code.cxx CMakeLists.txt
  DESTINATION share/ITKSphinxExamples/Code/Filtering/LabelMap/ConvertLabelMapToImage/
  COMPONENT Code
  )


enable_testing()
add_test(NAME ConvertLabelMapToImageTest
  COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ConvertLabelMapToImage)

