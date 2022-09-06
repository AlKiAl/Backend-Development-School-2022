#include<fstream>
#include<vector>

using namespace std;

int main() {

	ifstream input("input.txt");
	ofstream output("output.txt");


	int idx_bracket = 0;
	while (input) {

		char cr;
		input.get(cr);
		if (cr == '{' || cr == '}') {

			int count_bracket_in_prefix = 0;

			ifstream input_new("input.txt");
			int idx_input_new = 0;

			while (input_new) {

				char cr;
				input_new.get(cr);

				if (idx_input_new != idx_bracket && (cr == '{' || cr == '}')) {

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
				output << idx_bracket + 1;
				return 0;
			}
			// ______________________________

		}

		++idx_bracket;
	}


	output << -1;
	return 0;
}
