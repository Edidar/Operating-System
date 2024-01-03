#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string input;
    cout << "Enter input string: ";
    getline(cin, input);

    stack<char> stack;
    stack.push('$'); // Push end-of-stack marker
    stack.push('E'); // Push starting symbol

    int pos = 0;
    char lookahead = input[pos];

    cout << "STACK\t\t\tINPUT\t\t\tACTION\n";
    cout << "----\t\t\t-----\t\t\t------\n";

    while (!stack.empty()) {
        char top = stack.top();
        if (top == '$' && lookahead == '$') {
            cout << stack.top() << "\t\t\t" << lookahead << "\t\t\tAccept\n";
            break;
        } else if (top == lookahead) {
            stack.pop();
            pos++;
            lookahead = input[pos];
            cout << stack.top() << "\t\t\t" << input.substr(pos) << "\t\t\tMatch " << top << endl;
        } else if (top == 'E' && (lookahead == '(' || isalpha(lookahead))) {
            stack.pop();
            stack.push(')');
            stack.push('T');
            stack.push('+');
            stack.push('E');
            cout << stack.top() << "\t" << input.substr(pos) << "\t\t\tReduce E -> E + T\n";
        } else if (top == 'T' && (lookahead == '(' || isalpha(lookahead))) {
            stack.pop();
            stack.push(')');
            stack.push('F');
            stack.push('*');
            stack.push('T');
            cout << stack.top() << "\t" << input.substr(pos) << "\t\t\tReduce T -> T * F\n";
        } else if (top == 'F' && lookahead == '(') {
            stack.pop();
            stack.push(')');
            stack.push('E');
            stack.push('(');
            cout << stack.top() << "\t" << input.substr(pos) << "\t\t\tReduce F -> ( E )\n";
        } else if (top == 'F' && isalpha(lookahead)) {
            stack.pop();
            stack.push('id');
            cout << stack.top() << "\t" << input.substr(pos) << "\t\t\tReduce F -> id\n";
        } else {
            cout << "Error: Invalid input\n";
            break;
        }
    }

    return 0;
}
