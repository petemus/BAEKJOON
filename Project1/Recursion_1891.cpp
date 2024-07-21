// Recursion > ��и�(1891��)
// Ǯ�� �ð� :
// ! �������� �ʴ� ��и��� ��� �����������

// check point
// (1) �ڷ��� -> �Է� ��� ���� ������ �����ϰ� �˸´� �ڷ����� ����ؾ���

// Hanoi top check point
// 2^n -1 : �̵�Ƚ��
// ����, ��� 

// ��� 
// 1) �������� �Ű� -> ���� ���� ������ �ʾƾ��� + ������ ���� �����ؾ� ��


#include <iostream>
#include <vector>
//#include <math.h>
using namespace std;

int d;
vector<int> dNum;

// ���� ��и�
vector<int> moveNum;
// ���� �ε���
pair<long long, long long> idx;

// �ε��� ���ؼ� ��и� �����ֱ�
void findNum(int n, long long i, long long j)
{
	// ���� ����
	if (n <= 0) return;

	if (idx.first >= i + pow(2, n - 1) && idx.first < i + pow(2, n) && idx.second >= j + pow(2, n - 1) && idx.second < j + pow(2, n))
	{
		// 4�и�
		moveNum.push_back(4);
		findNum(n - 1, i + pow(2, n - 1), j + pow(2, n - 1));
	}
	else if (idx.first >= i + pow(2, n - 1) && idx.first < i + pow(2, n) && idx.second >= j && idx.second < j + pow(2, n - 1))
	{
		// 3�и�
		moveNum.push_back(3);
		findNum(n - 1, i + pow(2, n - 1), j);
	}
	else if(idx.first >= i && idx.first < i + pow(2, n - 1) && idx.second >= j + pow(2, n - 1) && idx.second < j + pow(2, n))
	{
		// 1�и�
		moveNum.push_back(1);
		findNum(n - 1, i, j + pow(2, n - 1));
	}
	else if (idx.first >= i && idx.first < i + pow(2, n - 1) && idx.second >= j && idx.second < j + pow(2, n - 1))
	{
		// 2�и�
		moveNum.push_back(2);
		findNum(n - 1, i, j);
	}

}


// ��и� ���ؼ� �ε��� �����ֱ� 
void findIdx(int n, long long i, long long j)
{
	// ���� ���� 
	if (n == 0)
	{
		idx = { i, j };
		return;
	}

	// �и鿡 ���� ������ 
	switch (dNum[d - n])
	{
	case 1:
		findIdx(n - 1, i, j + pow(2, n - 1));
		break;
	case 2:
		findIdx(n - 1, i, j);
		break;
	case 3:
		findIdx(n - 1, i + pow(2, n - 1), j);
		break;
	case 4:
		findIdx(n - 1, i + pow(2, n - 1), j + pow(2, n - 1));
		break;
	default:
		break;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> d >> s;
	for (int i = 0; i < s.size(); i++)
	{
		dNum.push_back(s[i] - '0');
	}

	// |x| <= 2^50
	long long x, y;
	cin >> x >> y;

	// dnum�� �ε��� ������
	// �ű⿡ x, y(��ǻ� -y) �����ְ� �� ���� ��и� num �����ֱ� 
	findIdx(d, 0, 0);
	
	idx.first -= y;
	idx.second += x;

	findNum(d, 0, 0);
	
	if (moveNum.size() == d)
	{
		for (int i = 0; i < d; i++) cout << moveNum[i];
	}
	else cout << -1;

	
}