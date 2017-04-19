#include <iostream>

#include <opencv2/opencv.hpp>

int
main(int argc, char* argv[])
{
  if (argc > 2)
  {
    printf("Usage: %s [CAMERA_ID]\n", argv[1]);
    return 1;
  }
  int camera_id = 0;
  if (argc == 2)
  {
    camera_id = atoi(argv[1]);
  }
  cv::VideoCapture cap(camera_id);
  if (!cap.isOpened())
  {
    printf("Failed to open the camera: %d\n", camera_id);
    return 1;
  }

  std::ostringstream stream;
  stream << "camera" << camera_id;
  std::string window_name = stream.str();

  cv::namedWindow(window_name, CV_WINDOW_AUTOSIZE | CV_WINDOW_KEEPRATIO | CV_GUI_EXPANDED);

  int key;
  cv::Mat frame;
  while (true)
  {
    cap >> frame;
    if (frame.empty())
    {
      break;
    }

    cv::imshow(window_name, frame);
    key = cv::waitKey(1);

    if (key == 27)
    {
      break;
    }
  }
}
