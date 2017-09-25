#include <jni.h>
#include <string>

using namespace std;

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_anirudhnj_opencv_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++ " + cv::getBuildInformation();

    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT void JNICALL Java_com_example_anirudhnj_opencv_ImageProcessing_ImgToGray(
        JNIEnv *env,
    jobject /* this */,
    jlong addrRgba, jlong addrGray){

    Mat& src = *(Mat*)addrRgba;
    Mat&  gray = *(Mat*)addrGray;

    cvtColor(src, gray, CV_BGR2GRAY);

}

