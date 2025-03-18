// Tree > Ʈ�� ��ȸ(1991��)
// Ǯ�� �ð� : 20~30m

// point 1 > Ʈ���� ��� ǥ������, ����� �̸��� ���ڰ� �ƴ� ���� -> But, ���ĺ��̿��� �ƽ�Ű�ڵ� �̿��ؼ� ���ڷ� ǥ���� �� ������
//		-> �Է��� �������� ���� -> ��帶�� �ڽ��� ������ 2���� �迭 ���·� ���� 
// point 2 > ����(rLR), ����(LrR), ����(LRr) ��ȸ ���� -> ���� ��� ������� ���� 


#include <iostream>
#include <vector>
using namespace std;

// ���ĺ� 26�� 
// char�� �����ص� �� 
pair<int, int> node[26];

void Preorder(int i)
{
	// ���� ���� 
	if (i < 0)
	{
		// ��Ʈ ����ΰ��� 
		return;
	}

	// rLR
	cout << (char)(i + 'A');
	Preorder(node[i].first);
	Preorder(node[i].second);
}

void Inorder(int i)
{
	// ���� ���� 
	if (i < 0)
	{
		// ��Ʈ ����ΰ��� 
		return;
	}

	// LrR
	Inorder(node[i].first);
	cout << (char)(i + 'A');
	Inorder(node[i].second);
}

void Postorder(int i)
{
	// ���� ���� 
	if (i < 0)
	{
		// ��Ʈ ����ΰ��� 
		return;
	}

	// LRr
	Postorder(node[i].first);
	Postorder(node[i].second);
	cout << (char)(i + 'A');

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	//input
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		 char mid, left, right;
		 cin >> mid >> left >> right;

		 // ����
		 if (left != '.')
		 {
			 node[mid - 'A'].first = left - 'A';
		 }
		 else node[mid - 'A'].first = -1;

		 // ������
		 if (right != '.')
		 {
		 	node[mid - 'A'].second = right - 'A';
		 }
		 else node[mid - 'A'].second = -1;
	}

	// A�� 0
	Preorder(0);
	cout << endl;
	Inorder(0);
	cout << endl;
	Postorder(0);
	cout << endl;

}