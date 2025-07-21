class Solution {
    typedef array<int, 3> Point;
public:
    int trapRainWater(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), dirs[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }, ans = 0, maxH = INT_MIN;
        priority_queue<Point, vector<Point>, greater<>> pq;
        vector<vector<bool>> seen(M, vector<bool>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == 0 || i == M - 1 || j == 0 || j == N - 1) {
                    pq.push({ A[i][j], i, j });
                    seen[i][j] = true;
                }
            }
        }
        while (pq.size()) {
            auto [h, x, y] = pq.top();
            pq.pop();
            maxH = max(maxH, h);
            for (auto &[dx, dy] : dirs) {
                int a = x + dx, b = y + dy;
                if (a < 0 || a >= M || b < 0 || b >= N || seen[a][b]) continue;
                seen[a][b] = true;
                if (A[a][b] < maxH) ans += maxH - A[a][b];
                pq.push({ A[a][b], a, b });
            }
        }
        return ans;
    }
};
