#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
void help(char** argv ) {
    std::cout << "\n"
              << "A simple OpenCV program that loads and displays an image from disk\n"
              << argv[0] <<" <path/filename>\n"
              << "For example:\n"
              << argv[0] << " ../data/test.jpg\n"
              << std::endl;
}
int main(int argc,char ** argv) {
    if (argc != 2) {
        help(argv);
        return 0;
    }
    Mat img = imread(argv[1],-1);//原始Opencv3的写法
    if(img.empty())return -1;
    namedWindow("Example2-2",cv::WINDOW_AUTOSIZE);
    imshow("Example2-2",img);
    waitKey(0);
    destroyWindow("Example2-2");
    return 0;
}