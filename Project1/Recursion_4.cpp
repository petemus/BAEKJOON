// Recursion > 4.����Լ��� ������?(17478��)

// �����...��
// f10 ,f11


#include <iostream>
using namespace std;

// �̰� ����..

void Indent(int k) {
	for (int i = 0; i < k; i++) cout << "____";
}

void chat(int n, int k) {
	Indent(k);
	cout << "\"����Լ��� ������?\"\n";
	if (n == 0) {
		Indent(k);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
		Indent(k);
		cout << "��� �亯�Ͽ���.\n";
	}
	else {
		Indent(k);
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		Indent(k);
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		Indent(k);
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		chat(n - 1, ++k);
		Indent(--k);
		cout << "��� �亯�Ͽ���.\n";
	};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	chat(n, 0);



}