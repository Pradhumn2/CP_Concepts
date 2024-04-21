class Solution
{
public:
  void dkst(int src, vector<int> &dist, vector<vector<pair<int, int>>> &adj)
  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
      int node = pq.top().second;
      int wt = pq.top().first;
      pq.pop();
      for (auto i : adj[node])
      {
        int curr_node = i.first;
        int curr_dist = i.second;
        if (dist[curr_node] > curr_dist + wt)
        {
          dist[curr_node] = curr_dist + wt;
          pq.push({dist[curr_node], curr_node});
        }
      }
    }
  }
  vector<bool> findAnswer(int n, vector<vector<int>> &edges)
  {
    vector<vector<pair<int, int>>> adj(n);
    for (auto i : edges)
    {
      int n1 = i[0], n2 = i[1], wt = i[2];
      adj[n1].push_back({n2, wt});
      adj[n2].push_back({n1, wt});
    }

    vector<int> src_dist(n, INT_MAX), dst_dist(n, INT_MAX);
    src_dist[0] = 0;
    dst_dist[n - 1] = 0;

    dkst(0, src_dist, adj);
    dkst(n - 1, dst_dist, adj);

    vector<bool> res;

    for (auto i : edges)
    {
      int n1 = i[0], n2 = i[1], wt = i[2];
      // cout<<n1<<" "<<src_dist[n1]<<" "<<n2<<" "<<dst_dist[n2]<<endl;
      if (src_dist[n1] != INT_MAX && dst_dist[n2] != INT_MAX)
      {
        if (src_dist[n1] + dst_dist[n2] + wt == src_dist[n - 1])
          res.push_back(true);
        else if (src_dist[n2] + dst_dist[n1] + wt == src_dist[n - 1])
          res.push_back(true);
        else
          res.push_back(false);
      }
      else
        res.push_back(false);
    }

    return res;
  }
};