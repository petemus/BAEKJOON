// �ִ� ���� �̱� ����
// ���� DP ����
// #DP , But �Ϲ� �������ε� Ǯ �� ����

#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

#define MAX_INDEX 100001

// memo �ִ� 10�� 
int memo0[MAX_INDEX];		// �ڱ� �ڽ� ������ memo
int memo1[MAX_INDEX];		// �ڱ� �ڽ� ���� memo

int GetMaxScore(vector<int>& array)
{

	// memo �ʱⰪ
	memo0[0] = 0;
	memo1[0] = array[0];

	// 
	for (int i = 1; i < array.size(); i++)
	{	
		// �ڱ� �������̸� ���� index������ �����ؾ���
		memo0[i] = memo1[i - 1];
		// �ڱ� �ڽ� ����
		memo1[i] = max(memo0[i - 1], memo1[i - 1]) + array[i];
	}

	return max(memo0[array.size() - 1], memo1[array.size() - 1]);

}


int main()
{

	vector<int> array = {-3, 2, 4, -1, -2, -5};

	cout << GetMaxScore(array);

}