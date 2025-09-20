class Router {
private:
    int size;
    unordered_map<long long, vector<int>> pkts;
    unordered_map<int, vector<int>> mp;
    queue<long long> q;

    long long encode(int source, int destination, int timestamp) {
        return ((long long)source << 40) | ((long long)destination << 20) | timestamp;
    }

    int lowerBound(vector<int>& arr, int target) {
        return (int)(lower_bound(arr.begin(), arr.end(), target) - arr.begin());
    }

    int upperBound(vector<int>& arr, int target) {
        return (int)(upper_bound(arr.begin(), arr.end(), target) - arr.begin());
    }

public:
    Router(int memoryLimit) {
        size = memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        long long key = encode(source, destination, timestamp);

        if (pkts.find(key) != pkts.end()) {
            return false;
        }

        if ((int)pkts.size() >= size) {
            forwardPacket();
        }

        pkts[key] = {source, destination, timestamp};
        q.push(key);
        mp[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {
        if (pkts.empty()) {
            return {};
        }

        long long key = q.front();
        q.pop();

        vector<int> packet = pkts[key];
        pkts.erase(key);

        int dest = packet[1];
        mp[dest].erase(mp[dest].begin());

        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = mp.find(destination);
        if (it == mp.end() || it->second.empty()) {
            return 0;
        }

        vector<int>& arr = it->second;

        int left = lowerBound(arr, startTime);
        int right = upperBound(arr, endTime);

        return right - left;
    }
};
