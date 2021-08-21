#include <iostream>
#include <vector>
#pragma once

class Graph
{
private:
    std::vector<int> nodelist;
    std::vector<int> edgelist1;
    std::vector<int> edgelist2;

public:
   
    void addVertex(int node);
    bool nodeExists(int node);
    void displayNodes();
    void addEdge(int node1, int node2);
    void addUndirectedEdge(int node1, int node2);
    bool edgeExists(int node1 , int node2);
    void displayEdges();
    int numNodes();
    int numEdges();
    int inDegree(int node);
    int outDegree(int node);
    int Degree(int node);
    void BreadthFirstTraversal(int node);
    
    void display();
};