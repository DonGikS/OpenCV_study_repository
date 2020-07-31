#include<opencv2/highgui.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main() {
	
	
	Mat img_color;

	VideoCapture cap(0); //������ü ���� �� 0�� ī�޶� ����
	
	if (!cap.isOpened()) {
		cerr << "���� - ī�޶� �� �� �����ϴ�.\n";
		return -1;
	}


	Size size = Size((int)cap.get(CAP_PROP_FRAME_WIDTH), (int)cap.get(CAP_PROP_FRAME_HEIGHT));

	VideoWriter writer;									//������ ���� ���� ��ü
	double fps = 29.97;
	int fourcc = VideoWriter::fourcc('M', 'J', 'P', 'G'); //���� �ڵ� ����
	writer.open("output.avi", fourcc, fps, size, true); //���� ���� �� ����
	if (!writer.isOpened()) {
		cout << "�������� �����ϱ� ���� �ʱ�ȭ �۾� �� ���� �߻�" << endl;
	}
	
	while (1) {
		cap.read(img_color);

		if (img_color.empty()) {
			cerr << "�� ������ ĸ�ĵǾ����ϴ�.\n";
			break;
		}

		writer.write(img_color);

		imshow("Color", img_color);

		if (waitKey(25) >= 0)break;
	}
	
	return 0;
}