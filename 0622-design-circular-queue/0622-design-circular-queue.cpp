class MyCircularQueue {

    vector<int> vec;
    int frontIdx = 0;
    int backIdx = 0;
    int queueSize = 0;
    int currentSize = 0;
public:
    MyCircularQueue(int k) {
        vec.resize(k+1,-1);
        queueSize = k;
        
    }

    bool enQueue(int value) {
        if (isFull())
        {
            return false;
        }
        vec[backIdx] = value;
        backIdx = (backIdx + 1) % queueSize;
        currentSize++;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
        {
            return false;
        }
        vec[frontIdx] = -1;
        frontIdx = (frontIdx + 1) % queueSize;
        currentSize--;
        return true;
    }

    int Front() {
        if (isEmpty())
        {
            return -1;
        }
        return vec[frontIdx];
    }

    int Rear() {
        if (isEmpty())
        {
            return -1;
        }
        int rear = (backIdx - 1 + queueSize) % queueSize;
        return vec[rear];
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == queueSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */