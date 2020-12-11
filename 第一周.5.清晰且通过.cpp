#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

char toChr(int number) {
	if (number < 10) {
		return number + '0';
	}
	return number - 10 + 'A';
}

int toNum(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return c - 'A' + 10;
}

string convert(long long number, int radix) {
	bool negative = number < 0;
	number = abs(number);
	string s = "";
	while (number > 0) {
		s += toChr(number % radix);
		number /= radix;
	}
	if (negative) {
		s += '-';
	}
	reverse(s.begin(), s.end());
	return s;
}

long long convert(const string& s, int radix) {
	long long result = 0;
	bool negative = s[0] == '-';
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-') continue;
		result *= radix;
		result += toNum(s[i]);
	}
	if (negative) {
		result *= -1;
	}
	return result;
}

int main() {
	int n;
	string s;
	int m;
	cin >> n >> s >> m;
  if(s[0]!=0)
	cout << convert(convert(s, n), m) << endl;
  else cout<<0;
}
