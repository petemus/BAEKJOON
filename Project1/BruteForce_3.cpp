// ������ ���� �����Դϴ�.
#include <iostream>
using namespace std;

int main() {

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	// x ���ϴ� ��   - (ce - fb)/(bd - ea)
	// y ���ϴ� �� (cd - fa) / (bd - ea)

	int bunmo = 0;
	bunmo = (b * d) - (e * a);
	int x, y;
	x =  - (c * e - f * b) / bunmo;
	y = (c * d - f * a) / bunmo;
	cout << x << ' ' << y;

}