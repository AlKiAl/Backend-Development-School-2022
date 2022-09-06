// интересный момент в 93 строке
#include<iostream>
#include<unordered_map>
#include<vector>
#include<sstream> // stringstream
#include<algorithm> // sort
#include<set>

using namespace std;

struct Person {
	string ID;
	int rating = 0;
	int penalty = 0;
};

bool comp(const Person& first, const Person& second) {

	if (first.rating == second.rating) {
		return first.penalty < second.penalty;
	}
	
		return first.rating > second.rating;
}

int main() {

	int n;
	cin >> n;

	unordered_map <string, int>s_i_to_m_i;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		stringstream ss(str);

		while (ss.good()) {
			string s_i;
			getline(ss, s_i, ',');

			string m_i;
			getline(ss, m_i);

			s_i_to_m_i[s_i] = stoi(m_i);
		}

	}

	int k;
	cin >> k;

	unordered_map <string, vector<Person>>s_i_to_Person;
	for (int i = 0; i < k; ++i) {

		string str;
		cin >> str;
		stringstream ss(str);

		while (ss.good()) {
			string c_j;
			getline(ss, c_j, ',');

			string q_j; // == s_i
			getline(ss, q_j, ',');

			string r_j;
			getline(ss, r_j, ',');
			int r_j_int_ = stoi(r_j);

			string p_j;
			getline(ss, p_j);
			int p_j_int_ = stoi(p_j);

			s_i_to_Person[q_j].push_back({ c_j , r_j_int_ , p_j_int_ });
		}

	}

	for (auto& [key, value] : s_i_to_Person) {
		sort(value.begin(), value.end(), comp);
	}

	//for (auto& [key, value] : s_i_to_Person) {
	//	cout << key << '\n';
	//	for (const auto person : value) {
	//		cout << person.ID << ' ' << person.rating << ' ' << person.penalty << '\n';
	//	}
	//}
	
	multiset <string> ans;
	for (const auto& [s_i, m_i] : s_i_to_m_i) {
		const vector<Person> x = s_i_to_Person[s_i];
		const int count = (m_i < x.size()) ? m_i : x.size();
		for (int i = 0; i < count; ++i) {
			
			ans.insert(x[i].ID);
		}

	}


	for (const auto& name : ans) {
		cout << name << '\n';
	}
	return 0;
}
