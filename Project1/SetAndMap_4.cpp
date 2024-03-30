// ���հ� �� > 4.���¾� ���ϸ� ������ �̴ټ� ��

// [c++/stl]
// auto ���� Ÿ�� > �����ϴ� ���� ���� �ڵ����� Ÿ���� ������
// ����� �ð� ���� ��� ->
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

// sol> ���ϸ� ������ map���� ����� (�̸�) / ��ȣ(1���� ����) , ������ �ȵǰ� ���� ������ ���� -> unordered_map
// ����(value)�� ������ �̸�(key)�� ��µǰ� �̸��� ������ ���ڰ� ��µǾ�� ��
// value�� key�� ã�� ��� ���� ���θ� ��ȸ�ؾ��ϹǷ� ��ȿ�����ε� �ٸ� ����� ������..?
// -> value �� key �� ã������ ���� ��ȸ�ؾ��ؼ� �ð� �ʰ��� O(n^2)�� �ð��ʰ� ���� ��.
// => �ε����� ã�� �迭�� ���� ����ų� 

// ���ڿ��� ���ڷ� ��ȯ�ϴ� ���
// >> 1. isdigit() �Լ� ����ؼ� ��ȸ�ϸ鼭 ���ڿ��� �������� Ȯ��
// >> 2. atoi() �Լ� ��� -> atoi() �Լ��� �Ű������� const char * Ÿ���� �� ( �׷��� string�� char pointer�� �Ѱ��ֱ� ���ؼ� string::c_str() �Լ��� ����ؾ���)
// ������ ��� -> ���� ��ȯ / ������ ��� -> 0 ��ȯ (����: ���� 0�� ��쵵 0�� ��ȯ)
// >> 3. stoi() �Լ� ��� -> atoi() �Լ��� �޸� string�� ���ڷ� �ν�
// but, stoi() �Լ��� ���ڰ� ���ڷ� ��ȯ�� �Ұ����� �� ����ó���� �̷���...
// >> 4. ���ڿ��� ù��° ���ڸ� Ȯ���ص� �� (���ϸ� �̸����� ���ڰ� ���� �����Ƿ�..) => isdigit() �Լ� ��� ����


#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	unordered_map<string, int> dic;
	string* indexDic = new string[n];
	
	//�Է�
	string tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		dic.insert(make_pair(tmp, i + 1));
		indexDic[i] = tmp;
	}

	string* inputs = new string[m];
	unordered_map<string, int>::iterator iter;
	for (int i = 0; i < m; i++) {
		cin >> inputs[i];
	}


	// ���
	for (int i = 0; i < m; i++) {
		if (atoi(inputs[i].c_str())) {
			// �����̸� value�� ���� key ã��
			
			// 1. ��ü ��ȸ
			//for (iter = dic.begin(); iter != dic.end(); iter++) {
			//	if (atoi(inputs[i].c_str()) == iter->second) {
			//		cout << iter->first << "\n";
			//		break; // value �� �ߺ����� �����Ƿ� break �ص� ��.
			//	}
			//}
			
			// 2. �ε��� �迭 ���� �����
			cout << indexDic[atoi(inputs[i].c_str()) - 1] << "\n";
		}
		else {
			// ���ڿ��̸�
			iter = dic.find(inputs[i]);
			cout << iter->second << "\n";
		}
	}

}