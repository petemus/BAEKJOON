// ���հ� �� > 3.ȸ�翡 �ִ� ���

// [c++ or stl]
// :: (���� ���� ������) -> �ĺ��ڸ� �����ϴ� �� ��� / ����::�ĺ���
// ���� �迭 ���� ������ ����ϴ� �� ex> map[key] = value; (set�� �翬�ϰԵ� �Ұ���)
// map : key ���� �������� ���ĵǾ� ���� / ���� Ž�� Ʈ���� �����ϰ� value�� ã�°�
// unordered_map ���� �����ɸ� O(n)
// unordered_map : ���ĵǾ� ���� ���� �����̳� / hash table �� �����ϰ� value�� ã�� �ð��� ���� �ɸ� O(1)
// @@@@@@@ ������ ������ �� �о� ����! ^^


// sol> ����� �α� ���� ����
// key ���� �̹� ������ ��� ���� ����쵵�� ¥���ҵ�
// ���ĵ� ���¿��� ����ϸ� �ȵ�
// map�� ���� ������� �ؾ��ҵ�.

// sol2> ����� set�� ���� ����ϸ� �� key�� ���쵵��. �׷��� ���� set���� 
// ����� ����� ���� ����.


#include <iostream>
#include <map>
using namespace std;

int main() {

	int n;
	cin >> n;
	// map�� �⺻�� ��������
	// greater<string> �߰��� �������� ����
	map<string, string, greater<string>> log; 
	string key, value;
	for (int i = 0; i < n; i++) {
		cin >> key >> value;
		// �ߺ� Ȯ��
		if (log.count(key)) {
			// �ߺ� �Ǹ� value ����
			// Ȥ�� ����� �ٽ� ���� ����
			log[key] = value;			
		}
		else {
			log.insert(make_pair(key, value));
		}
	}

	// ��ä Ž���ϸ鼭 value ���� enter�� �� key ���
	map<string, string>::iterator iter;
	for (iter = log.begin(); iter != log.end(); iter++) {
		if ((iter->second).compare("enter") == 0) {
			// compare() �Լ��� ���� ������ -> 0 / �ٸ��� -> -1 �� �����Ѵ�.
			cout << iter->first << "\n";
		}

	}

	
}