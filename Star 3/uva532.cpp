#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int L, R, C;
char maze[31][31][31];

struct point
{
    int x, y, z;
    int step = 0;   // record the step
};

int v[6][3] = {
    {1, 0, 0},
    {-1, 0, 0},
    {0, 1, 0},
    {0, -1, 0},
    {0, 0, 1},
    {0, 0, -1}
};

void BFS(struct point start, struct point end) {
    queue<point> q;
    q.push(start);

    while(!q.empty()){
        struct point curr = q.front();
        q.pop();

        if (curr.x == end.x && curr.y == end.y && curr.z == end.z) {
            cout << "Escaped in " << curr.step << " minute(s)." << endl;
            return;
        }

        // visit nearby points
        for(int i = 0; i < 6; i++){
            int x = curr.x + v[i][0];
            int y = curr.y + v[i][1];
            int z = curr.z + v[i][2];
            int step = curr.step + 1;

            if (0 <= x && x < L && 0 <= y && y < R && 0 <= z && z < C && (maze[x][y][z] == '.' || maze[x][y][z] == 'E')) {
                struct point next;
                next.x = x;
                next.y = y;
                next.z = z;
                next.step = step;
                q.push(next);
                /*
                    We can only mark the point as visited after we push it into the queue.
                    Otherwise, we may push the same point into the queue multiple times.
                    Therefore, it will cause the TLE error on the online judge.
                */
                maze[x][y][z] = 'V';  // mark as visited
            }

        }
    }
    // if no way to escape
    cout << "Trapped!" << endl;
}

int main() {
    // faster I/O
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (cin >> L >> R >> C && L && R && C)
    {
        memset(maze, 0, sizeof(maze));  // reset

        // input the maze
        string s;   // use string to speedup the I/O
        struct point start, end;  
        for(int i = 0; i < L; i++){
            for(int j = 0; j < R; j++){
                cin >> s;
                for(int k = 0; k < C; k++)
                {
                    maze[i][j][k] = s[k];

                    if (s[k] == 'S') {
                        start.x = i;
                        start.y = j;
                        start.z = k;
                        start.step = 0;
                    }
                    if (s[k] == 'E') {
                        end.x = i;
                        end.y = j;
                        end.z = k;
                    }

                }
            }
        }
        // find shortest path
        BFS(start, end);
    }
    
    return 0;
}