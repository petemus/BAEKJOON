// Sort2 > 7.카드(11652번)
// 가장 많은 수를 가지고 있는 카드 정수를 출력
// 수의 범위가 개 큼, 숫자의 개수는 10만개 이하
// 수의 범위가 2^62 -> int 형으로 부족할 듯 => long long
// 카드의 수가 매우 크기 떄문에 그 수를 index로 사용 못함 -> 수를 정렬해서 가장 많은 수를 세워야할듯

// merge sort 구현 -> 재귀 함수 이용
// 분할 -> 정복 -> 합병

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> card;
vector<long long> sorted;

void Merge(int left, int mid, int right) {


	int i = left; // 왼쪽 배열을 가리키는 index
	int j = mid + 1; //오른쪽 배열을 가리키는 index
	int k = left; // 정렬된 배열을 가리키는 index

	// 왼쪽 파티션 오른쪽 파티션 비교 병합
	while (i < mid + 1 && j < right + 1) {
		if (card[i] < card[j]) {
			sorted[k++] = card[i++];
		}
		else {
			sorted[k++] = card[j++];
		}
	}

	// 나머지 채우기
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

	//정렬된 배열 옮기기
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

	//정렬
	//sort(card.begin(), card.end());
	// merge sort
	MergeSort(0, n - 1);

	// 가장 많은 수 계산
	long long maxNum = card[0];
	long long prev = card[0];
	int maxCnt = 1;
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (prev != card[i]) {
			// 같은 수가 아니면
			cnt = 1;
		}
		else {
			// 같은 수이면
			cnt++;
		}
		if (maxCnt < cnt) { //마지막 수를 비교 안해줌
			maxCnt = cnt;
			maxNum = prev;
		}
		prev = card[i];
	}
	
	
	cout << maxNum;


}