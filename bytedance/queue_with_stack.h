#pragma once
#include<stack>
#include<queue>
class queue_with_stack
{
public:
	void push(int);
	int pop();
	queue_with_stack();
	~queue_with_stack();
private:
	std::stack<int> s1;
	std::stack<int> s2;
};
class stack_with_queue
{
public:
	void push(int);
	int pop();
	stack_with_queue()=default;
	~stack_with_queue()=default;
private:
	std::queue<int> q1;
	std::queue<int> q2;
};
class MyClass {
public:
	MyClass();
	void* operator new(size_t s);
	void* operator new[](size_t s);
private:
	int a{10};
};


