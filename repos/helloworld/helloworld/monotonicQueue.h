#pragma once
#include <deque>

using namespace std;

class monotonicQueue
{
private:
	deque<int> deq;

public:
	// �ڶ�β���Ԫ�� n
	void push(int n);
	// ���ص�ǰ�����е����ֵ
	int max();
	// ��ͷԪ������� n��ɾ����
	void pop(int n);
};

