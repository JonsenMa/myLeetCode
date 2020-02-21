/*Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true*/

#include<iostream>
#include<map>
#include<string>
#include<stack>

using namespace std;

bool isVaild(string s) {
	//用map存放所有可能出现的括号组合，左括号为key，右括号为value
	map<string, string> map;
	map.insert(pair<string, string>("(", ")"));
	map.insert(pair<string, string>("[", "]"));
	map.insert(pair<string, string>("{", "}"));
	stack<string> stack;//使用stack依次存入输入的括号字符串

	int size = s.size();
	if (size == 0)
		return true;//边界条件，当没有输入字符串时，认为合法
	for (int i = 0; i < size; i++){
		/*依次判断每个字符，若是map中有的左括号，则将该符号压入栈中，
		若不是map中的左括号，则将栈顶符号与之比较，若为一对，则弹出栈顶符号，直到栈空说明合法；
		若不为一对，则不合法*/
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
