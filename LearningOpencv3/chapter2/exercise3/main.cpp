#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
/*
 * 建立读取视频并降采样后彩色图像的程序
 */
void help(char** argv ) {
    std::cout << "\n"
              << "Read in a video, write out a  down sampling of it\n"
              << argv[0] <<" <path/video> <paht/video_output>\n"
              << "For example:\n"
              << argv[0] << " ../data/test.avi ../data/sampling.avi\n"
              << std::endl;
}

int main(int argc,char **argv) {

    if (argc != 3) {
        help(argv);
        return 0;
    }
    std::cout << "This is my exercise3" << std::endl;
    cv::namedWindow("exercise3",cv::WINDOW_AUTOSIZE);
    cv::namedWindow("downCvColor",cv::WINDOW_AUTOSIZE);
    cv::VideoCapture capture(argv[1]);
    double fps = capture.get(cv::CAP_PROP_FPS);
    cv::Size size(
            (int)capture.get(cv::CAP_PROP_FRAME_WIDTH)/2,//宽度
            (int)capture.get(cv::CAP_PROP_FRAME_HEIGHT)/2
    );
    cv::VideoWriter writer;
    writer.open( argv[2],CV_FOURCC('M','J','P','G'),fps,size);
    cv::Mat ptyDown_frame,orgin_frame;
    while(true)
    {
        capture >> orgin_frame;
        if(orgin_frame.empty())break;
        cv::imshow("exercise3",orgin_frame);
        cv::pyrDown(orgin_frame,ptyDown_frame);
        cv::imshow("downCvColor",ptyDown_frame);
        writer << ptyDown_frame;
        if(cv::waitKey(10)==27)break;
    }

    writer.release();
    capture.release();
    return 0;
}