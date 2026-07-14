class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> operations = {"+", "-", "*", "/"};
        stack<int> numbers;

        for (auto& token : tokens) {
            if (operations.find(token) == operations.end()) {
                numbers.push(stoi(token));
            } else {
                int b = numbers.top(); numbers.pop();
                int a = numbers.top(); numbers.pop();

                if      (token == "+") numbers.push(a + b);
                else if (token == "-") numbers.push(a - b);
                else if (token == "*") numbers.push(a * b);
                else if (token == "/") numbers.push(a / b);
            }
        }

        return numbers.top();
    }
};