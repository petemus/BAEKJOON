// ���հ� �� > 8. ���� �ٸ� �κ� ���ڿ��� ����
// ó������ �κ� ������ ������ ���ϴ� ������ ������ �ֳ��ߴµ� �ƴѵ�
// @@ ������ �� ���� ^^

// string::substr(a, b) : a�� ���� �ε���, b �� ���ڿ� ����


// sol1> ���ڿ��� 1~���ڿ��� ũ�⸸ŭ �ڸ� �͵��� ���տ� �������
// ������ �ߺ� ����� ���ϱ� ������ �� ������ ũ�Ⱑ ���� �ٸ� ���ڿ��� ������ ��.


#include <iostream>
#include <set>
using namespace std;

int main() {

	// ���ڿ��� ũ��� �� ���� ���� X
	string str; 
	cin >> str;

	set<string> substrs;
	string tmp;
	for (int i = 0; i < str.size(); i++) {
		for (int j = 1; j <= str.size() - i; j++) {
			tmp = str.substr(i, j);
			//cout << tmp << "\n";
			substrs.insert(tmp);
		}
	}

	cout << substrs.size();
}