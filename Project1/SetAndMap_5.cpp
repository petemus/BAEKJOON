// ���հ� �� > 5. ���� ī�� 2

// base�� ���� 1�� ��������� �ߺ��� ���ȴٴ� ���� �ٸ���..
// �⺻ set -> �ߺ� ��� X
// multiset -> �ߺ� ���
// sol1> multiset ��� => �ð� �ʰ� ��
// sol12> map�� ����ؼ� value�� ��� �ߺ��Ǵ����� ����
// ���Ǽ� :: count()�� ���� �ӵ��� ������. why???


#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	//multiset<int> cards;
	map<int, int> mapCards;
	int tmp;
	map<int, int>::iterator iter;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		//cards.insert(tmp);
		// map �� []�� ������ �����ؼ� find() �Լ� �� �ᵵ �ɵ�.
		// mapCards[tmp]++; �ص� ����.
		iter = mapCards.find(tmp);
		if (iter != mapCards.end()) {
			// �ߺ� �Ǹ� 
			mapCards[tmp] = (iter->second + 1 );
		}
		else {
			// �ߺ� ���� ������
			mapCards.insert(make_pair(tmp, 1));
		}
	}

	int m;
	cin >> m;
	// map �� []�� ������ �����ؼ� find() �Լ� �� �ᵵ �ɵ�.
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		//cout << cards.count(tmp) << " ";
		iter = mapCards.find(tmp);
		if (iter != mapCards.end()) {
			cout << iter->second << " ";
		}
		else {
			cout << "0 ";
		}
	}
	

}