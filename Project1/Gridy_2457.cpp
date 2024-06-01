// Gridy > ���ִ��� ���� (2457��)
// Ǯ�� �ð� : 
// ���� ���� �Ǵ� ���� �� �����ϰ�, �� ���� ��� �Ұ��ϋ� 0 ���
// ! startDate�� �����ؾ��ϳ�

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Date
{
	int month;
	int day;
	Date(int month, int day)
	{
		this->day = day;
		this->month = month;
	};
	Date() {};
};


bool compare(pair<Date, Date> d1, pair<Date, Date> d2)
{
	// ������ ��¥ ���� ��
	// ������ ���� ��¥�� �� ���� �� ���� 

	if (d1.second.month == d2.second.month)
	{
		if (d1.second.day == d2.second.day)
		{
			// ���� ��¥ �� ���� �� ��
			if (d1.first.month == d2.first.month)
			{
				return d1.first.day < d2.first.day;
			}
			else return d1.first.month < d2.first.month;
		}
		return d1.second.day > d2.second.day;
	}
	else return d1.second.month > d2.second.month;
}

bool compareDate(Date d1, Date d2)
{
	// d1 �� �� ���� ��¥�̸� ��
	if (d1.month == d2.month)
	{
		return d1.day < d2.day;
	}
	else return d1.month < d2.month;
}

bool compareDateEquel(Date d1, Date d2)
{
	// d1 �� �� ���� ��¥�̰ų� ������ ��
	if (d1.month == d2.month)
	{
		return d1.day <= d2.day;
	}
	else return d1.month < d2.month;
}

int main() 
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	std::cout.tie(NULL);

	int n;

	vector<pair<Date, Date>> flowers;

	// �Է�
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int sm, sd, em, ed;
		cin >> sm >> sd;
		cin >> em >> ed;

		flowers.push_back({ Date(sm, sd), Date(em, ed) });
	}

	// �׸���
	// 1. �ɵ��� ���� ��¥ ������ ����
	// 2. �ּ� �� ������
	sort(flowers.begin(), flowers.end(), compare);

	int flowerCnt = 0;
	Date sDate = Date(3, 1);
	Date eDate = Date(11, 30);

	bool isFind = false;

	while (true)
	{
		Date comSDate, comEDate;
		isFind = false;
		for (int i = 0; i < n; i++)
		{
			comSDate = flowers[i].first;
			comEDate = flowers[i].second;

			// 1) �� ���۳�¥�� ���۳�¥���� �۰ų� ���ƾ���
			// 2) �� �� ��¥�� ���۳�¥���� Ŀ���� 
			if (compareDateEquel(comSDate, sDate) && compareDate(sDate, comEDate))
			{
				// �̷� flowerCnt üũ 
				flowerCnt++;
				sDate = comEDate;
				isFind = true;
				break;
			}
			else continue;
		}

		if (!isFind)
		{
			flowerCnt = 0;
			break;
		}

		if (!isFind)
		{
			flowerCnt = 0;
			break;
		}
		// ���� ��¥�� ����¥���� ũ�� ���� 
		else if (compareDate(eDate, sDate)) break;
	}


	std::cout << flowerCnt;


}