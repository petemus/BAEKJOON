// Tree > ���� �˻� Ʈ��(5639��)
// Ǯ�� �ð� : 40m?

// ���� ��ȸ �Է°����� ���� ��ȸ�� ������ ���
// ! ���� ��ȸ�� ���� Ž�� Ʈ�� ���� �� ���� ��
// => bst ������ ����� �� �ٽ��ε�

// sol1> bst�� ���� ���� ���� ��ȸ
// sol2> ���� ��ȸ ������� ��ͷ� ��¼�� �ؼ� ���� ��ȸ

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
	// ������ 
	BST(Node* r) : root(r) {}
	BST() {}


// BST ���� �Լ���
public:
	// ���� �Լ�
	void insert(Node* newNode)
	{
		// root�� ������ root�� �� �־��ֱ�
		if (root == nullptr)
		{
			root = newNode;
			return;
		}

		// root ���� ���� ���� ������ left ũ�� right�� ���ϸ鼭 ��������
		Node* cmpN = root;
		while (cmpN != nullptr)
		{
			if (newNode->val <= cmpN->val)
			{
				// left
				if (cmpN->left != nullptr)
				{
					// nullptr �ƴϸ� ���� Ž��
					cmpN = cmpN->left;
				}
				else
				{
					// ������ ���ʿ� ����
					cmpN->left = newNode;
					break;
				}

			}
			else
			{
				// right
				if (cmpN->right != nullptr)
				{
					// nullptr �ƴϸ� ���� Ž��
					cmpN = cmpN->right;
				}
				else
				{
					// ������ ���ʿ� ����
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
	// BST ����
	BST bst = BST();

	// input
	while (cin >> input)
	{
		Node* newNode = new Node(input);
		bst.insert(newNode);
		// ! �̷��� �Է� ������ ���� ���� ���� ����� �� -> ctrl + z , enter
	}

	// ������� BST �������� ���� Ž�� 
	postorder(bst.root);

}