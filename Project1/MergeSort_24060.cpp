// �˰��� ���� - ���� ���� 1 (24060��)

#include <iostream> 
#include <vector>
using namespace std;

vector<int> arr;
vector<int> sorted;
int saveNum, answerIdx;
int answer = -1;

void Merge(int left, int mid, int right) {


	int i = left; // ���� �迭�� ����Ű�� index
	int j = mid + 1; //������ �迭�� ����Ű�� index
	int k = left; // ���ĵ� �迭�� ����Ű�� index

	// ���� ��Ƽ�� ������ ��Ƽ�� �� ����
	while (i < mid + 1 && j < right + 1) {
		if (arr[i] < arr[j]) {
			sorted[k++] = arr[i++];
		}
		else {
			sorted[k++] = arr[j++];
		}
	}

	// ������ ä���
	while (j <= right) {
		sorted[k++] = arr[j++];
	}
	while (i <= mid) {
		sorted[k++] = arr[i++];
	}

	//���ĵ� �迭 �ű��
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