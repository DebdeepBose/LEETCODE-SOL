class TaskManager {

    unordered_map<int, int> taskToUser;
    unordered_map<int, int> taskToPriority;
    set<pair<int,int>, greater<pair<int,int>>> execTask;

public:
    TaskManager(vector<vector<int>>& tasks) {
        

        for(auto task: tasks) {

            taskToUser[task[1]] = task[0];
            taskToPriority[task[1]] = task[2];
            execTask.insert({task[2], task[1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        
        taskToUser[taskId] = userId;
        taskToPriority[taskId] = priority;
        execTask.insert({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        
        int prevPriority = taskToPriority[taskId];

        auto it = execTask.lower_bound({prevPriority, taskId});
        execTask.erase(*it);

        execTask.insert({newPriority, taskId});
        taskToPriority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        
        int prevPriority = taskToPriority[taskId];

        auto it = execTask.lower_bound({prevPriority, taskId});
        execTask.erase(*it);

        taskToUser.erase(taskId);
        taskToPriority.erase(taskId);
    }
    
    int execTop() {
        
        if(execTask.size() == 0) {
            return -1;
        }

        auto it = execTask.begin();
        int taskId = (*it).second;

        execTask.erase(*it);
        return taskToUser[taskId];
    }
};

