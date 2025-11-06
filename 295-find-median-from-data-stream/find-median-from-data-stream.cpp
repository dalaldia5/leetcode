class MedianFinder {
private:
    // Max-heap to store the smaller half of the data
    priority_queue<int> maxHeap;
    // Min-heap to store the larger half of the data
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {}

    void addNum(int num) {
        // add to maxheap
        maxHeap.push(num);
        // balance by pushing the largest from maxHeap to minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        // if minHeap has more elements, move top back to maxHeap
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */