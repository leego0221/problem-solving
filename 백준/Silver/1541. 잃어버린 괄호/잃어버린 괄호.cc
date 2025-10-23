#include <iostream>
#include <string>
#include <queue>
using namespace std;

string expr;

// '+', '-', 혹은 제일 마지막 위치에서 멈춤
int parse_num(int &idx) {
	string num;
	while (++idx < expr.length()) {
		if (expr[idx] == '+' || expr[idx] == '-') {
			break;
		}
		num.push_back(expr[idx]);
	}
	return stoi(num);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int idx = 0, tmp_idx = -1, res, minus;
	queue<int> q;
	cin >> expr;
	
	// 맨 앞 숫자 파싱
	while (expr[idx] != '+' && expr[idx] != '-') {
		idx++;
	}
	res = parse_num(tmp_idx);

	// 연산자 확인 후 숫자 파싱
	while (idx < expr.length()) {
		if (expr[idx] == '+') {
			res += parse_num(idx); // 일단 '+' 연산만 결과에 반영
		}
		else if (expr[idx] == '-') {
			minus = parse_num(idx);
			while (expr[idx] == '+') {
				minus += parse_num(idx);
			}
			q.push(minus); // 큐에 '-' 연산할 값을 넣어둠
		}
	}
	
	// 마지막으로 '-' 연산 수행
	while (!q.empty()) {
		res -= q.front();
		q.pop();
	}

	// 최솟값 출력
	cout << res;
	return 0;
}