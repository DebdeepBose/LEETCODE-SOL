class SmallestInfiniteSet {
public:
    int current;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> addedBack;

    SmallestInfiniteSet() {
        current = 1;
    }

    int popSmallest() {
        if (!pq.empty()) {
            int smallest = pq.top();
            pq.pop();
            addedBack.erase(smallest);
            return smallest;
        }
        return current++;
    }

    void addBack(int num) {
        if (num < current && addedBack.find(num) == addedBack.end()) {
            pq.push(num);
            addedBack.insert(num);
        }
    }
};
