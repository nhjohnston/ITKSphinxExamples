#include "itkImage.h"
#include "itkImageFileWriter.h"

#include "ImageFilterMultipleOutputs.h"

int
main(int, char *[])
{
  // Setup types
  using ImageType = itk::Image<unsigned char, 2>;
  using FilterType = itk::ImageFilterMultipleOutputs<ImageType>;

  // Create and the filter
  FilterType::Pointer filter = FilterType::New();
  filter->Update();

  itk::WriteImage(filter->GetOutput1(), "TestOutput1.jpg");

  itk::WriteImage(filter->GetOutput2(), "TestOutput2.jpg");

  return EXIT_SUCCESS;
}
