// 1���������� ���п��� ��ġ�� �κ��� ���� �ּ� ���� ������ ���ϴ� ����
// ! ���� ��ġ�� �ϳ��� �� �������� ����� ���� 
// �׸���, ���� or ��Ž
// Ǯ�� �ð� : 50m ��

// 1) �� ������ �������� ���� -> Compare�Լ� ���� �ʿ�
// 2) ���ĵ� �迭���� �ϳ��� �������鼭 ���� ���ϱ� -> 10�� ���� �ɸ�


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(vector<int> a, vector<int> b)
{
	// �ι�° ��Ұ� ū ������� ����
	// �ι�° ��� ������ ù��° ��Ұ� ū�������
	if (a[1] == b[1])
	{
		return a[0] > b[0];
	}
	else return a[1] > b[1];
}


vector<vector<int>> getMergedLineSegments(vector<vector<int>>& lineSegments)
{
	// lineSegments ����
	sort(lineSegments.begin(), lineSegments.end(), compare);

	// ��� �迭
	vector<vector<int>> reResults;

	// ��ü ���鼭 ��� �迭�� �־���
	int startPoint = lineSegments[0][0];
	int endPoint = lineSegments[0][1];
	for (int i = 1; i < lineSegments.size(); i++)
	{
		// ���� ������ startpoint���� ū��� -> ���� �������̶� startpoint�� ��
		if (startPoint <= lineSegments[i][1])
		{
			if (startPoint > lineSegments[i][0])
			{
				// startPoint ������Ʈ
				startPoint = lineSegments[i][0];
			}
			else
			{
				// starpoint���� ũ�� �Ѿ��
				continue;
			}
		}
		else
		{
			// StartPoint���� ���� ��� -> vector�� �� �־���, startpoint, endPoint ������Ʈ
			vector<int> point = {startPoint, endPoint};
			reResults.push_back(point);
			
			startPoint = lineSegments[i][0];
			endPoint = lineSegments[i][1];
		}
	}
	// ������ ���� �־���� ��
	vector<int> point = { startPoint, endPoint };
	reResults.push_back(point);

	// ���ٷ� ��ȯ
	reverse(reResults.begin(), reResults.end());
	return reResults;
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	


	vector<vector<int>> lineSegments = {{4, 8}, {2, 6}, {5, 7}};

	vector<vector<int>> results = getMergedLineSegments(lineSegments);

	// ���
	cout << "{ ";
	for (int i = 0; i < results.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < results[0].size(); j++)
		{
			cout << results[i][j] << " ";
		}
		cout << "] ";
	}
	cout << " }\n";
}


