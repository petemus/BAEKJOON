//



#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include <string>
#include <map>

// 양쪽에서 프로그래머 문자열을 찾은 후 그 사이를 구함 
// ! 프로그래머 문자열을 찾는 것이 중요
// 왼쪽 프로그래머 문자열의 끝 인덱스 구한후 오른쪽 프로그래머 문자열의 앞 인덱스를 구한후 서로 뺴주기 

//int programmer[7] = {1, 3, 1, 1, 1, 2, 1};
map<char, int> programmerMap = { {'p', 1}, {'r', 3}, {'o', 1}, {'g', 1}, {'a', 1}, {'m', 2}, {'e', 1} };
char programmerChar[7] = { 'p', 'r', 'o', 'g', 'a', 'm', 'e' };

bool isPString(map<char, int>& check)
{
    for (int i = 0; i < 7; i++)
    {
        if (check[programmerChar[i]] < programmerMap[programmerChar[i]]) return false;
    }
    // 모든 문자가 programmer보다 많을 경우 프로그래머 문자열
    return true;
}



int programmerStrings(string s) {

    // programmer
    // p : 1, r: 3, o : 1, g : 1, a : 1, m : 2, e: 1

    map<char, int> leftcheck = { {'p', 0}, {'r', 0}, {'o', 0}, {'g', 0}, {'a', 0}, {'m', 0}, {'e', 0} };
    map<char, int> rightcheck = { {'p', 0}, {'r', 0}, {'o', 0}, {'g', 0}, {'a', 0}, {'m', 0}, {'e', 0} };

    int leftEndIndex = 0;
    // programmer 문자열인지 확인 
    for (int i = 0; i < s.size(); i++)
    {
        if (isPString(leftcheck))
        {
            // programmer 문자열이면 
            leftEndIndex = i;
            break;
        }
        else
        {
            // 문자열 아니면 문자 업뎃뎃
            // programmer 문자열인지 체크후 
            if (leftcheck.count(s[i]) > 0)
            {
                // 있는 문자열이면 
                ++leftcheck[s[i]];
            }
        }


    }
    // 오른쪽 문자열의 앞 인덱스 찾아주기 
    int rightfirstIndex = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (isPString(rightcheck))
        {
            // programmer 문자열이면 
            rightfirstIndex = i;
            break;
        }
        else
        {
            // 문자열 아니면 문자 업뎃뎃
            // programmer 문자열인지 체크후 
            if (rightcheck.count(s[i]) > 0)
            {
                // 있는 문자열이면 
                ++rightcheck[s[i]];
            }
        }
    }

    return rightfirstIndex - leftEndIndex + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	string pstring = "programmer";
	string target = "programmer";

}