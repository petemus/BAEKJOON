// BFS > 15.���ڲ���4(13913��)
// ť���ٰ� �θ� ��带 �����ϴ� �� �߰��ϸ� ���� ������ -> pop �Ǹ鼭 ���� �ջ��..
// Dangling pointer ������ �߻��� -> Ŭ������ ������ �ƴ� �������� ��������� ��.

// �ڽ��� �θ� ���� ������ �����ص� ������ (B, ���� �ߺ����� �ʤ��Ƽ�)
// c++ ������ ����ü�� Ŭ������ ���� ���̰� ����

#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
using namespace std;

// ����ü�� Ŭ������ �ƴϿ��� ���� �ٲ�� ��ü�� �ٲ�
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

	// ��, (����, �ð�)
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
			// �ش� tmp ��ȯ
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