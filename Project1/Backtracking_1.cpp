// Backtracking > 1.부분수열의 합(1182번)
// Backtracking과 dfs의 차이는 backtracking은 필요하지 않은 부분을 가지치기 해서 잘라내는 반면에
// dfs는 전체 탐색을 한다.

// 입력값 vector에 저장후 정렬
// backtracking ( 합한 값이 S 보다 커지면 back)

//????? 수열 -> 수의 나열 1 2 3 4  /  1 3 2 4 허용?

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int subseq = 0; // 부분 수열의 개수
int n, s;


// 이 문제에서는 dept가 안 쓰임
void Backtracking(int index, int sum, int dept) {
	sum += arr[index];
	// 종료 조건
	if (sum > s && arr[index] > 0) return;  // @@@@ 이 조건 잘 설정하는 게 중요!!!
	else if (sum == s) {
		subseq++;
	}

	for (int i = index + 1; i < n; i++) {
		Backtracking(i, sum, dept + 1);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	// 수열 정렬
	sort(arr.begin(), arr.end());
	// 수열 n 만큼 backtracking
	for (int i = 0; i < n; i++) {
		//cout << arr[i] << " ";
		Backtracking(i, 0, 1);
	}


	cout << subseq;

}