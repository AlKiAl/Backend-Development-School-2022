#include<fstream>
#include<vector>

using namespace std;

int main() {

	ifstream input("input.txt");
	ofstream output("output.txt");

	vector <int> indexes_brackets;
	int idx = 0;
	while (input) { // while (input.is_open()) { // error!?

		char cr;
		input.get(cr);
		if (cr == '{') {
			indexes_brackets.push_back(idx);
		}
		if (cr == '}') {
			indexes_brackets.push_back(idx);
		}
		++idx;
	}

	for (int i = 0; i < indexes_brackets.size(); ++i) {
		int count_bracket_in_prefix = 0;

		ifstream input_new("input.txt");
		int idx_input_new = 0;

		while (input_new) {

			char cr;
			input_new.get(cr);

			if (idx_input_new != indexes_brackets[i] && (cr == '{' || cr == '}')) {

				// check_cbs
				// ______________________________
				count_bracket_in_prefix += (cr == '{' ? +1 : -1);

				if (count_bracket_in_prefix < 0) {
					break;

				}
				// ______________________________

			}

			++idx_input_new;
		}

		// check_cbs
		// ______________________________
		if (count_bracket_in_prefix == 0) {
			output << indexes_brackets[i] + 1;
			return 0;
		}
		// ______________________________
	}

	output << -1;
	return 0;
}
