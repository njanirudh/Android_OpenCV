# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)


# OpenCV stuff
add_library( lib_opencv SHARED IMPORTED )
set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libopencv_java3.so)

add_library(lib_opencv_core STATIC IMPORTED)
set_target_properties(lib_opencv_core PROPERTIES IMPORTED_LOCATION
         ${CMAKE_SOURCE_DIR}/src/main/jniLibs/armeabi-v7a/libopencv_core.a)


add_library(lib_opencv_imgproc STATIC IMPORTED)
set_target_properties(lib_opencv_imgproc PROPERTIES IMPORTED_LOCATION
         ${CMAKE_SOURCE_DIR}/src/main/jniLibs/armeabi-v7a/libopencv_imgproc.a)



add_library(lib_opencv_imgcodecs STATIC IMPORTED)
set_target_properties(lib_opencv_imgcodecs PROPERTIES IMPORTED_LOCATION
          ${CMAKE_SOURCE_DIR}/src/main/jniLibs/armeabi-v7a/libopencv_imgcodecs.a)

add_library(lib_opencv_objdetect STATIC IMPORTED)
set_target_properties(lib_opencv_objdetect PROPERTIES IMPORTED_LOCATION
          ${CMAKE_SOURCE_DIR}/src/main/jniLibs/armeabi-v7a/libopencv_objdetect.a)

add_library(lib_opencv_tracking STATIC IMPORTED)
set_target_properties(lib_opencv_tracking PROPERTIES IMPORTED_LOCATION
          ${CMAKE_SOURCE_DIR}/src/main/jniLibs/armeabi-v7a/libopencv_tracking.a)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

# Link to Include path
include_directories(/Users/anirudhnj/SDK/Android/dist_arm/sdk/native/jni/include)

add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp )


# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # OpenCV lib
                       lib_opencv
                       lib_opencv_core
                       lib_opencv_imgproc
                       lib_opencv_imgcodecs

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )