#include<iostream>

using namespace std;

#define ll long long
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(0)
#define mod 1000000007




// find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool staVert[], int n)
{
    // Initialize min value
    int mindist = INT_MAX;
    int ind;

    for(int v = 0; v < n; v++)
        if((staVert[v] == false) && (dist[v] <= mindist))
        {
            mindist = dist[v];
            ind = v;
        }

    return ind;
}


void dijkstra(int **adjacency_mat, int src,int dist[], int n)
{

    bool staVert[n]; // staVert[i] will true if vertex i is included in shortest path tree

    // set staVert[] as false initially
    for (int i = 0; i < n; i++)
        staVert[i] = false;


    // Find shortest path for all vertices
    for (int cnt = 0; cnt < n-1; cnt++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet visited
        int u = minDistance(dist, staVert, n);
        staVert[u] = true; // Mark the picked vertex as visited

        for (int v = 0; v < n; v++) // Update dist value of the adjacent vertices of the picked vertex.
    //update if vertex is not staVert and there is path from choosen vertex to it
            if(!staVert[v] && adjacency_mat[u][v] && (dist[u]+adjacency_mat[u][v] < dist[v]))
                dist[v] = dist[u] + adjacency_mat[u][v];
    }

}

int find_best_city(int** adjacency_mat, int mycity, int friendcity, int n)
{
    int mdist[n]; // distance of cities from my city
    int fdist[n]; // distance of cities from my friend city

    // setting all distance to int_max initially
    for(int i=0; i<n; i++)
    {
    fdist[i] = INT_MAX;
    mdist[i] = INT_MAX;
    }

    mdist[mycity] = 0;
    fdist[friendcity] = 0;

    dijkstra(adjacency_mat, mycity,mdist, n); // finding distance from my city
    dijkstra(adjacency_mat, friendcity,fdist, n); //finding distance from friend city

    int answer = 0;

    int distt = INT_MAX;

    for(int i=0; i<n; i++) // finding city which has make me and my friend to wait minimum for other to meet
    {
        if(max(mdist[i],fdist[i]) < distt)
        {
        // cout<<i<<" "<<mdist[i]<<" "<<fdist[i]<<endl;
        distt = max(mdist[i],fdist[i]);
        answer = i;
        }
    }
    // cout<<distt<<endl;
    return answer;
}


int main()
{
    int m;
    cout << "Provide the size of you matrix n x n:";
    cin >> m;

    int** adjacency_mat = new int*[m];
	for (int i = 0; i < m; ++i)
	{
		adjacency_mat[i] = new int[m];
	}

    for(int i=0; i<m; i++)
        for(int j =0; j<m; j++)
            cin>>adjacency_mat[i][j];

    int mcity, fcity;
    cout << "Enter your city: ";
    cin >> mcity;
    cout << "Enter your destination city: ";
    cin >> fcity;

    cout << "Your Required city is: " << find_best_city(adjacency_mat, mcity, fcity, m);

    for (int i = 0; i < m; ++i)
		delete[] adjacency_mat[i];
	delete[] adjacency_mat;

    return 0;
}
