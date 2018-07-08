#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
using namespace cv;
using namespace std;


int main()
{
	Mat src, dst;

	char* source_window = "Source image";
	char* equalized_window = "Equalized Image";

	// 加载源图像
	src = imread("cat.jpg", 1);

	if (!src.data)
	{
		cout << "Usage: ./Histogram_Demo <path_to_image>" << endl;
		return -1;
	}

	// 转为灰度图
	cvtColor(src, src, CV_BGR2GRAY);

	// 应用直方图均衡化
	equalizeHist(src, dst);

	// 显示结果
	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
	namedWindow(equalized_window, CV_WINDOW_AUTOSIZE);

	imshow(source_window, src);
	imshow(equalized_window, dst);

	// 等待用户按键退出程序
	waitKey(0);

	return 0;
}