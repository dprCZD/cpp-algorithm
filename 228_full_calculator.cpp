#include "common.h"

const static unordered_map<char, int> OPERATOR_PRIORITY = {
	{'+',0},
	{'-',0},
	{'*',1},
	{'/',1},
	{'^',2},
	{'%',2}
};

class Solution {
public:
	int calculate(string s) {
		trim(s);
		int n = s.size();
		stack<int64_t> nums;
		if (n != 0 && (s[0] == '+' || s[0] == '-')) {
			nums.push(0);
		}
		stack<char> ops;
		for (auto iter = s.begin(); iter != s.end(); ++iter) {
			if (*iter == ' ') {
				continue;
			}
			else if (*iter == '(') {
				ops.push('(');
			}
			else if (*iter == ')') {
				while (ops.top() != '(') {
					calc(nums, ops);
				}
				ops.pop();
			}
			else if (isdigit(*iter)) {
				int64_t num = 0;
				while (iter != s.end() && isdigit(*iter)) {
					num = num * 10 + *iter - '0';
					++iter;
				}
				nums.push(num);
				--iter;
			}
			else {
				if (iter != s.begin() && *(iter - 1) == '(') {
					nums.push(0);
				}
				while (!ops.empty()) {
					char pre = ops.top();
					if (pre != '(' && OPERATOR_PRIORITY.at(pre) >= OPERATOR_PRIORITY.at(*iter)) {
						calc(nums, ops);
					}
					else {
						break;
					}
				}
				ops.push(*iter);
			}
		}
		while (!ops.empty()) {
			calc(nums, ops);
		}
		return nums.top();
	}

	void calc(stack<int64_t>& nums, stack<char>& ops) {
		if (nums.size() < 2 || ops.empty()) {
			return;
		}
		int64_t b = nums.top();
		nums.pop();
		int64_t a = nums.top();
		nums.pop();
		char op = ops.top();
		ops.pop();
		int64_t ans = 0;
		if (op == '+') {
			ans = a + b;
		}
		else if (op == '-') {
			ans = a - b;
		}
		else if (op == '*') {
			ans = a * b;
		}
		else if (op == '/') {
			ans = a / b;
		}
		else if (op == '^') {
			ans = pow(a,b);
		}
		else if (op == '%') {
			ans = a % b;
		}
		else {
			// unreachable code.
		}
		nums.push(ans);
	}

	void trim(string& s)
	{
		int index = 0;
		if (!s.empty())
		{
			while ((index = s.find(' ', index)) != string::npos)
			{
				s.erase(index, 1);
			}
		}
	}
};

//int main() {
//	Solution su;
//	std::cout << su.calculate("1-(     -2)");
//
//}