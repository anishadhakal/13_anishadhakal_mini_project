#include "graph.h"

void Graph::addVertex(int node)
{
    int vertex;
    vertex = nodeExists(node);
    if (vertex != 1)
    {
        nodelist.push_back(node);
    }
    else
    {
        std::cout << "Vertex already exists." << std::endl;
    }
}

bool Graph::nodeExists(int node)
{
    for (int i = 0; i < nodelist.size(); i++)
    {
        if (nodelist[i] == node)
        {
            return true;
        }
    }
    return false;
}

bool Graph::edgeExists(int node1, int node2)
{
    for (int i = 0; i < edgelist1.size(); i++)
    {
        if (edgelist1[i] == node1 && edgelist2[i] == node2)
        {
            return true;
        }
    }
    return false;
}

void Graph::addEdge(int node1, int node2)
{
    int compare1, compare2, compare3;
    compare1 = edgeExists(node1, node2);
    compare2 = nodeExists(node1);
    compare3 = nodeExists(node2);
    if (compare1 != 1 && compare2 == 1 && compare3 == 1)
    {
        edgelist1.push_back(node1);
        edgelist2.push_back(node2);
        std::cout << "Added edge: (" << node1 << "," << node2 << ")" << std::endl;
    }
    else if (compare1 == 1)
    {
        std::cout << "Edge already exists." << std::endl;
    }
    else
    {
        std::cout << "One of the node does not exist.So, the edge cannot be added." << std::endl;
    }
}

void Graph::addUndirectedEdge(int node1, int node2)
{
    addEdge(node1, node2);
    addEdge(node2, node1);
}

void Graph::displayNodes()
{
    for (std::vector<int>::const_iterator i = nodelist.begin(); i < (nodelist.end()); i++)
    {
        std::cout << "Vertex: " << (*i) << std::endl;
    }
}

void Graph::displayEdges()
{

    for (int i = 0; i < edgelist1.size(); i++)
    {
        std::cout << "Edges: (" << edgelist1[i] << "," << edgelist2[i] << ")" << std::endl;
    }
}

int Graph::numNodes()
{
    std::cout << "Num of vertices: " << nodelist.size() << std::endl;
}

int Graph::numEdges()
{
    std::cout << "Num of edges: " << edgelist1.size() << std::endl;
}
int Graph::inDegree(int node)
{
    int count = 0;
    for (int i = 0; i < nodelist.size(); i++)
    {
        if (nodeExists(node))
        {
            if (edgeExists(node, edgelist1[i]) || edgeExists(edgelist1[i], node))
            {
                count++;
            }
        }
    }
    return count;
}
int Graph::outDegree(int node)
{

    return inDegree(node);
}

int Graph::Degree(int node)
{
    return inDegree(node) + outDegree(node);
}


void Graph::BreadthFirstTraversal(int node)
{

    int p;
    p = nodeExists(node);
    std::vector<int> friendlist;
    if (p == 1)
    {
        int count = 0;
        std::cout << "Friends of " << node << ":" << std::endl;
        for (std::vector<int>::const_iterator i = edgelist1.begin(); i < (edgelist1.end()); i++)
        {
            if (*(edgelist1.begin() + count) == node)
            {
                friendlist.push_back(*(edgelist2.begin() + count));
                std::cout << *(edgelist2.begin() + count) << std::endl;
            }
            if (*(edgelist2.begin() + count) == node && *(edgelist1.begin() + count) != node)
            {
                friendlist.push_back(*(edgelist1.begin() + count));
                std::cout << *(edgelist1.begin() + count) << std::endl;
            }

            count++;
        }



        int count1 = 0;
        std::cout << "Friends of friends of " << node << " are as follows:" << std::endl;
        for (std::vector<int>::const_iterator i = friendlist.begin(); i < (friendlist.end()); i++)
        {
            int count2 = 0;
            std::cout << "Friends of " << *(friendlist.begin() + count1) << ":" << std::endl;
            for (std::vector<int>::const_iterator i2 = edgelist1.begin(); i2 < (edgelist1.end()); i2++)
            {
                if (*(edgelist1.begin() + count2) == *(friendlist.begin() + count1) && *(edgelist2.begin() + count2) != node)
                {
                    std::cout << *(edgelist2.begin() + count2) << std::endl;
                }
                if (*(edgelist2.begin() + count2) == *(friendlist.begin() + count1) && *(edgelist1.begin() + count2) != node)
                {
                    std::cout << *(edgelist1.begin() + count2) << std::endl;
                }
                count2++;
            }
            count1++;
        }
    }
}
