// 1> 
// Ǯ�� �ð� 15m 



#include <iostream>
#include <vector>
using namespace std;

// �� ������?
// ���� �����̶� ������ ������ ����
// ��(¦) ��(Ȧ) �Ѵ� ����
// ��(Ȧ) ��(Ȧ) ������ ũ�� ����
// �� (¦) ��(¦) ���� ���� -> ���� ũ�� �ø���
// ��(Ȧ) ��(¦) ���� ü����, ũ�� ������

int Moves(vector<int> arr) {

    int left = 0;
    int right = arr.size() - 1;

    int minMove = 0;
    while (left < right)
    {
        // ���� ¦
        if (arr[left] % 2 == 0)
        {
            if (arr[right] % 2 == 0)
            {
                // ������ ¦ -> ���� ũ�� �ø�
                ++left;
            }
            else
            {
                // ������ Ȧ -> ����, �Ѵ� ����
                ++left; --right;
            }
        }
        // ���� Ȧ
        else if (arr[left] % 2 == 1)
        {
            if (arr[right] % 2 == 0)
            {
                // ������ ¦ -> ���� ü����, ũ�� ����, �̵� �� ����
                left++; --right;
                ++minMove;
            }
            else
            {
                // ������ Ȧ -> ������ ���� ������ ũ�� ����
                --right;
            }
        }

    }

    return minMove;

}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


}