cmake_minimum_required(VERSION 3.16.3)

project( WriteATIFFImage )

find_package( ITK REQUIRED )
include( ${ITK_USE_FILE} )

add_executable( WriteATIFFImage Code.cxx )
target_link_libraries( WriteATIFFImage ${ITK_LIBRARIES} )

install( TARGETS WriteATIFFImage
  DESTINATION bin/ITKSphinxExamples/IO/TIFF/
  COMPONENT Runtime
)

install( FILES Code.cxx CMakeLists.txt
  DESTINATION share/ITKSphinxExamples/Code/IO/TIFF/WriteATIFFImage
  COMPONENT Code
)

enable_testing()
add_test( NAME WriteATIFFImageTest
  COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/WriteATIFFImage
    ${CMAKE_CURRENT_BINARY_DIR}/Output.tif )
