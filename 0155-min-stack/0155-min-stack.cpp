class MinStack {
	stack<int> s;
	stack<int> min_stack;
public:
	MinStack() {

	}

	void push(int value) {
		s.push(value);
		if (min_stack.empty() || value <= min_stack.top())
		{
			min_stack.push(value);
		}
	}
	void pop() {
		if (s.top() == min_stack.top())
		{
			min_stack.pop();
		}
		s.pop();
	}

	int top() {
		return s.top();
	}

	int getMin() {
		return min_stack.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */