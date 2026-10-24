#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
	class stack {
	private:
		int size{};
		int top{};
		int* arr{};
	public:
		stack(int size) :size(size), top(-1) {
			arr = new int[size];
		}
			bool is_full() {
				return top == size - 1;
			}
			bool is_empty() {
				return top == -1;
			}
			void push(int value) {
				if (!is_full()) {
					arr[++top] = value;
				}
			}
			int pop() {
				if (!is_empty()) {
					return arr[top--];
				}
			}
			void reverse(int num) {
				string s = to_string(num);
				for (int i = 0; i <s.size(); i++) {
					push(s[i]-'0');
				}
				int* newarr=new int [s.size()];
				for (int i = 0; i < s.size(); i++) {
					newarr[i] = pop();
				}
				for (int i = 0; i <s.size(); i++) {
					cout << newarr[i];
				}
			}
		};
	int main() {
		stack g(6);
		g.reverse(598375);

		return 0;
	}
