class MyCircularDeque {
    vector<int>buffer;
    int frontIdx = 0;
    int backIdx = 0;
    int bufferSize = 0;
public:
    MyCircularDeque(int k) {
        buffer.resize(k + 1);
        bufferSize = k + 1;
    }

    bool insertFront(int value) {
        if (isFull())
        {
            return false;
        }
        frontIdx = (frontIdx - 1 + bufferSize) % bufferSize;
        buffer[frontIdx] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
        {
            return false;
        }
        buffer[backIdx] = value;
        backIdx = (backIdx + 1) % bufferSize;

        return true;
    }

    bool deleteFront() {
        if (isEmpty())
        {
            return false;
        }
        frontIdx = (frontIdx + 1) % bufferSize;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
        {
            return false;
        }
        backIdx = (backIdx - 1 + bufferSize) % bufferSize;
        return true;
    }

    int getFront() {
        if (isEmpty())
        {
            return -1;
        }
        return buffer[frontIdx];
    }

    int getRear() {
        if (isEmpty())
        {
            return -1;
        }
        int rear = (backIdx - 1 + bufferSize) % bufferSize;
        return buffer[rear];
    }

    bool isEmpty() {
        return frontIdx == backIdx;
    }

    bool isFull() {
        return (backIdx + 1) % bufferSize == frontIdx;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */