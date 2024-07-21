// Recursion > 사분면(1891번)
// 풀이 시간 :
// ! 존재하지 않는 사분면인 경우 생각해줘야함

// check point
// (1) 자료형 -> 입력 출력 값의 범위를 생각하고 알맞는 자료형을 사용해야함

// Hanoi top check point
// 2^n -1 : 이동횟수
// 범위, 재귀 

// 재귀 
// 1) 종료조건 신경 -> 무한 루프 빠지지 않아야함 + 끝나는 것을 보장해야 함


#include <iostream>
#include <vector>
//#include <math.h>
using namespace std;

int d;
vector<int> dNum;

// 구할 사분면
vector<int> moveNum;
// 구할 인덱스
pair<long long, long long> idx;

// 인덱스 통해서 사분면 구해주기
void findNum(int n, long long i, long long j)
{
	// 종료 조건
	if (n <= 0) return;

	if (idx.first >= i + pow(2, n - 1) && idx.first < i + pow(2, n) && idx.second >= j + pow(2, n - 1) && idx.second < j + pow(2, n))
	{
		// 4분면
		moveNum.push_back(4);
		findNum(n - 1, i + pow(2, n - 1), j + pow(2, n - 1));
	}
	else if (idx.first >= i + pow(2, n - 1) && idx.first < i + pow(2, n) && idx.second >= j && idx.second < j + pow(2, n - 1))
	{
		// 3분면
		moveNum.push_back(3);
		findNum(n - 1, i + pow(2, n - 1), j);
	}
	else if(idx.first >= i && idx.first < i + pow(2, n - 1) && idx.second >= j + pow(2, n - 1) && idx.second < j + pow(2, n))
	{
		// 1분면
		moveNum.push_back(1);
		findNum(n - 1, i, j + pow(2, n - 1));
	}
	else if (idx.first >= i && idx.first < i + pow(2, n - 1) && idx.second >= j && idx.second < j + pow(2, n - 1))
	{
		// 2분면
		moveNum.push_back(2);
		findNum(n - 1, i, j);
	}

}


// 사분면 통해서 인덱스 구해주기 
void findIdx(int n, long long i, long long j)
{
	// 종료 조건 
	if (n == 0)
	{
		idx = { i, j };
		return;
	}

	// 분면에 따라 더해줌 
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

	// dnum의 인덱스 구한후
	// 거기에 x, y(사실상 -y) 더해주고 그 값의 사분면 num 구해주기 
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