//



#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include <string>
#include <map>

// ���ʿ��� ���α׷��� ���ڿ��� ã�� �� �� ���̸� ���� 
// ! ���α׷��� ���ڿ��� ã�� ���� �߿�
// ���� ���α׷��� ���ڿ��� �� �ε��� ������ ������ ���α׷��� ���ڿ��� �� �ε����� ������ ���� ���ֱ� 

//int programmer[7] = {1, 3, 1, 1, 1, 2, 1};
map<char, int> programmerMap = { {'p', 1}, {'r', 3}, {'o', 1}, {'g', 1}, {'a', 1}, {'m', 2}, {'e', 1} };
char programmerChar[7] = { 'p', 'r', 'o', 'g', 'a', 'm', 'e' };

bool isPString(map<char, int>& check)
{
    for (int i = 0; i < 7; i++)
    {
        if (check[programmerChar[i]] < programmerMap[programmerChar[i]]) return false;
    }
    // ��� ���ڰ� programmer���� ���� ��� ���α׷��� ���ڿ�
    return true;
}



int programmerStrings(string s) {

    // programmer
    // p : 1, r: 3, o : 1, g : 1, a : 1, m : 2, e: 1

    map<char, int> leftcheck = { {'p', 0}, {'r', 0}, {'o', 0}, {'g', 0}, {'a', 0}, {'m', 0}, {'e', 0} };
    map<char, int> rightcheck = { {'p', 0}, {'r', 0}, {'o', 0}, {'g', 0}, {'a', 0}, {'m', 0}, {'e', 0} };

    int leftEndIndex = 0;
    // programmer ���ڿ����� Ȯ�� 
    for (int i = 0; i < s.size(); i++)
    {
        if (isPString(leftcheck))
        {
            // programmer ���ڿ��̸� 
            leftEndIndex = i;
            break;
        }
        else
        {
            // ���ڿ� �ƴϸ� ���� ������
            // programmer ���ڿ����� üũ�� 
            if (leftcheck.count(s[i]) > 0)
            {
                // �ִ� ���ڿ��̸� 
                ++leftcheck[s[i]];
            }
        }


    }
    // ������ ���ڿ��� �� �ε��� ã���ֱ� 
    int rightfirstIndex = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (isPString(rightcheck))
        {
            // programmer ���ڿ��̸� 
            rightfirstIndex = i;
            break;
        }
        else
        {
            // ���ڿ� �ƴϸ� ���� ������
            // programmer ���ڿ����� üũ�� 
            if (rightcheck.count(s[i]) > 0)
            {
                // �ִ� ���ڿ��̸� 
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