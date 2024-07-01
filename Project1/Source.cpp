// Brute Force, Stack  > 창고 다각형 (2304번)
// 풀이 시간 : 10 18
// ! 오목한 부분이 있으면 안됨 -> 오목한 부분은 아래로 내려갔다가 올라가야함 => 지붕의 높이가 낮아지는 구간은 끝구간에만 가능
// 내려갈때 중간에 마지막 보다 큰 기둥이 있으면 그 기둥까지 그 기둥에 맞춰야함 => 제일 높은 기둥 기준으로 대칭
// @ 코드를 반복문 밖으로 뺄때는 조심 
// !들어오는 값이 랜덤이여서 최대 높이의 위치가 항상 왼쪽임을 보장하지 않음

#include <iostream>
using namespace std;


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; 
    cin >> n;

    int pillars[1001] = { 0, };
    int startPillar = 1000, endPillar = 0;
    int tallPillar, maxTall = 0;
    for (int i = 0; i < n; i++)
    {
        int l, h;
        cin >> l >> h;
        pillars[l] = h;
        // 시작 기둥 끝 기둥 찾아주기
        if (l < startPillar) startPillar = l;
        if (l > endPillar) endPillar = l;
        if (h > maxTall) // 항상 왼쪽에 있는 것을 보장하지 않음
        {
            tallPillar = l;
            maxTall = h;
        }
    }


    // 시작 기둥부터 끝 기둥까지 탐색
    // 기둥이 더 작으면 개수 세주기
    // 큰 기둥을 기점으로 대칭 
    int bigPillar = 0;
    int smallPillCnt = 0;
    int area = 0;

    for (int i = startPillar; i <= tallPillar; i++)
    {
        if (pillars[i] <= pillars[bigPillar])
        {
            // 카운트 세주기
            ++smallPillCnt;
            if (i == tallPillar)
            {
                area += pillars[bigPillar] * smallPillCnt;
            }
        }
        else
        {
            // 큰 pillar 만나면 변수 초기화 + area 세주기
            if (smallPillCnt > 0) area += pillars[bigPillar] * smallPillCnt;
            bigPillar = i;
            area += pillars[bigPillar];
            smallPillCnt = 0;
        }
    }

    //
    bigPillar = 0;
    smallPillCnt = 0;
    for (int i = endPillar; i > tallPillar; i--)
    {
        if (pillars[i] <= pillars[bigPillar])
        {
            // 카운트 세주기
            ++smallPillCnt;

            if (i == tallPillar + 1)
            {
                if (smallPillCnt > 0) area += pillars[bigPillar] * smallPillCnt;
            }
        }
        else
        {
            // 큰 pillar 만나면 변수 초기화 + area 세주기
            if(smallPillCnt > 0) area += pillars[bigPillar] * smallPillCnt;
            bigPillar = i;
            area += pillars[bigPillar];
            smallPillCnt = 0;
        }
    }
    

    cout << area;
    
}