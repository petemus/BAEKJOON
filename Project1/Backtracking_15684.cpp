// Backtracking > ��ٸ� ����(15684��)
// checkpoint
// 1) �ٸ��� ������� ��� ������
// 2) ���ӵǾ� �ִ� ������ �ٸ��� �θ� �ȵ�

// Backtracking
// �� �� �ٸ� ���� üũ
// �ȵǸ� �ٸ� �� ����
// �ּڰ� ���ϱ� 
// 3 �Ѿ�� �� return + �����ϸ� -1

// ?
// �ٸ��� ���� �����ϴ��� ��� �Ƴ�
// verLine���� �Ǵ� row ������ ���������鼭 
// ����Ǿ� ������ ���� Line�� �� �����̸� ���� 


#include <iostream>
using namespace std;

// ���μ��� ���� �迭 (a, b)�� ǥ�� (a�� ��ġ���� b~b+1 ���̸� ����)
// ���μ� ���� �迭 ũ�� : h * (n -1)�� (�ִ� 270)
// �� 0 : ���� X, �� 1 : ���� 
int horLine[31][10] = { 0, };

int n, m, h;
int minLine = -1;

bool isSuccess()
{
	// i���� ����� i�� �� �������� üũ
	bool isSuccess = true;

	// �� ���� �����ϸ� false ��ȯ
	for (int i = 1; i <= n; i++)
	{
		int nowLine = i;
		for (int j = 1; j <= h; j++)
		{
			
			if (nowLine < n && horLine[j][nowLine])
			{
				// ���� ������ �������� �ű�
				nowLine++;
				continue;
			}

			if (nowLine > 1 && horLine[j][nowLine - 1])
			{
				// ���� ������ �������� �ű�
				nowLine--;
				continue;
			}

		}

		// ������ ������ ���� ������ ����
		if(nowLine != i) return false;
	}
	return true;
}

void Backtracking(int lineCnt, int y, int x)
{
	// ���� ���� 1
	// �߰� �ؾ��ϴ� ���μ��� 3���� ũ�� -1 ����
	if (lineCnt >= 4)
	{
		return;
	}
	// ���� ���� 2
	// ��� ������ i���� i�� ���� ����
	if (isSuccess())
	{
		if(lineCnt < minLine || minLine < 0) minLine = lineCnt;
		return;
	}

	// line �� �� �ִ� ���� ���� �α� 
	for (int i = y; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if(i == y && j == 1) j = x;

			// ���� �Ǿ� ������ continue
			if (j > 1 && horLine[i][j - 1]) continue;
			if(j < n - 1 && horLine[i][j + 1]) continue;
			
			if (!horLine[i][j])
			{
				horLine[i][j] = 1;
				Backtracking(lineCnt + 1, i, j);
				horLine[i][j] = 0;
			}
		}
	}
}


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> n >> m >> h;

	for (int  i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		horLine[a][b] = 1;
	}

	Backtracking(0, 1, 1);

	cout << minLine;
}