// Simulation > 방 번호 (1475번)
// 풀이 시간 : 13m

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	// 문자열 입력 받고
	// 문자열 문자로 쪼개서 number의 개수 더해줌
	// 마지막에 개수 최대값 만큼 출력

	// number 개수 세주기
	int number[10] = { 0, };
	string s;

	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		// 문자 숫자 바꿔주기
		int n = s[i] - '0';
		number[n]++;
	}

	// 6이나 9 최소화
	int result = number[6] + number[9];
	if (result % 2 == 1) result = result / 2 + 1;
	else result /= 2;
	number[6] = result; number[9] = result;

	int max = 0;
	for (int i = 0; i < 10; i++)
	{
		if (max < number[i]) max = number[i];
	}


	cout << max;




}