// �� > 3.AC(5430��)
// idea>
// ���������� ������ ���� ������ ���� ����ϸ� �������� �ڿ��� ������ ������ ������ �տ��� ������ �ȴ�
// ���� ���������� ������ �ʰ� flag ���� ���� �̿��ؼ� �������� �� �������� ǥ���ؼ�
// �׿� ���� pop�� �޸� �Ѵ�.
// ! �迭�� �Է¹޴� �� ����� �� ����.
// @@ ����ã�� �� �������̽����� ã�ƾ���.!

// [c++]
// c++���� ���ڿ� �ڸ���>
// - ssstream::istringstream �� std::getline() �Լ� �̿��ϱ� -> ���ڿ� �����ڰ� 1���� �� ����
// - strtok() �Լ� �̿��ϱ� -> ���ڿ� �����ڰ� 2�� �̻��� ��� ���������� ����ȯ�� ���� �ʿ���

// @@ ���ڿ����� �迭�� ������ �� �ɰ��� �Լ��� �̿��ϴ� �� ����
// @@ ��Ģ�� ã�Ƽ� �Է� �޴� �� �� ���� ��

#include <iostream>
#include <deque>
#include <cstring>
#include <string>
using namespace std;

void printArr(deque<int> dq, bool isReverse) {
	cout << "[";
	if (isReverse) {
		for (int i = dq.size() - 1; i >= 0; i--) {
			cout << dq[i];
			if (i != 0) cout << ",";
		}
	}
	else {
		for (int i = 0; i < dq.size(); i++) {
			cout << dq[i];
			if (i != dq.size() - 1 ) cout << ",";
		}
	}
	cout << "]\n";
}

void makeArr(string arr, deque<int>& dq) {
	// string �� ���� �迭�� ��ȯ�� �� �� ũ�⺸�� 1�� �� Ŀ�� �Ѵ�.
	// �ι��ڸ� �����ؾ��ϹǷ�
	char* charr = new char[arr.size() + 1];
	strcpy_s(charr, arr.size() + 1, arr.c_str());
	// ���ؿ����� strcpy_s�� ������ ������. strcpy()�� ����ϴµ�

	char* leftstr = NULL;
	char* ptr = strtok_s(charr, "[,]", &leftstr);
	// ���ؿ����� strtok_s() �Լ��� ������ ����. strtok_r()�� ����ϴ� ��

	string tmp;
	while (ptr != NULL) {
		tmp = string(ptr);
		dq.push_back(stoi(tmp));
		ptr = strtok_s(NULL, "[,]", &leftstr);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	// ������
	string cmd;
	int n; // �迭 ũ��
	string arr;
	deque<int> dq;
	bool isReverse = false;
	bool isError = false;

	for (int i = 0; i < t; i++) {
		cin >> cmd >> n >> arr;
		// arr ���ڿ��� �ɰ��� ���� ����.
		makeArr(arr, dq);
		// ��ɾ� ����
		for (int j = 0; j < cmd.size(); j++) {
			if (cmd[j] == 'R') {
				isReverse = !isReverse;
			}
			else if (cmd[j] == 'D') {
				if (dq.size() == 0) {
					// ��� ������ error�� �ݺ��� Ż��
					cout << "error\n";
					isError = true;
					break;
				}
				else {
					// �ڷ� pop
					if (isReverse) dq.pop_back();
					// ������ pop
					else dq.pop_front();
				}
			}
		}
		// ���� �迭 ���
		if(!isError) printArr(dq, isReverse);
		// ������ �ʱ�ȭ
		isReverse = false;
		dq.clear();
		isError = false;
	}
}