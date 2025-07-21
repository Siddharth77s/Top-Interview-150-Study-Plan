class Solution {
    typedef tuple<int, int, int> Item;
public:
    int kthSmallest(vector<vector<int>>& A, int k) {
        int N = A.size(), dirs[2][2] = { {0,1},{1,0} };
        vector<vector<bool>> seen(N, vector<bool>(N));
        priority_queue<Item, vector<Item>, greater<>> pq;
        pq.emplace(A[0][0], 0, 0);
        seen[0][0] = true;
        while (--k) {
            auto [n, x, y] = pq.top();
            pq.pop();
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= N || b < 0 || b >= N || seen[a][b]) continue;
                seen[a][b] = true;
                pq.emplace(A[a][b], a, b);
            }
        }
        return get<0>(pq.top());
    }
};