// PRIM'S ALGORITHM

class Solution
{
    int getMinValue(vector<int> &key, vector<bool> &mst)
    {
        int temp = INT_MAX;
        int index = -1;
        for (int i = 0; i < key.size(); i++)
        {
            if (key[i] < temp && mst[i] == false)
            {
                temp = key[i];
                index = i;
            }
        }
        return index;
    }

public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> key(V, INT_MAX);
        vector<bool> mst(V, false);
        vector<int> parent(V, -1);

        key[0] = 0;

        while (true)
        {
            int u = getMinValue(key, mst);
            if (u == -1)
                break;

            mst[u] = true;

            for (auto edge : adj[u])
            {
                int v = edge[0];
                int w = edge[1];

                if (mst[v] == false && w < key[v])
                {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < parent.size(); i++)
        {
            if (parent[i] == -1)
                continue;
            for (auto edge : adj[i])
            {
                int v = edge[0];
                int w = edge[1];
                if (v == parent[i])
                {
                    sum += w;
                }
            }
        }
        return sum;
    }
};

// KRUSKAL'S ALGORITHM

class Solution
{
    static bool mycomp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }

    int findParent(vector<int> &parent, int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        u = findParent(parent, u);
        v = findParent(parent, v);

        if (rank[u] > rank[v])
        {
            parent[v] = u;
            rank[u]++;
        }
        else
        {
            parent[u] = v;
            rank[v]++;
        }
    }

public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> parent(V);
        vector<int> rank(V, 0);

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }

        // Converting to a linear data structure
        vector<vector<int>> vec;
        for (int i = 0; i < V; i++)
        {
            for (auto edge : adj[i])
            {
                int u = edge[0];
                int w = edge[1];

                vec.push_back({i, u, w});
            }
        }

        // Sort v vector according to weights
        sort(vec.begin(), vec.end(), mycomp);

        int ans = 0;
        for (auto edge : vec)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            u = findParent(parent, u);
            v = findParent(parent, v);

            if (u != v)
            {
                unionSet(u, v, parent, rank);
                ans += w;
            }
        }
        return ans;
    }
};