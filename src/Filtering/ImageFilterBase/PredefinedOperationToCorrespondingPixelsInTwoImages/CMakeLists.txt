cmake_minimum_required(VERSION 3.16.3)

project(PredefinedOperationToCorrespondingPixelsInTwoImages)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})


add_executable(PredefinedOperationToCorrespondingPixelsInTwoImages Code.cxx)
target_link_libraries(PredefinedOperationToCorrespondingPixelsInTwoImages ${ITK_LIBRARIES})

install(TARGETS PredefinedOperationToCorrespondingPixelsInTwoImages
  DESTINATION bin/ITKSphinxExamples/Filtering/ImageFilterBase
  COMPONENT Runtime
  )

install(FILES Code.cxx CMakeLists.txt
  DESTINATION share/ITKSphinxExamples/Code/Filtering/ImageFilterBase/PredefinedOperationToCorrespondingPixelsInTwoImages/
  COMPONENT Code
  )


enable_testing()
add_test(NAME PredefinedOperationToCorrespondingPixelsInTwoImagesTest
  COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/PredefinedOperationToCorrespondingPixelsInTwoImages)
