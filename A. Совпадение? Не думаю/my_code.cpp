#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	// input
	string A, B;
	cin >> A >> B;

	// solution
	unordered_map <char, int> char_string_A_to_count_char_in_A;

	for (const auto& chr : A) {
		++char_string_A_to_count_char_in_A[chr];
	}

	string C(B.size(), ' ');

	for (size_t i = 0; i < A.size(); ++i) {

		if (A[i] == B[i]) {
			--char_string_A_to_count_char_in_A[B[i]];
			C[i] = 'P';
		}
	}

	for (size_t i = 0; i < A.size(); ++i) {

		if (A[i] != B[i]) {

			if (char_string_A_to_count_char_in_A[B[i]]) {
				--char_string_A_to_count_char_in_A[B[i]];
				C[i] = 'S';
			}
			else {
				C[i] = 'I';
			}

		}
	}

	// output
	cout << C;

	return 0;
}
