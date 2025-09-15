class Solution {
public:


int floorDiv(int a, int b) {
    int result = a / b;
    if ((a ^ b) < 0 && a % b != 0) {
        result--;
    }
    return result;
}

    bool isOperator(char x) {
        return x == '+' || x == '-' || x == '*' || x == '/' || x == '^';
    }


int res(int x, int y, string &s) {
    switch (s[0]) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return floorDiv(x, y);
        case '^': return pow(x, y);
        default: return 0;
    }
}


    int evaluatePostfix(vector<string> &arr) {
        stack<int> s;

        for (const string &token : arr) {
            if (token.length() == 1 && isOperator(token[0])) {
                if (s.size() < 2) return 0; 
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(res(a, b, const_cast<string&>(token)));
            } else {
                s.push(stoi(token));
            }
        }

        return s.top();
    }
};