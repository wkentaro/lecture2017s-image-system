#include <opencv2/opencv.hpp>

int
main(int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s FILENAME\n", argv[0]);
    return 1;
  }
  cv::Mat img = cv::imread(argv[1]);

  cv::Mat gray;
  cv::cvtColor(img, gray, CV_BGR2GRAY);

  cv::Moments mom = cv::moments(gray);
  int x = static_cast<int>(mom.m10 / mom.m00);
  int y = static_cast<int>(mom.m01 / mom.m00);
  cv::circle(img, cv::Point(x, y), 10, cv::Scalar(0, 255, 0), 10);
  cv::imshow("moment", img);
  cv::waitKey(0);
}
