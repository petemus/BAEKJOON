// Tree > ���� ���� Ʈ��(9934��)
// Ǯ�� �ð�: 2~30m

// Ž�� ��� LrR(���� ��ȸ)�ε� + ��ǻ� ���� ���� Ʈ���� �ƴ϶� ��ȭ���� Ʈ���ε� 
// ��ȭ ����Ʈ���� ��� �� : 2^k -1
// ���� ����Ʈ���� ��� �� : Max = ��ȭ ���� Ʈ���� ���� min = 2^(k-1) ������ �������� �ϳ��� �� ��� 

// point 1 > ��ȸ ������ ���ؼ� ��� Ʈ���� ���� �� ������ -> ��ȸ �ϸ鼭 �� ������ �´� ��� �־��ָ� �ɵ� 

#include <iostream>
#include <vector>
// #include <cmath> // ���ؿ����� ��������� pow() �Լ� ��� ���� 
using namespace std;

int cnt = 0;
int nodeCnt = 0;

// ���ǻ� tree���� 1���� �ֱ� 
vector<int> tree;
vector<int> circuit;

void Inorder(int node)
{

	// ���� ���� �˻�
	if(node > nodeCnt) return;

	// LrR
	Inorder(node *2);
	// ��� �˻�
	tree[node] = circuit[cnt++];
	Inorder(node * 2 + 1);
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> k;

	nodeCnt = pow(2, k) - 1;
	// ���ǻ� tree���� 1���� �ֱ� 
	tree.resize(nodeCnt + 1, -1);
	circuit.resize(nodeCnt, -1);

	// input
	for (int i = 0; i < nodeCnt; ++i)
	{
		cin >> circuit[i];
	}

	// ���� ��ȸ �ϸ鼭 ��� �� �־���

	Inorder(1);

	// output
	int lev = 1;
	for (int i = 1; i <= nodeCnt; ++i)
	{
		cout << tree[i] << " ";
		// ���� ������ ���� 
		if(i == (pow(2, lev) - 1))
		{
			cout << '\n';
			++lev;
		}
	}



}