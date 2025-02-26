// ��Ž, ��Ʈ��ŷ, hash > ī�� ���� (5568��)
// Ǯ�� �ð� : 30m


// point 1> �� ����� -> ��Ž, ��Ʈ��ŷ���� ����
// point 2> �ߺ� üũ -> ������ ũ�Ⱑ �۾Ƽ� ��Ž ����, (set, map) ��� 
// point 3> ���ڸ� ��� ī��ó�� �̿�? => ���ڿ� �̿� (���ڿ��� �޾Ƽ� ���ϴ� ������)


#include <iostream>
#include <unordered_set>
using namespace std;


int numCnt = 0;
int n, k;

string cards[11];
bool isUsed[11] = {false,};
unordered_set<string> uset;


void Backracking(string c, int cnt)
{
	if (cnt >= k)
	{
		// �ش� ���ڿ��� �ִ��� üũ
		if (uset.find(c) == uset.end())
		{
			// ������ set�� �ֱ�
			uset.insert(c);
			++numCnt;
		}
		return;
	}

	// Backtracking
	for (int i = 0; i < n; ++i)
	{
		if (!isUsed[i])
		{
			// �湮 �������� Backtracking
			isUsed[i] = true;
			Backracking(c + cards[i], cnt + 1);
			isUsed[i] = false;
		}
	}


}


int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		cards[i] = s;
	}


	// Backtracking
	Backracking("", 0);

	cout << numCnt;

}