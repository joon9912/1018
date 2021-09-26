#include <iostream>
#include <string>
using namespace std;

int N, M;

// WB와 BW 일치 여부 확인
string WB[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
};

string BW[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
};

string board[50];

int main() {
	// 8 <= N, M <= 50
	cin >> N >> M;
	
	for (int i = 0; i < N; ++i) {
		cin >> board[i];
	}

	int countWB = 0;
	int countBW = 0;
	int minWB = 2147483647;
	int minBW = 2147483647;
	for (int i = 0; i <= M - 8; ++i) {	
		for (int j = 0; j <= N - 8; ++j) {
			for (int k = 0; k < 8; ++k) {
				for (int l = 0; l < 8; ++l) {
					if (WB[k][l] != board[k + j][l + i]) 
						++countWB;
					if (BW[k][l] != board[k + j][l + i]) 
						++countBW;
				}
			}
			if (minWB > countWB) 
				minWB = countWB;
			if (minBW > countBW)
				minBW = countBW;
			countWB = 0;
			countBW = 0;
		}
	}
	if (minWB > minBW)
		printf("%d\n", minBW);
	else 
		printf("%d\n", minWB);

	return 0;
}