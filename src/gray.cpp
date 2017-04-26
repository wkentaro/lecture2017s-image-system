#include <iostream>

#include <opencv2/opencv.hpp>

int
main(int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s FILENAME\n", argv[0]);
    return 1;
  }
  cv::Mat img = cv::imread(argv[1], 1);

  cv::Mat gray;
  cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);   // 1 channel gray
  cv::cvtColor(gray, gray, cv::COLOR_GRAY2BGR);  // 3 channels gray

  cv::Mat viz;
  cv::hconcat(img, gray, viz);

  cv::namedWindow(argv[1], CV_WINDOW_AUTOSIZE | CV_WINDOW_KEEPRATIO | CV_GUI_EXPANDED);
  cv::imshow(argv[1], viz);
  cv::waitKey(0);
}
