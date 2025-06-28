// CODE360: Minimum Multiplications to reach End

// Pattern 4 - Dijkstra / Shortest Path

int MOD = 1000;
int minimumOperations(int n, int start, int end, vector<int> &a)
{
    if (start == end) return 0; // ? base case

    vector<int> distance(1000, 1e9);
    distance[start] = 0;

    queue<pair<int, int>> qu; // {steps, node}
    qu.push({0, start});

    while (!qu.empty())
    {
        int steps = qu.front().first;
        int node = qu.front().second;
        qu.pop();

        for (int arr : a)
        {
            int num = (arr * node) % MOD;

            if (num == end) return steps + 1;

            if (steps + 1 < distance[num])
            {
                distance[num] = steps + 1;
                qu.push({steps + 1, num});
            }
        }
    }

    return -1;
}

// Time Complexity = O(1000 * n)
// Space Complexity = O(1000)// distance[1000] array
