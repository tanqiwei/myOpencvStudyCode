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
cv::Mat g_ptyDown_frame,g_orgin_frame;//全局处理
int g_slider_position = 2;
void onTrackbarSlide(int pos,void *) {
    if(pos >=2 && pos <4 ){
        cv::setTrackbarPos("downSampleFactor","downCvColor",2);
        pos = 2;
    }else if(pos >=4 & pos< 8){
        cv::setTrackbarPos("downSampleFactor","downCvColor",4);
        pos = 4;
    }else{
        cv::setTrackbarPos("downSampleFactor","downCvColor",8);
        pos = 8;
    }

    cv::Mat orgin_frame = g_orgin_frame;
    while(pos !=1){
        cv::pyrDown(orgin_frame,g_ptyDown_frame);
        orgin_frame = g_ptyDown_frame;
        pos/=2;
    }
    cv::imshow("downCvColor",g_ptyDown_frame);
}



int main(int argc,char **argv) {

    if (argc != 2) {
        help(argv);
        return 0;
    }
    std::cout << "This is my exercise5" << std::endl;
    cv::namedWindow("exercise5",cv::WINDOW_AUTOSIZE);
    cv::namedWindow("downCvColor",cv::WINDOW_AUTOSIZE);
    g_orgin_frame = cv::imread(argv[1],-1);
    if(g_orgin_frame.empty())return -1;
    cv::imshow("exercise5",g_orgin_frame);
    // 创建滚动条
    cv::createTrackbar("downSampleFactor","downCvColor",&g_slider_position,8,onTrackbarSlide);
    cv::setTrackbarMin("downSampleFactor","downCvColor",2);//设置最小值
    cv::pyrDown(g_orgin_frame,g_ptyDown_frame);
    cv::imshow("downCvColor",g_ptyDown_frame);
    while(true){
        if(cv::waitKey(10)==27)break;
    }

    cv::destroyWindow("exercise4");
    cv::destroyWindow("downCvColor");
    return 0;
}