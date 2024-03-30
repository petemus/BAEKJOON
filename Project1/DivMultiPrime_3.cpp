// 약수, 배수와 소수 2 > 3.분수 합

// @ sol1> 일단 두 분수의 합을 분모를 곱해서 구한 후 구한 분모와 분자의 gcd를 구한후 gcd를 분모 분자에 나누면
// 기약분수 완성 -> 정답 뜸
// ?? sol2> 두 분수의 분모의 lcm을 구하고 분모에 lcm을 나눈 몫과 분자들을 곱하면 완성 -> 틀렸습니다 뜸
// => 더한 값도 약분이 될 수 있음. 즉 오류ㅠㅠ

#include <iostream>
using namespace std;

// 최대 공약수 구하기
int GCD(int a, int b) {
	int gcd = 0;
	for (int i = (a < b) ? a : b; i > 0; i--) {
		if ((a % i == 0) && (b % i == 0)) {
			// 최대 공약수 
			gcd = i;
			return gcd;
		}
	}
}

// 최소 공배수 구해주기
int LCM(int a, int b) {
	// 최대 공약수 구하기
	int gcd = GCD(a, b);
	// 최소 공배수 구해주기
	int lcm = 0;
	lcm = (a / gcd) * (b / gcd) * gcd; // => a * b / gcd;
	return lcm;
}

int main() {

	int a_deno, a_num, b_deno, b_num;
	cin >> a_num >> a_deno;
	cin >> b_num >> b_deno;

	int c_deno, c_num;

	//int lcm = LCM(a_deno, b_deno);
	//c_deno = lcm;
	//c_num = (lcm / a_deno * a_num) + (lcm / b_deno * b_num);

	//cout << c_num << " " << c_deno;

	c_deno = a_deno * b_deno;
	c_num = a_num * b_deno + b_num * a_deno;
	int gcd = GCD(c_num, c_deno);
	c_deno /= gcd;
	c_num /= gcd;
	cout << c_num << " " << c_deno;
}