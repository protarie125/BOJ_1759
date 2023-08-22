#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int l, c;
vector<char> chars;
vector<char> ans;

int vct;
int cct;

void solve(int b) {
	if (l == ans.size()) {
		if (1 <= vct && 2 <= cct) {
			for (const auto& x : ans) {
				cout << x;
			}
			cout << '\n';
		}

		return;
	}

	for (auto i = b; i < c; ++i) {
		ans.push_back(chars[i]);
		if ('a' == chars[i] || 'e' == chars[i] ||
			'i' == chars[i] || 'o' == chars[i] ||
			'u' == chars[i]) {
			++vct;
		}
		else {
			++cct;
		}

		solve(i + 1);

		ans.pop_back();
		if ('a' == chars[i] || 'e' == chars[i] ||
			'i' == chars[i] || 'o' == chars[i] ||
			'u' == chars[i]) {
			--vct;
		}
		else {
			--cct;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> l >> c;

	chars = vector<char>(c);
	for (auto&& x : chars) {
		cin >> x;
	}

	sort(chars.begin(), chars.end());

	ans.reserve(4);
	vct = 0;
	cct = 0;

	solve(0);

	return 0;
}