class MyCircularQueue {
    int k;
    int[] arr;
    int start,end;
    public MyCircularQueue(int k) {
        start = -1;
        end = -1;
        arr = new int[k];
        this.k = k;
    }
    
    public boolean enQueue(int value) {
        if(isFull()) return false;
        if(start==-1) {
            start = 0;
            end = 0;
        }
        arr[end]=value;
        end=(end+1)%k;
        return true;
    }
    
    public boolean deQueue() {
        if(start==-1) return false;
        start=(start+1)%k;
        if(start==end) {
            start=-1;
            end=-1;
        }
        return true;
    }
    
    public int Front() {
        if(start==-1) return -1;
        return arr[start];
    }
    
    public int Rear() {
        if(start==-1) return -1;
        return arr[(end-1+k)%k];
    }
    
    public boolean isEmpty() {
        return start==-1;
    }
    
    public boolean isFull() {
        return start!=-1 && start==end;
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