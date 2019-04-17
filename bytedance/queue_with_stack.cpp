#include<iostream>
#include<cassert>
#include "queue_with_stack.h"
using namespace std;
void queue_with_stack::push(int node) {
	s1.push(node);
}
int queue_with_stack::pop() {
	int x;
	if (s2.empty()) {
		if (s1.empty())
			assert(!s1.empty());
			while (!s1.empty()) {
				auto x = s1.top();
				s2.push(x);
				s1.pop();
			}
			x = s2.top();
			s2.pop();
	}
	else {
		x = s2.top();
		s2.pop();
	}
	return x;
}
queue_with_stack::queue_with_stack() = default;
queue_with_stack::~queue_with_stack() = default;

void stack_with_queue::push(int node) {
	if (q2.empty())
		q1.push(node);
	else {
		q2.push(node);
	}
}
int stack_with_queue::pop() {
	if (q1.empty() && q2.empty())
		return -1;
	if (q1.empty()) {
		while (q2.size() != 1) {
			auto x = q2.front();
			q1.push(x);
			q2.pop();
		}
		auto x = q2.front(); q2.pop();
		return x;
	}
	else {
		while (q1.size() != 1) {
			auto x = q1.front();
			q2.push(x);
			q1.pop();
		}
		auto x = q1.front(); q1.pop();
		return x;
	}
}
MyClass::MyClass() {
	std::cout << "construcor" << std::endl;
}
void* MyClass::operator new(size_t s) {
	std::cout << "yes" << std::endl;
	return malloc(sizeof(MyClass));
}
void* MyClass::operator new[](size_t s) {
	std::cout << "wow" << std::endl;
	return malloc(s);
}

