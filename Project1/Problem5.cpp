// 첨단 발전소 문제 
// #구현, #우선순위 큐..?
// 풀이 시간 : 20

// 완탐 하면 최대 10^10..?
// 언제 낮아질지만 알면 될 것 같은데 -> 그럼 최대 10만 정도 메모리 공간도 10만 필요
// +> 우선 순위 큐 문제..?

#include <iostream>
#include <vector>
using namespace std;

// Energy의 크기 저장 배열 
// Time일때 Energy가 있으면 그 Energy는 이제 효용이 없어짐
int Energy[100002] = {0,};

int GetMaxTime(int th, vector<int>& initialEnergy)
{
	// Initial Energy 에 저장
	long long EnergySum = 0;
	for (int i = 0; i < initialEnergy.size(); i++)
	{
		++Energy[initialEnergy[i]];
		EnergySum += initialEnergy[i];
	}

	int time = 0;
	int minusEnergy = 0;
	int EnergySize = initialEnergy.size();
	while (EnergySum >= th)
	{
		// Energy 합 계산
		++time;
		EnergySum -= (EnergySize - minusEnergy);

		// 에너지가 시간에 따라 0이 되는 에너지 계속 더해나감 
		minusEnergy += Energy[time];
	}

	return time - 1;

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int th = 9;
	vector<int> initialEnergy = {4, 8, 7, 1, 2, 11, 5};

	cout << GetMaxTime(th, initialEnergy);

}