// Brute Force, Stack  > â�� �ٰ��� (2304��)
// Ǯ�� �ð� : 10 18
// ! ������ �κ��� ������ �ȵ� -> ������ �κ��� �Ʒ��� �������ٰ� �ö󰡾��� => ������ ���̰� �������� ������ ���������� ����
// �������� �߰��� ������ ���� ū ����� ������ �� ��ձ��� �� ��տ� ������� => ���� ���� ��� �������� ��Ī
// @ �ڵ带 �ݺ��� ������ ������ ���� 
// !������ ���� �����̿��� �ִ� ������ ��ġ�� �׻� �������� �������� ����

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
        // ���� ��� �� ��� ã���ֱ�
        if (l < startPillar) startPillar = l;
        if (l > endPillar) endPillar = l;
        if (h > maxTall) // �׻� ���ʿ� �ִ� ���� �������� ����
        {
            tallPillar = l;
            maxTall = h;
        }
    }


    // ���� ��պ��� �� ��ձ��� Ž��
    // ����� �� ������ ���� ���ֱ�
    // ū ����� �������� ��Ī 
    int bigPillar = 0;
    int smallPillCnt = 0;
    int area = 0;

    for (int i = startPillar; i <= tallPillar; i++)
    {
        if (pillars[i] <= pillars[bigPillar])
        {
            // ī��Ʈ ���ֱ�
            ++smallPillCnt;
            if (i == tallPillar)
            {
                area += pillars[bigPillar] * smallPillCnt;
            }
        }
        else
        {
            // ū pillar ������ ���� �ʱ�ȭ + area ���ֱ�
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
            // ī��Ʈ ���ֱ�
            ++smallPillCnt;

            if (i == tallPillar + 1)
            {
                if (smallPillCnt > 0) area += pillars[bigPillar] * smallPillCnt;
            }
        }
        else
        {
            // ū pillar ������ ���� �ʱ�ȭ + area ���ֱ�
            if(smallPillCnt > 0) area += pillars[bigPillar] * smallPillCnt;
            bigPillar = i;
            area += pillars[bigPillar];
            smallPillCnt = 0;
        }
    }
    

    cout << area;
    
}