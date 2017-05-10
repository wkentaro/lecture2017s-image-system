#include <opencv2/opencv.hpp>

int
main(int argc, char* argv[])
{
  if (argc != 3)
  {
    printf("Usage: %s FILENAME1 FILENAME2\n", argv[0]);
    return 1;
  }

  cv::Mat img1 = cv::imread(argv[1], 0);
  cv::Mat img2 = cv::imread(argv[2], 0);
  cv::Mat disp1 = cv::imread(argv[1], 1);
  cv::Mat disp2 = cv::imread(argv[2], 1);

  std::vector<cv::Point2f> p1;
  cv::goodFeaturesToTrack(img1, p1, 80, 0.01, 5);
  for (size_t i=0; i<p1.size(); i++)
  {
    cv::circle(disp1, p1.at(i), 3, cv::Scalar(0, 255, 0));
  }

  std::vector<cv::Point2f> p2;
  std::vector<uchar> status;
  std::vector<float> err;
  cv::calcOpticalFlowPyrLK(img1, img2, p1, p2, status, err);

  for (size_t i=0; i<p2.size(); i++)
  {
    cv::circle(disp2, p2.at(i), 3, cv::Scalar(0, 255, 0));
  }

  cv::Mat viz;
  cv::hconcat(disp1, disp2, viz);

  cv::namedWindow(argv[1], CV_WINDOW_AUTOSIZE | CV_WINDOW_KEEPRATIO | CV_GUI_EXPANDED);
  cv::imshow("optical_flow", viz);
  cv::waitKey(0);
}
