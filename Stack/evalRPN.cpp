class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> result;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int num1 = result.top();
                result.pop();
                int num2 = result.top();
                result.pop();
                if (tokens[i] == "+") result.push(num1 + num2);
                else if (tokens[i] == "-") result.push(num2 - num1);
                else if (tokens[i] == "*") result.push(num1 * num2);
                else if (tokens[i] == "/") result.push(num2 / num1);
            }
            else
            {
                result.push(stoi(tokens[i]));
            }
        }
        int res = result.top();
        return res;
    }
};