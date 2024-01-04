#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    int minTime = INT_MAX;
    int commandCenter = -1;

    for (int i = 0; i < N; i++) {
        vector<bool> visited(N, false);
        queue<int> q;
        q.push(i);
        visited[i] = true;
        int time = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int j = 0; j < M; j++) {
                if (graph[curr][j] == 1) {
                    for (int k = 0; k < N; k++) {
                        if (graph[k][j] == -1 && !visited[k]) {
                            q.push(k);
                            visited[k] = true;
                        }
                    }
                }
            }
            time++;
        }

        if (time < minTime) {
            minTime = time;
            commandCenter = i;
        }
    }

    cout << "Командный центр: " << commandCenter << endl;

    return 0;
}
