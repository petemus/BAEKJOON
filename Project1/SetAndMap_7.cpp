// ���հ� �� > 7.��Ī ������
// ��Ī �������� ������ ���ϴ� ����
// ���� A, B�� ���� �� (A - B) + (B - A) �� ��Ī ������.

// sol1> B�� A�� �������� ������ ���ϰ� B�� A�� ���� ������ ���� ���� 2*(������)�� ����
// @@@@ �߿� => A + B - 2(A n B) 
// sol2> setA�� ����� setB�� ���� ���Ұ� ���� ��,
// A�� �ִ� ���Ұ� ������ ��� �����ϰ� A�� ���� ���Ұ� ������ �߰�
// => setA�� ��¥ ��Ī �������� set���� ���� �� ����.

#include <iostream>
#include <set>
using namespace std;

int main() {


	int n, m;
	cin >> n >> m;

	set<int> setA;
	set<int> setB;
	int count = 0;

	//A �Է� ����
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		setA.insert(tmp);
	}
	// B �Է� ���� + A�� ��ġ�� ���� Ȯ��
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		setB.insert(tmp);
		if (setA.count(tmp)) {
			// count() ���� find() �Լ� ���� ����ȭ ����
			// tmp�� A�� ������
			count++;
		}
	}
	int result = 0;
	// ��� ���
	result = setA.size() + setB.size() - 2 * count;
	cout << result;

}