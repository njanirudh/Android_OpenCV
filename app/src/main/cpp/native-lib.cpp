#include <jni.h>
#include <string>

using namespace std;

#include "opencv2/core/core.hpp"

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
