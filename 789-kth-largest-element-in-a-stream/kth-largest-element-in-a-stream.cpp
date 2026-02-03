class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int>> minheap;
    KthLargest(int k,vector<int>& nums) {
        this->k=k;
        for (int x:nums) {
            minheap.push(x);
            if (minheap.size()>k) {
                minheap.pop();
            }
        }
    }
    int add(int val) {
        minheap.push(val);
        if (minheap.size()>k) {
            minheap.pop();
        }
        return minheap.top();
    }
};




/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */