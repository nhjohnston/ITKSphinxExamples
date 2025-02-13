cmake_minimum_required(VERSION 3.16.3)

project( RescaleIntensity )

find_package( ITK REQUIRED )
include( ${ITK_USE_FILE} )

add_executable( RescaleIntensity Code.cxx )
target_link_libraries( RescaleIntensity ${ITK_LIBRARIES} )

install( TARGETS RescaleIntensity
  DESTINATION bin/ITKSphinxExamples/Filtering/ImageIntensity
  COMPONENT Runtime
)

install( FILES Code.cxx CMakeLists.txt
  DESTINATION share/ITKSphinxExamples/Code/Filtering/ImageIntensity/RescaleIntensity
  COMPONENT Code
)

enable_testing()

set( input_image ${CMAKE_CURRENT_BINARY_DIR}/Gourds.png )
set( output_image Output.png )

add_test( NAME RescaleIntensityTest
  COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/RescaleIntensity
    ${input_image}
    ${output_image}
    0
    255
)

if( ITK_WRAP_PYTHON )
  string( REPLACE . "Python." output_image "${output_image}" )
  add_test( NAME RescaleIntensityTestPython
    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/Code.py
      ${input_image}
      ${output_image}
      0
      255
  )
endif()
