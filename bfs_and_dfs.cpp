#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Graph
{
private:
    int** adjacencyMatrix;
    int numCities;
public:
    Graph(int n){
        numCities = n;
        adjacencyMatrix = new int*[numCities];
        for(int i=0;i<numCities;++i){
            adjacencyMatrix[i] = new int[numCities];
            for(int j=0; j<numCities; ++j)
                adjacencyMatrix[i][j] = 0;
        }
    }
    
    ~Graph(){
        for(int i=0; i<numCities; ++i)
            delete[] adjacencyMatrix[i];
        delete[] adjacencyMatrix;
    }

    void addEdge(int city1, int city2){
        adjacencyMatrix[city1][city2] = 1;
    }

    void BFS(int startNode){
        bool* visited = new bool[numCities]{false};
        queue<int> q;
        visited[startNode]=true;
        q.push(startNode);

        cout << "Nodes reachable from node "<<startNode<<" are:\n";
        while(!q.empty()){
            int current = q.front();
            q.pop();
            cout << current << " ";

            for(int i=0; i<numCities; ++i){
                if(adjacencyMatrix[current][i] == 1 && !visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
        delete[] visited;
    }

    void DFSUtil (int startNode, bool* visited){
        visited[startNode] = true;

        for(int i=0; i<numCities ; ++i){
            if(adjacencyMatrix[startNode][i] == 1 && !visited[i]){
                DFSUtil(i, visited);
            }
        }
    }

    bool isConnected(){
        bool* visited = new bool[numCities]{false};
        DFSUtil(0, visited);

        for(int i=1; i<numCities; ++i){
            if(!visited[i]){
                delete[] visited;
                return false;
            }
        }

        delete[] visited;
        return true;
    }
};



int main(){
    int numCities;
    cout << "Enter the number of cities:\t";
    cin >> numCities;

    Graph graph(numCities);

    cout << "\nEnter the connections (0-based indexing, -1 to end):\n";
    int city1, city2;
    while(true){
        cout << "Enter connection (city1, city2):\n";
        cin >> city1 >> city2;
        if(city1 == -1 || city2 == -1)
            break;
        if(city1 >= numCities || city2 >= numCities){
            cout << "Invalid city index. Try agin.\n";
            continue;
        }
        graph.addEdge(city1, city2);
    }

    int startNode;
    cout << "Enter the starting node for BFS: \t";
    cin >> startNode;
    
    graph.BFS(startNode);

    cout << "Checking graph is connected or not using DFS..........\n\n";
    
    if(graph.isConnected())
        cout << "The cities(graph) is connected.\n";
    else    
        cout << "The graph is not connected.\n";

    return 0;
}