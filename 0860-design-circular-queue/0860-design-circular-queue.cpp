class MyCircularQueue {
public:
    vector<int> cq;
    int front;
    int rear;
    int size;
    int capacity;

    MyCircularQueue(int k) {
        cq.resize(k);
        capacity = k;
        front = 0;
        rear = -1;
        size = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        cq[rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return cq[front];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return cq[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};
