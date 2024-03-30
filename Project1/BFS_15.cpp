// BFS > 15.숨박꼭질4(13913번)
// 큐에다가 부모 노드를 저장하는 걸 추가하면 되지 않을까 -> pop 되면서 값이 손상됨..
// Dangling pointer 문제가 발생함 -> 클래스를 정적이 아닌 동적으로 생성해줘야 함.

// 자식의 부모가 무슨 값인지 저장해도 괜찮음 (B, 값이 중복되지 않ㅇ아서)
// c++ 에서는 구조체랑 클래스랑 거의 차이가 없음

#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
using namespace std;

// 구조체는 클래스가 아니여서 값이 바뀌면 전체가 바뀜
//struct Node {
//	int val;
//	int lev;
//	Node* parent;
//	Node(int v, int l, Node* n) : val(v), lev(l), parent(n) {}
//};

class Node {
public:
	int val;
	int lev;
	Node* parent;
	Node(int v, int l, Node* n) {
		val = v;
		lev = l;
		parent = n;
	}
};

void BFS(int n, int k) {

	// 값, (레벨, 시간)
	queue<Node*> q;
	bool isVisited[200001] = { 0, };
	//vector<Node*> qarr;

	Node* no = new Node(n, 0, nullptr);
	q.push(no);
	//cout << "parent : " << no << "\n";
	//qarr.push_back(&no);
	isVisited[n] = 1;

	int tmpD, tmpL;

	Node* tmp = nullptr;
	int value = 0;
	while (!q.empty()) {
		tmp = q.front();
		//cout << "tmp : " << tmp->val << " lev : " << tmp->lev << "(" << tmp << ")\n";
		if (tmp->val == k) {
			cout << tmp->lev << "\n";
			// 해당 tmp 반환
			break;
		}

		int dirDis[3] = { tmp->val * 2, tmp->val + 1, tmp->val - 1 };
		for (int i = 0; i < 3; i++) {
			tmpD = dirDis[i];
			tmpL = tmp->lev + 1;
			if (tmpD < 0 || tmpD > 200000) continue;
			if (!isVisited[tmpD]) {
				isVisited[tmpD] = 1;
				Node* no = new Node(tmpD, tmpL, tmp);
				//cout << "parent : " << tmp->val << "(" << tmp << ") new: " << no->val << "(" << &no << ")\n";
				q.push(no);
				//qarr.push_back(&no);
			}
		}
		q.pop();
	}

	stack<int> path;
	while(tmp->parent != nullptr) {
		path.push(tmp->val);
		tmp = tmp->parent;
	}
	path.push(n);

	while (!path.empty()) {
		cout << path.top() << " ";
		path.pop();
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int* arr = new int[3];

	int n, k;
	cin >> n >> k;

	BFS(n, k);
}