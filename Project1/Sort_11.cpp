// ���� > 11. ��ǥ ����
// �׳� find() �Լ��� ����� ��� -> �ð� �ʰ�
// lower_bound() �Լ� ��� : ã������ key ������ ���ų� ū ����
// ���� ó�� �����ϴ��� �� �� ����
// find() �Լ��� ���������� iterator begin()�� ���־�� ��.
// lower_bound() �� ��� -> ����
// �ƿ� find() �Լ��� �� ����ϴ� �� ���� ��
// erase()�� unique() �Լ� ���
// erase(x,y) : x ~ y �� ����
// unique(x,y) : x ~ y ���� �ߺ��� ���� ���� ���� �ϳ� ���� �� �ڷ� ������ �� �ε��� ��ȯ

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int n;
	cin >> n;
	int* inputs = new int[n];
	vector<int> vec;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		inputs[i] = tmp;
		// ��ġ�� ������ push
		vec.push_back(tmp);
	}
	// ����
	sort(vec.begin(), vec.end());
	// erase() �Լ��� unique() �Լ� ���
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0; i < n; i++) {
		tmp = inputs[i];
		// ���� Ž���� �˰��� ����ϸ� ez (���ĵ� ���¿��� ���)
		cout << (lower_bound(vec.begin(), vec.end(), tmp) - vec.begin()) << ' ';
	}

}