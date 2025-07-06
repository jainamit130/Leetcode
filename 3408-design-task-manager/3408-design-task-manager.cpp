class TaskManager {
public:
    priority_queue<vector<int>> taskMaxHeap;
    unordered_map<int,vector<int>> taskUser;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto task:tasks) {
            taskUser[task[1]]= {task[0],task[2]};
            taskMaxHeap.push({task[2],task[1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskUser[taskId]= {userId,priority};
        taskMaxHeap.push({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        taskUser[taskId][1] = newPriority;
        taskMaxHeap.push({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        taskUser.erase(taskId);
    }
    
    int execTop() {
        while(!taskMaxHeap.empty() 
              && (taskUser.find(taskMaxHeap.top()[1])==taskUser.end() || 
              taskUser[taskMaxHeap.top()[1]][1]!=taskMaxHeap.top()[0])) {
                taskMaxHeap.pop();
            }

            if(taskMaxHeap.empty()) return -1;
            int taskId = taskMaxHeap.top()[1];
            int userId = taskUser[taskId][0];
            rmv(taskId);
            taskMaxHeap.pop();
            return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();


taskId => userId,newPriority

maxHeap =>  {newPriority, taskId}
            {priority, taskId}


 */