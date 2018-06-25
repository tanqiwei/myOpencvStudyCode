#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
// you can use the test jpg
// example2.1 ../data/test.jpg

int main(int argc,char ** argv) {
    Mat img = imread(argv[1],-1);//原始Opencv3的写法
    if(img.empty())return -1;
    namedWindow("Example1",cv::WINDOW_AUTOSIZE);
    imshow("Example1",img);
    waitKey(0);
//    destroyWindow("Example1");
    return 0;
}
