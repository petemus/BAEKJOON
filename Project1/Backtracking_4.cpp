// Backtracking > 4.������� ���ġ��(16987��)
// ���� ���� ���� ����
// ��� ������ ���� ����
// �ʹ� ���� ��� �Լ� ȣ�� ����

#include <iostream>
#include <vector>
using namespace std;

int maxCnt = 0;
vector<pair<int, int>> eggs; // first : ������, second: ����(���ݷ�)
int n;


void Backtracking(int leftEgg, int rightEgg, int brokenEgg) {

	//cout << "eggs ";
	//for (int i = 0; i < n; i++) {
	//	cout << eggs[i].first << " ";
	//}
	//cout << '\n';

	//�ް� ����
	//���� ����� �����ų� ������ ����� ���������� pass
	bool isBreak = false;
	if (eggs[leftEgg].first > 0 && eggs[rightEgg].first > 0) {
		eggs[leftEgg].first -= eggs[rightEgg].second;
		eggs[rightEgg].first -= eggs[leftEgg].second;
		//cout << "broken Egg " << eggs[leftEgg].first << " " << eggs[rightEgg].first << '\n';
		if (eggs[leftEgg].first <= 0) brokenEgg++;
		if (eggs[rightEgg].first <= 0) brokenEgg++;
		isBreak = true;
	}
	
	//���� ����
	if (leftEgg + 1 == n) {
		if (brokenEgg > maxCnt) maxCnt = brokenEgg;
		// ��� ��������
		if (isBreak) {
			eggs[leftEgg].first += eggs[rightEgg].second;
			eggs[rightEgg].first += eggs[leftEgg].second;
		}
		return;
	}

	//��� ȣ��
	bool noEgg = true;
	for (int i = 0; i < n; i++) {
		if (i == leftEgg + 1) continue;
		if (eggs[i].first > 0) {
			//cout << "Backtracking " << leftEgg + 1 << " " << i << '\n';
			Backtracking(leftEgg + 1, i, brokenEgg);
			noEgg = false;
		}
	}

	if (noEgg) {
		//cout << "ĥ�� ����\n";
		//cout << "Backtracking " << leftEgg + 1 << " " << 0 << '\n';
		Backtracking(leftEgg + 1, 0, brokenEgg);
	}

	if (isBreak) {
		// ��� ��������
		eggs[leftEgg].first += eggs[rightEgg].second;
		eggs[rightEgg].first += eggs[leftEgg].second;
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// algorithm
	// �Է�
	// Backtracking

	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		eggs.push_back(make_pair(a, b));
	}

	//Backtracking
	for (int i = 1; i < n; i++) {
		//cout << i << "\n";
		//cout << "Backtracking " << 0 << " " << i << '\n';
		Backtracking(0, i, 0);
	}

	cout << maxCnt;

}