// Tree > 완전 이진 트리(9934번)
// 풀이 시간: 2~30m

// 탐색 방법 LrR(중위 순회)인듯 + 사실상 완전 이진 트리가 아니라 포화이진 트리인듯 
// 포화 이진트리의 노드 수 : 2^k -1
// 완전 이진트리의 노드 수 : Max = 포화 이진 트리랑 같음 min = 2^(k-1) 마지막 레벨에서 하나만 찰 경우 

// point 1 > 순회 순서를 통해서 어떻게 트리를 구할 수 있을까 -> 순회 하면서 그 순서에 맞는 노드 넣어주면 될듯 

#include <iostream>
#include <vector>
// #include <cmath> // 백준에서는 포함해줘야 pow() 함수 사용 가능 
using namespace std;

int cnt = 0;
int nodeCnt = 0;

// 편의상 tree에는 1부터 넣기 
vector<int> tree;
vector<int> circuit;

void Inorder(int node)
{

	// 종료 조건 검사
	if(node > nodeCnt) return;

	// LrR
	Inorder(node *2);
	// 노드 검사
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
	// 편의상 tree에는 1부터 넣기 
	tree.resize(nodeCnt + 1, -1);
	circuit.resize(nodeCnt, -1);

	// input
	for (int i = 0; i < nodeCnt; ++i)
	{
		cin >> circuit[i];
	}

	// 중위 순회 하면서 노드 값 넣어줌

	Inorder(1);

	// output
	int lev = 1;
	for (int i = 1; i <= nodeCnt; ++i)
	{
		cout << tree[i] << " ";
		// 레벨 단위로 개행 
		if(i == (pow(2, lev) - 1))
		{
			cout << '\n';
			++lev;
		}
	}



}