// Broute Force > 누울 자리를 찾아라(1652번)
// 풀이 시간 : 10 m 


#include <iostream>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	char cells[100][100];

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> cells[i][j];
		}
	}


	// 전체 탐색 -> 행 탐색 , 열 탐색 
	int rowSeat = 0, colSeat = 0;
	for (int i = 0; i < n; i++)
	{
		int rCell = 0;
		int cCell = 0;
		for (int j = 0; j < n; j++)
		{
			if (cells[i][j] == '.') rCell++;
			else
			{
				if (rCell >= 2) rowSeat++;

				rCell = 0;
			}
			if (cells[j][i] == '.') cCell++;
			else
			{
				if (cCell >= 2) colSeat++;

				cCell = 0;
			}
		}
		if (rCell >= 2) rowSeat++;
		if (cCell >= 2) colSeat++;
	}


	cout << rowSeat << " " << colSeat;
}