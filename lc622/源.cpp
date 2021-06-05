class MyCircularQueue {
private:
    int* data;
    int  front, rear;
    int  len;
public:
    MyCircularQueue(int k) {
        data = new int[k];
        len = k;
        front = rear = -1;
    }
    ~MyCircularQueue()
    {
        delete[] data;
    }

    bool enQueue(int value) {
        if (isFull())
        {
            return false;
        }
        if (isEmpty())
        {
            front++;
        }
        rear = (rear + 1) % len;
        data[rear] = value;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
        {
            return false;
        }
        if (front == rear && front != -1)
        {
            front = rear = -1;
        }

        else { front = (front + 1) % len; }
        return true;
    }

    int Front() {
        if (isEmpty())
        {
            return -1;
        }
        return data[front];
    }

    int Rear() {
        if (isEmpty())
        {
            return -1;
        }
        return data[rear];
    }

    bool isEmpty() {
        if (front == rear && front == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (front == (rear + 1) % len)
        {
            return true;
        }
        return false;
    }
};