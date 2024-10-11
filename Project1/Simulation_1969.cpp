// simulation, greedy > DNA (1966��)
// Ǯ�� �ð� : 30m
// �ѱ��ھ� ���ؼ� ���� ���� ��Ŭ����Ƽ��� ����

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
	
	// �Է�
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		dna.push_back(s);
	}

	int nucleotide[4][50] = { 0, }; // A C G T : ������
	
	// A C G T ���ֱ� 
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
	// DNA s �����ֱ�
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

	// minSum �����ֱ�
	int minSum = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dna[j][i] != s[i]) ++minSum;
		}
	}

	// ���
	for (int i = 0; i < m; i++)
	{
		cout << s[i];
	}
	cout << '\n' << minSum;
		
}