cmake_minimum_required(VERSION 3.16.3)

project(WriteTransfromFromFile)

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})


add_executable(WriteTransfromFromFile Code.cxx)
target_link_libraries(WriteTransfromFromFile ${ITK_LIBRARIES})

install(TARGETS WriteTransfromFromFile
  DESTINATION bin/ITKSphinxExamples/IO/TransformBase
  COMPONENT Runtime
  )

install(FILES Code.cxx CMakeLists.txt
  DESTINATION share/ITKSphinxExamples/Code/IO/TransformBase/WriteTransfromFromFile/
  COMPONENT Code
  )


enable_testing()
add_test(NAME WriteTransfromFromFileTest
  COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/WriteTransfromFromFile
  )
