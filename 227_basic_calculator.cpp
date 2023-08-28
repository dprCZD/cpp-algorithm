#include "common.h"
class Solution {
public:
	static int calculate(string s) {

		deque<char> operatorStack;
		deque<int32_t> numStack;

		auto iter = s.begin();
		while (iter != s.end()) {
			if (*iter == ' ') {
				++iter;
				continue;
			}
			// case num
			else if (*iter >= '0' && *iter <= '9') {
				int32_t num = 0;
				while (iter != s.end() && *iter >= '0' && *iter <= '9') {
					num = num * 10 + *iter - '0';
					++iter;
				}
				numStack.push_front(num);
				if (operatorStack.empty()) {
					continue;
				}
				char ope = operatorStack.front();
				if (ope == '*'||ope == '/') {
					operatorStack.pop_front();
					int32_t num1 = numStack.front();
					numStack.pop_front();
					int32_t num2 = numStack.front();
					numStack.pop_front();
					if (ope == '*') {
						numStack.push_front(num2 * num1);
					}
					else {
						numStack.push_front(num2 / num1);
					}
				}
			}
			else {
				operatorStack.push_front(*iter);
				++iter;
			}
		}
		while (!operatorStack.empty()) {
			char ope = operatorStack.back();
			operatorStack.pop_back();
			int32_t num1 = numStack.back();
			numStack.pop_back();
			int32_t num2 = numStack.back();
			numStack.pop_back();
			if (ope == '+') {
				numStack.push_back(num1 + num2);
			}
			else {
				numStack.push_back(num1 - num2);
			}
		}
		return numStack.front();

	}
};
