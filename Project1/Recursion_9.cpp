// Recursion > 9.�� ��� - 11(2448��)

// N�� �ִ� 3072

// ex) n = 3 => n�� ����
//     *
//    * *
//   *****
//  n=       3,            6,             12
// �غ� ���� 5( 3+ 3 - 1), 11(6 + 6 - 1), 23, ...

#include <iostream>
using namespace std;

// ó�� �ʱ�ȭ�� 0�� ����
char arr[3072][6143];

void star(int n, int midY, int midX ) {

	// ���� ���� k = 1
	if (n == 3) {
		arr[midY][midX] = '*';
		arr[midY + 1][midX + 1] = '*';
		arr[midY + 1][midX - 1] = '*';
		for (int i = midX - 2; i < midX + 3; i++) arr[midY + 2][i] = '*';
		return;
	}

	// 3�� �ݺ� 
	// �׻� �߽��� �������� �ؼ� +
	star(n / 2, midY, midX);
	star(n / 2, midY + n / 2, midX - (n / 2));
	star(n / 2, midY + n / 2, midX + (n / 2));

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	fill(&arr[0][0], &arr[3071][6143], ' ');

	star(n, 0, n - 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2 - 1; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}


}