// 정렬 > 11. 죄표 압축
// 그냥 find() 함수를 사용할 경우 -> 시간 초과
// lower_bound() 함수 사용 : 찾으려는 key 값보다 같거나 큰 값이
// 언제 처음 등장하는지 알 수 있음
// find() 함수와 마찬가지로 iterator begin()을 뺴주어야 함.
// lower_bound() 만 사용 -> 실패
// 아예 find() 함수는 안 사용하는 게 좋은 듯
// erase()와 unique() 함수 사용
// erase(x,y) : x ~ y 값 제거
// unique(x,y) : x ~ y 까지 중복된 값이 나온 값을 하나 빼고 맨 뒤로 보내고 그 인덱스 반환

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int n;
	cin >> n;
	int* inputs = new int[n];
	vector<int> vec;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		inputs[i] = tmp;
		// 겹치지 않으면 push
		vec.push_back(tmp);
	}
	// 정렬
	sort(vec.begin(), vec.end());
	// erase() 함수와 unique() 함수 사용
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0; i < n; i++) {
		tmp = inputs[i];
		// 이진 탐색을 알고리즘 사용하면 ez (정렬된 상태에서 사용)
		cout << (lower_bound(vec.begin(), vec.end(), tmp) - vec.begin()) << ' ';
	}

}