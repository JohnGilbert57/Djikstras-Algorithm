#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
using namespace std;
#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
class WeightedGraph{
    public:
        //constructor
        WeightedGraph();
        //creates the graph for a test case
        void createGraph();
        //takes values assigned in the shortest path and puts it into a single string to be outputted to the user
        void loadShortestDistance(int city);
        //assigns appropriate values for finding the shortest path
        void shortestPath(int vertex);
        //returns the value of n for a certain test case
        size_t getNumCites();
        //returns finalPath variable that will be outputted to the user
        string getSolution();
    private:
        //size_t n: stores the number of cities
        size_t n;
        //vector<string> citiesName: stores the names of the cities inputted
        vector<string> citiesName;
        //vector<vector<int>> adjacencyMatrix: Will create an adjacenct matrix to determine the shortest distance
        vector<vector<int>> adjacencyMatrix;
        //int maxDistance: will hold the number we assume to mean infinite
        size_t maxDistance;
        //vector<size_t> predecessor: holds the predecessor vertexes visited
        vector<size_t> predecessor;
        //string finalPath: holds the values of the smallest path including the vertexes and the final distance
        string finalPath;
        //vector<size_t> smallestWeight: will be used to hold values of smallest weights and will coorespond with vertexes
        vector<size_t> smallestWeight;
};
#endif