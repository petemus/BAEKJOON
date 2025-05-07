// Tree > 이진 검색 트리(5639번)
// 풀이 시간 : 40m?

// 전위 순회 입력값으로 후위 순회의 값으로 출력
// ! 전위 순회로 이진 탐색 트리 만들 수 있을 듯
// => bst 구조를 만드는 게 핵심인듯

// sol1> bst를 직접 만들어서 후위 순회
// sol2> 전위 순회 결과값을 재귀로 어쩌고 해서 후위 순회

#include <iostream>
using namespace std;


struct Node {
	int val;
	Node* left;
	Node* right;

	Node(int v) : val(v), left(nullptr), right(nullptr) 
	{}

};

class BST {

public:
	Node* root = nullptr;


public:
	// 생성자 
	BST(Node* r) : root(r) {}
	BST() {}


// BST 관련 함수들
public:
	// 삽입 함수
	void insert(Node* newNode)
	{
		// root가 없으면 root에 값 넣어주기
		if (root == nullptr)
		{
			root = newNode;
			return;
		}

		// root 값과 비교후 값이 작으면 left 크면 right와 비교하면서 내려가기
		Node* cmpN = root;
		while (cmpN != nullptr)
		{
			if (newNode->val <= cmpN->val)
			{
				// left
				if (cmpN->left != nullptr)
				{
					// nullptr 아니면 그쪽 탐색
					cmpN = cmpN->left;
				}
				else
				{
					// 맞으면 그쪽에 삽입
					cmpN->left = newNode;
					break;
				}

			}
			else
			{
				// right
				if (cmpN->right != nullptr)
				{
					// nullptr 아니면 그쪽 탐색
					cmpN = cmpN->right;
				}
				else
				{
					// 맞으면 그쪽에 삽입
					cmpN->right = newNode;
					break;
				}
			}
		}


	}


};

void postorder(Node* n)
{
	if (n == nullptr)
	{
		return;
	}
	
	// postorder : LRr
	postorder(n->left);
	postorder(n->right);
	cout << n->val << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input;
	// BST 생성
	BST bst = BST();

	// input
	while (cin >> input)
	{
		Node* newNode = new Node(input);
		bst.insert(newNode);
		// ! 이렇게 입력 받으면 내가 직접 종료 해줘야 함 -> ctrl + z , enter
	}

	// 만들어진 BST 바탕으로 후위 탐색 
	postorder(bst.root);

}