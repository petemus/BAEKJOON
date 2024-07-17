// 3¹ø

#include <string>
#include <vector>

using namespace std;

int solution(vector<string> drum) {
    int answer = -1;
    int success = 0;

    for (int n = 0; n < drum.size(); n++) {
        int x = n;
        int y = 0;
        int count = 0;

        while (1) {

            if (drum[y][x] == '#') {
                y++;


            }
            else if (drum[y][x] == '>') {
                x++;


            }
            else if (drum[y][x] == '<') {
                x--;

            }
            else if (drum[y][x] == '*') {
                count++;
                if (count > 1)
                    break;

                y++;
            }

            if (y > drum.size() - 1) {
                success++;
                break;
            }

        }

    }

    answer = success;

    return answer;
}

// 2¹ø

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money, int limit) {
    vector<int> answer;
    int success = 0;
    int fail = 0;
    int remit = limit;
    int consecutive = 0;

    while (1) {

        if (money - remit >= 0) {
            success++;
            consecutive++;
            money -= remit;

            if (fail == 0 && success == 1)
                break;

            if (consecutive > 1)
                break;

        }
        else {
            fail++;
            consecutive = 0;

            if (remit == 1)
                break;
            else
                remit = (remit / 2);
        }
    }



    answer.push_back(success);
    answer.push_back(fail);

    return answer;
}

// 1¹ø

#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int range = 100000000;


    for (int i = 1; i < 10; i++) {
        if (n / range != 0) {
            answer += (n / range);
            n = (n % range);
        }
        range = range / 10;
    }



    return answer;
}