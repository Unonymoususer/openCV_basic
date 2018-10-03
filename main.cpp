#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

#define EX1 0
#define EX2 0
#define EX3 0
#define EX4 0
#define EX5 0
#define EX6 1

int main()
{
#if EX1
	Mat image = Mat::zeros(480, 640, CV_8UC3); //y=480, x=640
	cout << "image size: " << image.cols << " x " << image.rows << endl;
	putText(image, "Hello, OpenCV", Point(0, image.rows / 2), FONT_HERSHEY_PLAIN, 3, Scalar(0, 255, 0), 4);
	//텍스트 삽입. x좌표 및 y좌표 지정, 폰트, 폰트크기, 색상, ?
	imshow("Hello OpenCV", image);
	waitKey(); //ms단위로 창을 보여줌. 아무것도 넣지 않거나 0을 넣을경우 키보드 입력이 있을 때까지 대기.
	return 0;
#endif

#if EX2
	Mat image = imread("../data/lena.png");
	Mat resized_image;
	resize(image, resized_image, Size(512, 256)); //x,y
	imshow("lena", image);
	imshow("resized lena", resized_image);
	imwrite("../data/lena_resized.png", resized_image);
	waitKey();
	return 0;
#endif

#if EX6
	Mat image = imread("../data/lena.png");
	Mat sBGR;
	image.copyTo(sBGR);

	for (int y = 0; y < image.rows; ++y)
	{
		for (int x = 0; x < image.cols; ++x)
		{
			for (int c = 0; c < 3; ++c)
				sBGR.at<Vec3b>(y, x)[c] = (unsigned char)(255 * pow(image.at<Vec3b>(y, x)[c] / 255.0, 2.2));
				//Vec3b = vector-3channel-byte
		}
	}
	imshow("lena", image);
	imshow("sRGB", sBGR);
	waitKey();

	Mat XYZ;
	cvtColor(sBGR, XYZ, CV_BGR2XYZ);
	imshow("XYZ", XYZ);

	Mat HSV;
	cvtColor(sBGR, HSV, CV_BGR2HSV);
	imshow("HSV", HSV);

	Mat Lab;
	cvtColor(sBGR, Lab, CV_BGR2Lab);
	imshow("Lab", Lab);

	waitKey();
#endif
}