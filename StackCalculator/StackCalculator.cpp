#include <iostream>
#include <stack> 
#include <cctype>
#include <cstring>
#include <cmath>

using namespace std;

void calculate(stack<int>& numbers, stack<char>& operations) {
	//precondition :stack is not empty, and numbers is not negative integer
	//postcondition : result is an integer
	int number1, number2;
	char symbol;

	if (numbers.empty() != 1) {
		// number1 (symbol) number2 = result
		number2 = numbers.top();
		numbers.pop();
		number1 = numbers.top();
		numbers.pop();
		symbol = operations.top();
		operations.pop();

		switch (symbol) {
			//������ Ȯ��
		case '+':numbers.push(number1 + number2); break;
		case '-':numbers.push(number1 - number2); break;
		case '*':numbers.push(number1 * number2); break;
		case '/':
			if (number1 == 0 || number2 == 0) {
				printf("Error!\n");
				operations.push('E');
				break;
			}
			else
				numbers.push(number1 / number2); break;
		case '^':numbers.push(pow(number1, number2)); break;
		case '%':
			if (number1 == 0 || number2 == 0) {
				printf("Error!\n");
				operations.push('E');
				break;
			}
			else
				numbers.push(number1 % number2); break;
		}
	}
}

void read_stack(istream& ins) {
	stack<int> numbers;
	stack<char> operations;
	int number;
	char symbol;

	while (1) {
		if (ins.peek() == '0') {
			// 0 �Է½� ���α׷� ����
			ins.ignore();
			if (ins.peek() == '\n') {
				return;
			}
			else {
				numbers.push(0);
			}
		}

		while (ins && ins.peek() != '\n') {
			//���� ���ڰ� ���ö� ���� ����
			if (operations.empty() != 1 && operations.top() == 'E')
				break;
			if (isdigit(ins.peek())) {
				//���ڸ� numbers stack�� ����
				ins >> number;
				numbers.push(number);
			}
			else if (strchr("+-*/%^(", ins.peek()) != NULL) {
				// �����ڸ� operations stack�� ����.
				ins >> symbol;

				if (symbol == '(')
					operations.push(symbol);
				else if (operations.empty() == 1 || operations.top() == '(') {
					operations.push(symbol);
				}
				else {
					if (symbol == '^') {
						if (operations.top() == '^') {
							calculate(numbers, operations);
						}
						if (operations.empty() != 1 && operations.top() == 'E')
							break;
						else
							operations.push(symbol);
					}
					else if (symbol == '*' || symbol == '/' || symbol == '%') {
						if (operations.top() == '^') {
							calculate(numbers, operations);
						}
						if (operations.empty() != 1 && operations.top() == 'E')
							break;
						else
							operations.push(symbol);
					}
					else {
						calculate(numbers, operations);
						if (operations.empty() != 1 && operations.top() == 'E')
							break;
						else
							operations.push(symbol);
					}
				}
			}
			else if (ins.peek() == ')') {
				ins.ignore();
				while (operations.top() != '(') {
					calculate(numbers, operations);
					if (operations.empty() != 1 && operations.top() == 'E')
						break;
				}
				if (operations.top() == '(')
					operations.pop();

			}
			else
				ins.ignore();
		}
		while (ins.peek() != '\n') {
			ins.ignore();

		}
		if (ins.peek() == '\n') {
			ins.ignore();
		}
		//�Էµ� ���� ��� stack ���� �Ϸ�

		while (operations.empty() != 1) {
			// ���� ���� ���
			if (operations.top() == 'E')
				break;
			calculate(numbers, operations);
		}

		if (operations.empty() != 1 && operations.top() == 'E') {
			// ���. stack���
			while (numbers.empty() != 1) {
				numbers.pop();
			}
			while (operations.empty() != 1) {
				operations.pop();
			}
		}
		else {
			// output
			cout << numbers.top() << endl;
		}
	}
}

int main() {
	read_stack(cin);
}
