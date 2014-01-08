//Mike McManaman Code::Blocks IDE Windows 7

#include <iostream>
#include <vector>

using namespace std;

const int inf = 9999;
const int NUMVEC = 6;

int graph[NUMVEC][NUMVEC];

void Dijkstra();

int shortNode(bool visit[], int dista[]);

int shortDistance(bool visit[], int dista[]);

int main()
{
    for (int i = 0; i < NUMVEC; i++)
    {
        cout << "Please enter the distance of node " << i+1 << " from the other nodes.";
        cout<< endl;
        cout << "Note: If nodes don't connect, set value to 9999: ";
        cout<< endl;
        for (int j = 0; j<NUMVEC; j++)
        {
            cin>>graph[i][j];
        }
    }

    Dijkstra();
}

void Dijkstra()
{
    int dist[NUMVEC];
    bool visited[NUMVEC];

    for (int i = 0; i < NUMVEC; i++)
    {
        dist[i] = inf;
        visited[i]= false;
    }

    dist[0]= 0;

    for (int j = 0; j < NUMVEC; j++)
    {
        int sn = shortNode(visited, dist);
        int sd = shortDistance(visited, dist);

        visited[sn] = true;

        for(int k = 0; k<NUMVEC; k++)
        {
        if ((dist[k] > (graph[sn][k]+dist[sn])) && !visited[k])
        {
            dist[k] = sd + graph[sn][k];
        }
        }
    }

    cout << "Node          Distance from source ";
    cout<< endl;

    for (int i = 0; i < NUMVEC; i++)
    {
        cout << i<< "                   " << dist[i];
        cout <<endl;
    }
}

int shortNode(bool visit[], int dista[])
{
    int shortdist = 9999;

    int shortestNode;

    for (int i = 0; i<NUMVEC; i++)
    {
        if ((dista[i]< shortdist) && !visit[i])
        {
            shortestNode = i;
            shortdist = dista[i];
        }
    }

    return shortestNode;
}


int shortDistance(bool visit[], int dista[])
{
    int shortdist = 9999;

    int shortestNode;

    for (int i = 0; i<NUMVEC; i++)
    {
        if ((dista[i]< shortdist) && !visit[i])
        {
            shortestNode = i;
            shortdist = dista[i];
        }
    }

    return shortdist;
}
