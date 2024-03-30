// Backtracking > 6.�ҹ��� ĥ����(1941��)
// �̰� dfs �� �ϴ� �ǰ�?

#include <iostream>
#include<queue>
using namespace std;

queue<pair<int, int>> ppath;
char seats[5][5];
bool isVisited[5][5] = { 0, };
int path[7][2];
int dirR[] = { 0, 0, 1, -1 };
int dirC[] = { 1, -1, 0, 0 };
int princess7 = 0;

void Backtracking(int rindex, int cindex, int dept, int sCnt) {

	//��� ����
	path[dept - 1][0] = rindex;
	path[dept - 1][1] = cindex;
	ppath.push(make_pair(rindex, cindex));

	//���� ����
	if (dept == 7) {
		cout << "����\n";
		princess7++;
		return;
	}

	// ��� ȣ��
	int tmpR, tmpC;
	pair<int, int> tmp;
	bool isDuplicate = false;

	tmp = ppath.front();
	for (int i = 0; i < 4; i++) {
		tmpR = tmp.first + dirR[i];
		tmpC = tmp.second + dirC[i];
		
		cout << "tR tC : " << tmpR << " " << tmpC << '\n';

		if (tmpR < 0 || tmpR > 4 || tmpC < 0 || tmpC > 4) continue;
		if (isVisited[tmpR][tmpC]) continue;
		// path�� �ִ� ������ Ȯ��
		isDuplicate = false;
		for (int j = 0; j < dept; j++) {
			cout << "path " << path[j][0] << " " << path[j][1] << "\n";
			if (path[j][0] == tmpR && path[j][1] == tmpC) {
				cout << "��ħ\n";
				isDuplicate = true;
			}
		}
		cout << "\n";
		if (isDuplicate) continue;

		ppath.push(make_pair(tmpR, tmpC));


		// ��� ȣ�� �ϴ� ����
		if (seats[tmpR][tmpC] == 'S') {
			if ((7 - dept) > (3 - sCnt)) {
				cout << "�� : tmpR tmpC " << tmpR << " " << tmpC << "\n";
				Backtracking(tmpR, tmpC, dept + 1, sCnt + 1);
				isVisited[tmpR][tmpC] = 1;
			}
		}
		else {
			if ((7 - dept) > (4 - sCnt)) {
				cout << "tmpR tmpC " << tmpR << " " << tmpC << "\n";
				Backtracking(tmpR, tmpC, dept + 1, sCnt);
			}
		}
	}




}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// algorithm
	
	// �Է�
	// �̹����� �� �̳� �ߵ���
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> seats[i][j];
		}
	}

	// Backtracking
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (seats[i][j] == 'S') {
				cout << "R: " << i << " C: " << j << "\n";
				isVisited[i][j] = 1;
				Backtracking(i, j, 1, 1);
			}
		}
	}

	cout << princess7;

	//for (int i = 0; i < 5; i++) {
	//	for (int j = 0; j < 5; j++) {
	//		cout << seats[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

}