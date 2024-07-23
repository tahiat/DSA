// Date: 2024-07-16
// Description: 

#include <iostream>
#include<vector>
#include<queue>
using namespace std;


class MedianFinder {
private:
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;
public:

    MedianFinder() {
        maxQ = priority_queue<int>();
        minQ = priority_queue<int, vector<int>, greater<int>>();
    }
    
    void addNum(int num) {
        maxQ.push(num);
        if (!minQ.empty() && !maxQ.empty() && minQ.top() < maxQ.top()){
            int k = maxQ.top();
            maxQ.pop();
            minQ.push(k);
        }

        if (maxQ.size() > minQ.size() + 1){
            minQ.push(maxQ.top());
            maxQ.pop();
        }

        if (minQ.size() > maxQ.size() + 1){
            maxQ.push(minQ.top());
            minQ.pop();
        }

    }
    
    double findMedian() {
        
        if (maxQ.size() > minQ.size()){
            return maxQ.top();
        }
        if (maxQ.size() < minQ.size()){
            return minQ.top();
        }
        else {
            return (double) (maxQ.top()+minQ.top())/2;
        }
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.findMedian();
    mf.addNum(2);
    mf.findMedian();
    return 0;
} 