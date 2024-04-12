#ifndef YOLOV5_H
#define YOLOV5_H

#endif // YOLOV5_H
#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
using namespace std;

struct Detection
{
    int class_id;
    float confidence;
    cv::Rect box;
};




const std::vector<cv::Scalar> colors = {cv::Scalar(255, 255, 0), cv::Scalar(0, 255, 0), cv::Scalar(0, 255, 255), cv::Scalar(255, 0, 0)};
const float INPUT_WIDTH = 640.0;
const float INPUT_HEIGHT = 640.0;
const float SCORE_THRESHOLD = 0.2;
const float NMS_THRESHOLD = 0.4;
const float CONFIDENCE_THRESHOLD = 0.4;


class Yolov5
{
  public:
    bool is_cuda;
    cv::dnn::Net net;
    void load_net(cv::dnn::Net &net, bool is_cuda);
    std::vector<std::string> load_class_list();
    cv::Mat format_yolov5(const cv::Mat &source);
    void detect(cv::Mat &image, cv::dnn::Net &net, std::vector<Detection> &output, const std::vector<std::string> &className);
    cv::Mat Draw_Img(cv::Mat &frame, const std::vector<Detection> &output, const std::vector<std::string> &class_list);



  private:

};
