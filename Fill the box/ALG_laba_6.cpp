#include <iostream>
#include <cstring>

using namespace std;

int length, width, height, k;
long long cubes[20];

int main() {
	while (cin >> length>> width>> height >> k) {
		memset(cubes, 0, sizeof(cubes));
		for (int i = 0; i < k; i++) {
			cin >> cubes[i];
		}
		long long volume = 1LL * length * width * height;
		long long result = 0;
		for (int i = 20; i >= 0; i--) {
			long long size = 1LL << i;
			long long count = volume / (size * size * size);
			if (count > cubes[i]) {
				count = cubes[i];
			}
			result += count;
			volume -= count * size * size * size;
			if (volume == 0) {
				break;
			}
		}
		if (volume == 0) {
			cout << result << endl;
		}
		else {
			cout << - 1 << endl;
		}
	}
	return 0;
}