#include <iostream>

#include <opencv2/opencv.hpp>

int
main(int argc, char* argv[])
{
  if (argc != 3)
  {
    printf("Usage: %s FILENAME SCALOR\n", argv[0]);
    return 1;
  }
  cv::Mat src = cv::imread(argv[1], 1);
  int scalor = atoi(argv[2]);

  cv::Mat dst;
  src.copyTo(dst);

  for (size_t j=0; j<dst.rows; j++)
  {
    for (size_t i=0; i<dst.cols; i++)
    {
      dst.at<cv::Vec3b>(j, i) += cv::Vec3b(scalor, scalor, scalor);
    }
  }

  cv::Mat viz;
  cv::hconcat(src, dst, viz);

  cv::namedWindow(argv[1], CV_WINDOW_AUTOSIZE | CV_WINDOW_KEEPRATIO | CV_GUI_EXPANDED);
  cv::imshow(argv[1], viz);
  cv::waitKey(0);
}
