// ���� > 9. �ܾ� ����
// �ߺ��Ǵ� ���� vector�� ���� �ʴ� �� �ٽ�.
// -- ��� ���� --
// ���� �ڸ����� ���� ���.
// ���ڸ������� �����ؼ� ù���ڸ� ������ ����

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	else  return a.length() < b.length(); // size()�� ����
}

// ���ڿ������� length() �� �������� ���ڿ� ���̸� �ǹ�
// size()�� string ��ü�� �޸𸮿��� ���� ����ϰ� �ִ� ũ��
// ��������� ���� ���� ������ �� ������... ���� �������� ��Ȯ�� �𸣰���
// vector������ size() �� ���� ������ �ǹ��ϰ�
// capacity()�� vector�� type���� ���� �� �ִ� �޸𸮰� �Ҵ�Ǿ� �ִ� ������ �뷮

int main() {

	int n;
	cin >> n;

	vector<string> arr;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		// find �Լ��� �ش� ���ڿ��� ������ arr.end()�� ��ȯ
		if (find(arr.begin(), arr.end(), str) == arr.end())
			arr.push_back(str);
	}
	// �Ϲ������� ���ڿ� ������ ������
	sort(arr.begin(), arr.end(), compare); 


	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << '\n';
	}

}