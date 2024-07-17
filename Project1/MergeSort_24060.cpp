// 알고리즘 수업 - 병합 정렬 1 (24060번)

#include <iostream> 
#include <vector>
using namespace std;

vector<int> arr;
vector<int> sorted;
int saveNum, answerIdx;
int answer = -1;

void Merge(int left, int mid, int right) {


	int i = left; // 왼쪽 배열을 가리키는 index
	int j = mid + 1; //오른쪽 배열을 가리키는 index
	int k = left; // 정렬된 배열을 가리키는 index

	// 왼쪽 파티션 오른쪽 파티션 비교 병합
	while (i < mid + 1 && j < right + 1) {
		if (arr[i] < arr[j]) {
			sorted[k++] = arr[i++];
		}
		else {
			sorted[k++] = arr[j++];
		}
	}

	// 나머지 채우기
	while (j <= right) {
		sorted[k++] = arr[j++];
	}
	while (i <= mid) {
		sorted[k++] = arr[i++];
	}

	//정렬된 배열 옮기기
	for (int i = left; i <= right; i++) {
		arr[i] = sorted[i];
		++saveNum;
		if (saveNum == answerIdx) answer = arr[i];
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n >> answerIdx;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		arr.push_back(t);
		sorted.push_back(t);
	}

	MergeSort(0, arr.size() - 1);

	cout << answer;

}