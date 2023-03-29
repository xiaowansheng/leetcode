#include <iostream>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if (s.length() < 1||s.length()%2!=0) {
            return false;
        }
        const char* str=s.c_str();
        stack<char> stack;
        for (int i = 0; i < s.length(); i++) {
            if (stack.size()>0&&(stack.top()=='('&&str[i]==')'|| stack.top() == '[' && str[i] == ']'|| stack.top() == '{' && str[i] == '}')) {
                stack.pop();
            }
            else {
                stack.push(str[i]);
            }
        }
        return stack.size() == 0 ? true : false;
    }
};
int main20()
{
    string str = "()[]{}";
    Solution* s = new Solution();
    bool flag=s->isValid(str);
    cout << "字符串:" << str << endl;
    cout << "是否括号两两成对：" << flag << endl;
    return 0;
}
