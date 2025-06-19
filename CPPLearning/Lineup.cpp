#include <iostream>
#include <vector>

#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	vector<int> v = { 8, 4, 5, 9, 1, 2};
	
	cout << count(v.begin(), v.end(), 4) << endl;

	cout << count_if(v.begin(), v.end(), [](int i) { return i > 4; }) << endl;

	v.erase(std::remove_if(v.begin(),
		v.end(),
		[](int i) { return i < 8; }),
		v.end());

	for (int n : v) cout << n << ' ';

	vector<int> V(v.size() - 1);

	transform(v.begin(), v.end() - 1, v.begin() + 1, V.begin(), [](int a, int b) { return a - b; });

	for (int n : V) cout << n << ' ';

	cout << accumulate(V.begin(), V.end(), 0);
}