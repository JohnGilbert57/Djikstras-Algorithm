#include<iostream>
#include<string>
#include<vector>
#include "weightedgraph.h"
using namespace std;
int main(int argc, char** argv){
    //will hold the number of test cases that need to be ran
    int testCases;
    //take in test case number from the file
    cin >> testCases;
    //execute these lines while there is still at test case
    while(testCases != 0){
        //declaration of WeightedGraph variable
        WeightedGraph graph;
        //create the graph values 
        graph.createGraph();
        //finds the shortest path and assigns values to coorespond
        graph.shortestPath(0);
        //loads stortest path into a variable and prints it to the user
        graph.loadShortestDistance(graph.getNumCites() - 1);
        //decrement test cases
        testCases--;
    }
    return 0;
}