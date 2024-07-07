// MY APPROACH --> GIVING WRONG ANS --> WHY ? I DONT KNOW
class Solution
{
public:
    void dfs2(int src, unordered_map<int, bool> &visited2, unordered_map<int, list<int>> &newAdjList)
    {
        visited2[src] = 1;

        for (auto nbr : newAdjList[src])
        {
            if (!visited2[nbr])
            {
                dfs2(nbr, visited2, newAdjList);
            }
        }
    }

    void dfs1(int src, stack<int> &st, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
    {
        visited[src] = 1;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                dfs1(nbr, st, visited, adjList);
            }
        }
        st.push(src);
    }

    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // code here
        unordered_map<int, list<int>> adjList;
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                if (adj[i][j] == 1)
                {
                    adjList[i].push_back(j);
                }
            }
        }

        // soring dfs traversal in stack1
        stack<int> st;
        unordered_map<int, bool> visited;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs1(i, st, visited, adjList);
        }

        // Resversing the edges
        unordered_map<int, list<int>> newAdjList;
        for (auto i : adjList)
        {
            for (auto j : i.second)
            {
                int u = i.first;
                int v = j;
                newAdjList[v].push_back(u);
            }
        }

        int count = 0;
        unordered_map<int, bool> visited2;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (!visited2[node])
            {
                dfs2(node, visited2, newAdjList);
                count++;
            }
        }
        return count;
    }
};

// CORRECT APPROACH
class Solution
{
public:
    void dfs2(int src, unordered_map<int, bool> &visited2, vector<int> newAdj[])
    {
        visited2[src] = 1;

        for (auto nbr : newAdj[src])
        {
            if (!visited2[nbr])
            {
                dfs2(nbr, visited2, newAdj);
            }
        }
    }

    void dfs1(int src, stack<int> &st, unordered_map<int, bool> &visited, vector<vector<int>> &adj)
    {
        visited[src] = 1;

        for (auto nbr : adj[src])
        {
            if (!visited[nbr])
            {
                dfs1(nbr, st, visited, adj);
            }
        }
        st.push(src);
    }

    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        // code here
        //     unordered_map<int, list<int>> adjList;
        //     for(int i=0; i<adj.size(); i++){
        //     for(int j=0; j<adj[i].size(); j++){
        //         if(adj[i][j] == 1){
        //             adjList[i].push_back(j);
        //         }
        //     }
        // }

        // Step 1 -> soring dfs traversal in stack1
        stack<int> st;
        unordered_map<int, bool> visited;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs1(i, st, visited, adj);
        }

        // Step 2 ->Resversing the edges
        vector<int> newAdj[V];
        for (int i = 0; i < V; i++)
        {
            // visited[i] = 0;
            for (auto j : adj[i])
            {
                newAdj[j].push_back(i);
            }
        }

        int count = 0;
        unordered_map<int, bool> visited2;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (!visited2[node])
            {
                dfs2(node, visited2, newAdj);
                count++;
            }
        }
        return count;
    }
};