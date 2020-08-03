#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

string title = "밝기변경", bar_name = "밝기 값"; //imshow WINDOW title
Mat image;

//track bar control event
void onChange(int value, void *userdata) {
	int add_value = value - 130;
	cout << "추가 화소값" << add_value << endl;	//print bright value

	Mat tmp = image + add_value;
	imshow(title, tmp);
}

//마우스 콜벡함수
void onMouse(int event, int x, int y, int flags, void *param) {
	//mouse right button
	if (event == 1) {
		add(image, 10, image);
		setTrackbarPos(bar_name, title, image.at<uchar>(0));	//track bar position set
		imshow(title, image);
	}
	//mouse left button
	else if (event == 2) {
		subtract(image, 10, image);
		setTrackbarPos(bar_name, title, image.at<uchar>(0));	//track bar position set
		imshow(title, image);
	}
}

int main() {
	int value = 130;
	image = Mat(300, 500, CV_8UC1, Scalar(120));

	namedWindow(title, WINDOW_AUTOSIZE);
	createTrackbar(bar_name, title, &value, 255, onChange);		//track bar set function
	setMouseCallback(title, onMouse, 0);						//mouse callBack function call
	imshow(title, image);
	waitKey(0);
	return 0;
}