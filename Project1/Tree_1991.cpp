// Tree > 트리 순회(1991번)
// 풀이 시간 : 20~30m

// point 1 > 트리를 어떻게 표현할지, 노드의 이름이 숫자가 아닌 문자 -> But, 알파벳이여서 아스키코드 이용해서 숫자로 표현할 수 있을듯
//		-> 입력이 무작위로 들어옴 -> 노드마다 자식을 가지는 2차원 배열 형태로 저장 
// point 2 > 전위(rLR), 중위(LrR), 후위(LRr) 순회 구현 -> 보통 재귀 방식으로 구현 


#include <iostream>
#include <vector>
using namespace std;

// 알파벳 26자 
// char로 저장해도 됨 
pair<int, int> node[26];

void Preorder(int i)
{
	// 종료 조건 
	if (i < 0)
	{
		// 루트 노드인거임 
		return;
	}

	// rLR
	cout << (char)(i + 'A');
	Preorder(node[i].first);
	Preorder(node[i].second);
}

void Inorder(int i)
{
	// 종료 조건 
	if (i < 0)
	{
		// 루트 노드인거임 
		return;
	}

	// LrR
	Inorder(node[i].first);
	cout << (char)(i + 'A');
	Inorder(node[i].second);
}

void Postorder(int i)
{
	// 종료 조건 
	if (i < 0)
	{
		// 루트 노드인거임 
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

		 // 왼쪽
		 if (left != '.')
		 {
			 node[mid - 'A'].first = left - 'A';
		 }
		 else node[mid - 'A'].first = -1;

		 // 오른쪽
		 if (right != '.')
		 {
		 	node[mid - 'A'].second = right - 'A';
		 }
		 else node[mid - 'A'].second = -1;
	}

	// A는 0
	Preorder(0);
	cout << endl;
	Inorder(0);
	cout << endl;
	Postorder(0);
	cout << endl;

}