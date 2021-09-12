#include "weightedgraph.h"
WeightedGraph::WeightedGraph(){
    //sets n to zero
    n = 0;
    //defines our bound for infinite
    maxDistance = 10000;
}
void WeightedGraph::createGraph(){
    //holds individual city names
    string city;
    //holds distance values to be stored in the adjacencyMatrix
    int distance;
    //reads in number of cities
    cin >> n;
    //line 16-18: assigns values of smallest weight to our predefined value of infinite
    for(size_t i = 0; i < n; i++){
        smallestWeight.push_back(maxDistance+1);
    }
    //line 20-22:assigns value to the predecessor to the above the number of cities
    for(size_t i = 0; i < n; i++){
        predecessor.push_back(n+1);
    }
    //line 23-27: loads in the city names 
    for(size_t i = 0; i < n; i++){
        cin >>city;
        citiesName.push_back(city);
    }
    //line 29-32: a temporary vector that will allow the creation of a 2D vector
    vector<int> tempload;
    for(size_t i = 0; i < n; ++i){
        tempload.push_back(0);
    }
    //line 34-36: creates the 2D adjacency matrix
    for(size_t i = 0; i < n; ++i){
        adjacencyMatrix.push_back(tempload);
    }
    //line 38-48: assigns appropriate weights to the indexes
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            cin >> distance;
            if(distance == 0 && i !=j ){
                adjacencyMatrix[i][j] = maxDistance + 1;
            }
            else{
                adjacencyMatrix[i][j] = distance;
            }
        }
    }
}
void WeightedGraph::shortestPath(int vertex){
    vector<bool> weightFound;
    //line: 52-54: loads values of smallestWeight and declares weightFound
    for(size_t i = 0; i < n; i++){
        smallestWeight[i] = adjacencyMatrix[vertex][i];
    }
    //line 56-58: loads the weightFound vector
    for(size_t j = 0; j < n; j++){
        weightFound.push_back(false);
    }
    //lines 60-63: assigns the values of the vertex as the starting point
    weightFound[vertex] = true;
    predecessor[vertex] = vertex;
    smallestWeight[vertex] = 0;
    for(size_t i = 0; i < n; i++){
        //assigns minWeight
        size_t minWeight = INT_MAX;
        int v = 0;
        //line 68-75: sequential search to find the minWeight of a vertex
        for(size_t j = 0; j < n; j++){
            if(!weightFound[j]){
                if(smallestWeight[j] < minWeight){
                    v = j;
                    minWeight = smallestWeight[v];
                }
            }
        }
        //signifies that we have found a smallest edge
        weightFound[v] = true;
        //line 79-81: visits the next vertex that the next smallest edge needs to be found
        if(predecessor[i] == (n+1)){
            predecessor[i] = vertex;
        }
        //line 83-90: assigns the minimum weights to the smallestWeight vector to solve for the smallest path
        for(size_t j = 0; j < n; j++){
            if(!weightFound[j]){
                if(minWeight + adjacencyMatrix[v][j] < smallestWeight[j]){
                    smallestWeight[j] = minWeight + adjacencyMatrix[v][j];
                    predecessor[j] = v;
                }
            }
        }
    }
}
void WeightedGraph::loadShortestDistance(int city){
    //path loaded from the predecessor
    vector<int> path;
    //holds individual indexes of vector<int> path
    int index;
    //will hold the final string solution
    string locations= "";
    //takes the current value of the predecessor
    int currentLocation = predecessor[city];
    //line 102-104: pushes back first value of shortest path
    path.push_back(city);
    path.push_back(currentLocation);
    //line 106-109: loads the rest of the shortest distance path
    while(currentLocation != 0){
        currentLocation = predecessor[currentLocation];
        path.push_back(currentLocation);
    }
    //line 111-114: loads the vector<int> path into the locations
    for(int i = path.size()-1; i >= 0; --i){
        index = path[i];
        locations += (citiesName[index] + " ");
    }
    //line 115-118: assigns the final path of the 
    locations += to_string(smallestWeight[n-1]);
    finalPath = locations;
    cout << finalPath << endl;
}
size_t WeightedGraph::getNumCites(){
    //returns value of n
    return n;
}