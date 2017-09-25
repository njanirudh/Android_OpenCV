package com.example.anirudhnj.opencv;

import android.graphics.Bitmap;

import org.opencv.core.CvType;
import org.opencv.core.Mat;

/**
 * Created by anirudhnj on 25/09/17.
 */

public class ImageProcessing {

    static {
        System.loadLibrary("native-lib");
    }

    public native String ImgToGray(long addrRgba, long addrGray);

    public Bitmap convert_img_2_gray(Bitmap bitmap, int width, int height, boolean rotation)
    {
        Mat mat = new Mat(bitmap.getWidth(), bitmap.getHeight(),
                CvType.CV_8UC1);
        org.opencv.android.Utils.bitmapToMat(bitmap, mat);
        Mat outMat = new Mat(height, width, CvType.CV_8SC1);

        ImgToGray(mat.getNativeObjAddr(),outMat.getNativeObjAddr());

        org.opencv.android.Utils.matToBitmap(outMat, bitmap);
        return bitmap;
    }

}
