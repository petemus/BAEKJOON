// Simulation > 8.트럭(13335번)

#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int truck[1001] = { 0, };
	int bridge[101] = { 0, };

	int n, w, maxWeight; // 1000, 100, 1000

	// 입력
	cin >> n >> w >> maxWeight;
	for (int i = 0; i < n; i++) {
		cin >> truck[i];
	}


	int bridgeWeight = 0;
	int time = 0;
	// truck 배열의 첫번쨰 원소가 0일때 종료 + bridge에 트럭이 없을 때 -> 트럭이 다 건너면 종료
	while (true) {
		if (truck[0] == 0 && bridgeWeight == 0) break;

		// 다리 건너기
		for (int i = w - 1; i >= 0; i--) {
			if (bridge[i] != 0) {
				// 트럭이 있으면 한칸씩 이동
				if (i == w - 1) {
					// 트럭이 맨끝에 있으면 무게 뺴기
					bridgeWeight -= bridge[i];
					bridge[i] = 0;
				}
				bridge[i + 1] = bridge[i];
				bridge[i] = 0;
			}
		}

		// truck 한칸씩 옮기기
		// 맨 처음 있는 트럭 먼저 계산
		if (truck[0] + bridgeWeight <= maxWeight) {
			// 트럭이 건널 수 있으면 이동
			bridgeWeight += truck[0];
			bridge[0] = truck[0];
			truck[0] = 0;
			// 트럭이 이동하면 다음 트럭들도 한칸씩 이동
			for (int i = 1; i < n; i++) {
				if (truck[i] != 0) {
					// 트럭이 있으면 한칸씩 이동
					truck[i - 1] = truck[i];
					truck[i] = 0;
				}
			}
		}
		

		time++;

		//cout << "트럭 : ";
		//for (int i = 0; i < n; i++) {
		//	cout << truck[i] << " ";
		//}
		//cout << "\n";
		//cout << "다리 : ";
		//for (int i = 0; i < w; i++) {
		//	cout << bridge[i] << " ";
		//}
		//cout << "\n";
	}

	cout << time;


}