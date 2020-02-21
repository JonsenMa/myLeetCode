#include<iostream>
#include<map>
#include<string>
#include<stack>

using namespace std;

bool isVaild(string s) {
	map<string, string> map;
	map.insert(pair<string, string>("(", ")"));
	map.insert(pair<string, string>("[", "]"));
	map.insert(pair<string, string>("{", "}"));
	stack<string> stack;

	int size = s.size();
	if (size == 0)
		return true;
	for (int i = 0; i < size; i++){
		string temp = s.substr(i, 1);
		if (map.find(temp) != map.end()){
			stack.push(temp);
		}
		else {
			string top = map[stack.top()];
			if (top == temp) {
				stack.pop();
				continue;
			}
			else
				return false;
		}
	}
	if (stack.empty())
		return true;
	else
		return false;
}

int main() {
	string s;
	cin >> s;
	if (isVaild(s))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
