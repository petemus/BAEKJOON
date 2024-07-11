//문자열 압축 해제
//시간 제한 : 1초
//엘리스 토끼는 문자열을 직접 압축 해제하려고 합니다.
//압축되지 않은 문자열 S가 주어졌을 때, 이 문자열 중 어떤 부분 문자열은 K(Q)와 같이 압축할 수 있습니다.이것은 Q라는 문자열이 K 번 반복된다는 뜻입니다.K는 한 자릿수의 정수이고, Q는 0자리 이상의 문자열입니다.
//예를 들면, 53(8)은 다음과 같이 압축을 해제할 수 있습니다.
//53(8) = 5 + 3(8) = 5 + 888 = 5888
//압축된 문자열이 주어졌을 때, 이 문자열을 다시 압축을 푸는 프로그램을 작성하세요.

// category : stack, 문자열 
// 풀이 시간 : 30m
// !실제로 문자가 무엿인지 알 필요 없음 -> 길이만 계산해주면 됨 

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	cin >> input;

	stack<char> stk;
	// 압축 푼 문자열의 길이 
	int len = 0;
	for (int i = 0; i < input.size(); i++)
	{
		// )이면 팝
		// ( 와 숫자면 put
		if (input[i] != ')') stk.push(input[i]);
		else
		{
			// 1) 쌍찾기
			// 2) 길이 계산해주기 (기존에 갖고 있는 길이 더해줌)
			// 3) 압축 풀어줌 
			while (!stk.empty())
			{
				char c = stk.top();
				stk.pop();
				// 끝 괄호만나면 break 숫자 만나면 길이 세주기
				if (c == '(') break;
				else ++len;
			}
			// 곱해줌(압축해제)
			if (!stk.empty())
			{
				char c = stk.top(); stk.pop();
				if (c <= '9' && c >= '0') len = len * (c - '0');
			}
		}
	}

	// 마지막 계산 
	while (!stk.empty())
	{
		char c = stk.top(); stk.pop();
		if (c <= '9' && c >= '0') ++len;
	}

	cout << len;
}