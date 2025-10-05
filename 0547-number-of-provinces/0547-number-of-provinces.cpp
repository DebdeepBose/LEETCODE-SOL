class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        // Well we check this cuz we gotta know how many nodes are there
        int vertices = isConnected.size();

        vector<vector<int>> adjacencyList(vertices);
        /* This basically creates a list of V number of lists
        like this adj = [

                    0 -> [   ]
                    1 -> [   ]
                    2 -> [   ]

                ]
        */

        // Next we basically build our adjacencyList
        // Also its n*n matrix, aka number of vertices remain same
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                /*i mean we are avoiding i==j cuz like it will double
                push an element suppose i == j == 0 then 0 -> [0,0],
                this will happen cuz
                0.push_back(0)
                0.push_back(0)
                will end up pushing 0 twice*/
                if (isConnected[i][j] == 1 && i != j) {
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }
        // oh we also keep a visited array
        vector<bool> visited(adjacencyList.size(), false);

        int provinces = 0;

        // Now since nodes start from 0 and go < vertices we run a loop
        for (int node = 0; node < vertices; node++) {
            if (!visited[node]) {

                /*get this, the number of provinces logically equalas to the
                  number of times we have to start a fresh dfs cuz its not
                  visited*/
                provinces++;
                dfs(node, adjacencyList, visited);
            }
        }

        return provinces;
    }

    // Now we d the f and s
    void dfs(int node, vector<vector<int>>& adjacencyList,
             vector<bool>& visited) {
        // As soon as any node enter we gotta mark is
        visited[node] = true;

        // next for that node number in the adjacency list we gotta go
        // deep...pause
        for (auto subarrayNode : adjacencyList[node]) {
            // Only of its unvisited, we go deeper..pause again
            if (!visited[subarrayNode]) {
                dfs(subarrayNode, adjacencyList, visited);
            }
        }
    }
};