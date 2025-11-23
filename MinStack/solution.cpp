class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        s_.push(val);
        mp_[val]++;
    }
    
    void pop() {
        mp_[s_.top()]--;
        if (mp_[s_.top()] == 0) mp_.erase(s_.top());
        s_.pop();
    }
    
    int top() {
        return s_.top();
    }
    
    int getMin() {
        auto it = mp_.begin();
        return it->first;
    }
private:
    stack<int> s_;
    map<int, int> mp_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// We use an actual stack to keep track of push, pop, and top operations
// To keep track of min, we use a sorted hashmap that maps each element to the number of elements in the stack, since multiple elements with the same key can be pushed
// To return min, we always return the minimum element in the ordered map, or map.begin()
// We make sure to erase elements from the map if pop() makes the element's frequency = 0
