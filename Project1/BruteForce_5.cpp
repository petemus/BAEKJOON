#include <iostream>
#include <string>
using namespace std;

// ������ ������ Ȯ�����ִ� �Լ�
bool isEndNum(int n) {
	string num_str = to_string(n);
	string endNum = "666";

	// 666�� �����ϰ� ������ �� ��ȯ
	if (num_str.find(endNum) != string::npos) return true;
	else return false;

	//char* str = new char[num_str.length() + 1];
	//num_str.copy(str, num_str.length() + 1);
	//int count = 0;
	//for (int i = 0; i < num_str.length(); i++) {
	//	if (str[i] == '6') count++;
	//}
	//if (count >= 3) return true;
	//else return false;
}

int main() {

	int n;
	cin >> n;

	int order = 0;
	int i = 665;
	while (true) {
		if (order == n) break;
		 //i�� ������ ������ Ȯ��
		 //������ order 1 ����
		i++;
		if (isEndNum(i)) {
			order++;
		}
	}

	cout << i;

}