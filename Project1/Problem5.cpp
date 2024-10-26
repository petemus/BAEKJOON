// ÷�� ������ ���� 
// #����, #�켱���� ť..?
// Ǯ�� �ð� : 20

// ��Ž �ϸ� �ִ� 10^10..?
// ���� ���������� �˸� �� �� ������ -> �׷� �ִ� 10�� ���� �޸� ������ 10�� �ʿ�
// +> �켱 ���� ť ����..?

#include <iostream>
#include <vector>
using namespace std;

// Energy�� ũ�� ���� �迭 
// Time�϶� Energy�� ������ �� Energy�� ���� ȿ���� ������
int Energy[100002] = {0,};

int GetMaxTime(int th, vector<int>& initialEnergy)
{
	// Initial Energy �� ����
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
		// Energy �� ���
		++time;
		EnergySum -= (EnergySize - minusEnergy);

		// �������� �ð��� ���� 0�� �Ǵ� ������ ��� ���س��� 
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