// DP > ����� �賶(12865��) -> ���� 
// Ǯ�� �ð� :
//

// 1) Backtracking  -> �ð� �ʰ�
// 2) DP -> ���� ���ذ� �ȵ�

#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	int object[100][2];

	// Input
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> object[i][0] >> object[i][1];
	}

	// DP



	// Output


	// Backtracking
	//Backtracking(0, 0, 0);
	//cout << maxValue;
}

// ------------ Backtracking

//int n, k;
//int object[100][2];		//  ���� w, v ����
//// ���� ������ �ִ���
//bool isHave[100] = { false, };
//int maxValue = 0;
//
//void Backtracking(int thingCnt, int allWeight, int allValue)
//{
//	
//	// object �־��ֱ� 
//	for (int i = 0; i < n; i++)
//	{
//		// ������ ���� ������ ��Ʈ��ŷ
//		if (!isHave[i] && (allWeight + object[i][0]) <= k)
//		{
//			isHave[i] = true;
//			Backtracking(thingCnt + 1, allWeight + object[i][0], allValue + object[i][1]);
//			isHave[i] = false;
//		}
//	}
//
//	// ���� ����
//	// > ���̻� ���� object �� ���� ��
//	// �ִ� ��ġ������ Ȯ��
//	if (allValue > maxValue) maxValue = allValue;
//	return;
//
//}