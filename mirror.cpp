#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<char> read_stdin();
bool is_mirror(vector<char>& mir);

//bool result = true;

int main(){
	vector<char> mirror = read_stdin();
	if (is_mirror(mirror))
		cout << "True";
	else
		cout << "False";

}

vector<char> read_stdin() {
	char c;
	vector<char> _vec;
	string line;
	getline(cin, line);
	istringstream iss(line);
	while (iss >> c) {
		_vec.push_back(c);
	}
	return _vec;
}

bool is_mirror(vector<char>& mir) {
	int counter = 0;
	vector<char> temp_one;
	vector<char> temp_two;
	for (unsigned int i = 0; i < mir.size() - 1; i++) {
		temp_one.clear();
		temp_two.clear();
		//counter = 0;
		if (mir[i] != '#') {
			counter = i;
			while (mir[counter] != '#') {
				temp_one.push_back(mir[counter]);
				counter++;
			}
			i = counter;
			if (mir[i] == '#') {
				for (unsigned int j = i + 1; j <= i + temp_one.size() && j < mir.size(); j++) {
					temp_two.push_back(mir[j]);
				}
				i += temp_two.size();
			}
		}
		reverse(temp_two.begin(), temp_two.end());
		for (unsigned int z = 0; z < temp_two.size(); z++) {
			if (temp_one[z] != temp_two[z])
				return false;
		}
	}
	return true;
}