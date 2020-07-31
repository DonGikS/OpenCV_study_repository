#include<opencv2/highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main() {
	
	
	Mat img_color;

	VideoCapture cap(0); //비디오객체 선언 및 0번 카메라 연결
	
	if (!cap.isOpened()) {
		cerr << "에러 - 카메라를 열 수 없습니다.\n";
		return -1;
	}


	Size size = Size((int)cap.get(CAP_PROP_FRAME_WIDTH), (int)cap.get(CAP_PROP_FRAME_HEIGHT));

	VideoWriter writer;									//동영상 파일 저장 객체
	double fps = 29.97;
	int fourcc = VideoWriter::fourcc('M', 'J', 'P', 'G'); //압축 코덱 설정
	writer.open("output.avi", fourcc, fps, size, true); //파일 개방 및 설정
	if (!writer.isOpened()) {
		cout << "동영상을 저장하기 위한 초기화 작업 중 에러 발생" << endl;
	}
	
	while (1) {
		cap.read(img_color);

		if (img_color.empty()) {
			cerr << "빈 영상이 캡쳐되었습니다.\n";
			break;
		}

		writer.write(img_color);

		imshow("Color", img_color);

		if (waitKey(25) >= 0)break;
	}
	
	return 0;
}