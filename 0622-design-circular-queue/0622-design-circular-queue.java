class MyCircularQueue {
    Deque<Integer> dq;
    int k;
    public MyCircularQueue(int k) {
        this.k=k;
        dq = new ArrayDeque(k);
    }
    
    public boolean enQueue(int value) {
        if(dq.size()==k) return false;
        return dq.offer(value);
    }
    
    public boolean deQueue() {
        if(dq.poll()==null) return false;
        return true;
    }
    
    public int Front() {
        if(dq.peekFirst()==null) return -1;
        return dq.peekFirst();
    }
    
    public int Rear() {
        if(dq.peekLast()==null) return -1;
        return dq.peekLast();
    }
    
    public boolean isEmpty() {
        return dq.size()==0;
    }
    
    public boolean isFull() {
        return dq.size()==k;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */