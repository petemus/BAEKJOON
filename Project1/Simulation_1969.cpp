// simulation, greedy > DNA (1966번)
// 풀이 시간 : 30m
// 한글자씩 비교해서 가장 많은 뉴클레오티드로 배정

#include <iostream>
#include <vector>
using namespace std;

int n, m;
int disGo[1000][1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vector<string> dna;
	
	// 입력
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		dna.push_back(s);
	}

	int nucleotide[4][50] = { 0, }; // A C G T : 사전순
	
	// A C G T 세주기 
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			switch (dna[j][i])
			{
			case 'A':
				++nucleotide[0][i];
				break;
			case 'C':
				++nucleotide[1][i];
				break;
			case 'G':
				++nucleotide[2][i];
				break;
			case 'T':
				++nucleotide[3][i];
				break;
			default:
				break;
			}
		}
	}

	char s[51];
	// DNA s 구해주기
	for (int i = 0; i < m; i++)
	{
		int maxIndx = 0;
		int maxNum = 0;
		for (int j = 0; j < 4; j++)
		{
			if (nucleotide[j][i] > maxNum)
			{
				maxNum = nucleotide[j][i];
				maxIndx = j;
			}
		}

		switch (maxIndx)
		{
		case 0 :
			s[i] = 'A';
			break;
		case 1:
			s[i] = 'C';
			break;
		case 2:
			s[i] = 'G';
			break;
		case 3:
			s[i] = 'T';
			break;
		default:
			break;
		}
	}

	// minSum 구해주기
	int minSum = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dna[j][i] != s[i]) ++minSum;
		}
	}

	// 출력
	for (int i = 0; i < m; i++)
	{
		cout << s[i];
	}
	cout << '\n' << minSum;
		
}