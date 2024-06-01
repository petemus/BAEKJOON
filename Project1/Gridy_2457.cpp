// Gridy > 공주님의 정원 (2457번)
// 풀이 시간 : 
// 꽃의 지고 피는 조건 잘 봐야하고, 두 조건 모두 불가일떄 0 출력
// ! startDate도 정렬해야하네

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
	// 끝나는 날짜 먼저 비교
	// 같으면 시작 날짜가 더 빠른 거 위에 

	if (d1.second.month == d2.second.month)
	{
		if (d1.second.day == d2.second.day)
		{
			// 시작 날짜 더 빠른 거 비교
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
	// d1 이 더 빠른 날짜이면 참
	if (d1.month == d2.month)
	{
		return d1.day < d2.day;
	}
	else return d1.month < d2.month;
}

bool compareDateEquel(Date d1, Date d2)
{
	// d1 이 더 빠른 날짜이거나 같으면 참
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

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int sm, sd, em, ed;
		cin >> sm >> sd;
		cin >> em >> ed;

		flowers.push_back({ Date(sm, sd), Date(em, ed) });
	}

	// 그리디
	// 1. 꽃들이 지는 날짜 순으로 정렬
	// 2. 최소 꽃 구해줌
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

			// 1) 비교 시작날짜가 시작날짜보다 작거나 같아야함
			// 2) 비교 끝 날짜가 시작날짜보다 커야함 
			if (compareDateEquel(comSDate, sDate) && compareDate(sDate, comEDate))
			{
				// 이럼 flowerCnt 체크 
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
		// 시작 날짜가 끝날짜보다 크면 종료 
		else if (compareDate(eDate, sDate)) break;
	}


	std::cout << flowerCnt;


}