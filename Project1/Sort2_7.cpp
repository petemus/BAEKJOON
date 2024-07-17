// Sort2 > 7.ī��(11652��)
// ���� ���� ���� ������ �ִ� ī�� ������ ���
// ���� ������ �� ŭ, ������ ������ 10���� ����
// ���� ������ 2^62 -> int ������ ������ �� => long long
// ī���� ���� �ſ� ũ�� ������ �� ���� index�� ��� ���� -> ���� �����ؼ� ���� ���� ���� �������ҵ�

// merge sort ���� -> ��� �Լ� �̿�
// ���� -> ���� -> �պ�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> card;
vector<long long> sorted;

void Merge(int left, int mid, int right) {


	int i = left; // ���� �迭�� ����Ű�� index
	int j = mid + 1; //������ �迭�� ����Ű�� index
	int k = left; // ���ĵ� �迭�� ����Ű�� index

	// ���� ��Ƽ�� ������ ��Ƽ�� �� ����
	while (i < mid + 1 && j < right + 1) {
		if (card[i] < card[j]) {
			sorted[k++] = card[i++];
		}
		else {
			sorted[k++] = card[j++];
		}
	}

	// ������ ä���
	if (i > mid) {
		while (j < right + 1) {
			sorted[k++] = card[j++];
		}
	}
	else {
		while (i < mid + 1) {
			sorted[k++] = card[i++];
		}
	}

	//���ĵ� �迭 �ű��
	for (int i = left; i <= right; i++) {
		card[i] = sorted[i];
	}

}

void MergeSort(int left, int right) {

	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(left, mid);
		MergeSort(mid + 1, right);
		Merge(left, mid, right);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	

	cin >> n;

	long long tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		card.push_back(tmp);
		sorted.push_back(0);
	}

	//����
	//sort(card.begin(), card.end());
	// merge sort
	MergeSort(0, n - 1);

	// ���� ���� �� ���
	long long maxNum = card[0];
	long long prev = card[0];
	int maxCnt = 1;
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (prev != card[i]) {
			// ���� ���� �ƴϸ�
			cnt = 1;
		}
		else {
			// ���� ���̸�
			cnt++;
		}
		if (maxCnt < cnt) { //������ ���� �� ������
			maxCnt = cnt;
			maxNum = prev;
		}
		prev = card[i];
	}
	
	
	cout << maxNum;


}