

/*

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
*/


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> nums ;
        nums.reserve(tokens.size());
        for(string & s : tokens)
            {
                char x = s[0];
                if(x == '+' || x == '-' || x == '*' || x=='/')
                {
                    int a = nums.back();
                    nums.pop_back();
                    int b= nums.back();
                    nums.pop_back();
                    switch (x)
                    {
                    case '+':
                    a += b;
                    break;
                    case '-':
                    a-= b;
                    break;
                    case '*':
                    a*=b;
                    break;
                    case '/':
                    a/= b;
                    break;
                    }
                    nums.push_back(a);
                }
                else{
                    nums.push_back(stoi(s));
                }
            }
        return nums.back();
    }
};


//optimized code to run faster, with no overheads:

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int st[10000];      // max tokens = 10^4
        int top = -1;

        for (const string& s : tokens) {
            // Check if token is a single-character operator
            if (s.size() == 1) {
                char c = s[0];
                if (c == '+' || c == '-' || c == '*' || c == '/') {
                    int b = st[top--];   // right operand
                    int a = st[top--];   // left operand
                    int res;
                    switch (c) {
                        case '+': res = a + b; break;
                        case '-': res = a - b; break;
                        case '*': res = a * b; break;
                        default:  res = a / b; break; // '/'
                    }
                    st[++top] = res;
                    continue;
                }
            }

            // Manual integer parsing (faster than stoi)
            int num = 0;
            int sign = 1;
            size_t i = 0;
            if (s[0] == '-') {
                sign = -1;
                i = 1;
            }
            for (; i < s.size(); ++i) {
                num = num * 10 + (s[i] - '0');
            }
            st[++top] = sign * num;
        }
        return st[top];
    }
};
