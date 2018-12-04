#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
/*
 * 建立读取视频并降采样后彩色图像的程序
 */
void help(char** argv ) {
    std::cout << "\n"
              << "Read in a image, write out a  down sampling of it\n"
              << argv[0] <<" <path/image>\n"
              << "For example:\n"
              << argv[0] << " ../data/adrian.jpg\n"
              << std::endl;
}

int main(int argc,char **argv) {

    if (argc != 2) {
        help(argv);
        return 0;
    }
    std::cout << "This is my exercise4" << std::endl;
    cv::namedWindow("exercise4",cv::WINDOW_AUTOSIZE);
    cv::namedWindow("downCvColor",cv::WINDOW_AUTOSIZE);
    cv::Mat ptyDown_frame,orgin_frame;
    orgin_frame = cv::imread(argv[1],-1);
    if(orgin_frame.empty())return -1;
    cv::imshow("exercise4",orgin_frame);
    cv::pyrDown(orgin_frame,ptyDown_frame);
    cv::imshow("downCvColor",ptyDown_frame);
    cv::waitKey(5000);
    cv::destroyWindow("exercise4");
    cv::destroyWindow("downCvColor");
    return 0;
}