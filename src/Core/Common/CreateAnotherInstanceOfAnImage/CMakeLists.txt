cmake_minimum_required(VERSION 3.16.3)

project(CreateAnotherInstanceOfAnImage)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})


add_executable(CreateAnotherInstanceOfAnImage Code.cxx)
target_link_libraries(CreateAnotherInstanceOfAnImage ${ITK_LIBRARIES})

install(TARGETS CreateAnotherInstanceOfAnImage
  DESTINATION bin/ITKSphinxExamples/Core/Common
  COMPONENT Runtime
  )

install(FILES Code.cxx CMakeLists.txt
  DESTINATION share/ITKSphinxExamples/Code/Core/Common/CreateAnotherInstanceOfAnImage/
  COMPONENT Code
  )


enable_testing()
add_test(NAME CreateAnotherInstanceOfAnImageTest
  COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/CreateAnotherInstanceOfAnImage)

