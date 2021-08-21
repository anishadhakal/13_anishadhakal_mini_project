#include "graph.cpp"

int main()
{
    std::cout << "                --------Program to find friends of friends--------" << std::endl;
    Graph g;
    int a, b, size;
    std::cout << "Enter the size of nodes you want:" << std::endl;
    std::cin >> size;
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the vertex:" << std::endl;
        std::cin >> a;
        g.addVertex(a);
    }
    std::cout << "Enter the size of edges you want:" << std::endl;
    std::cin >> size;
    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter the vertex:" << std::endl;
        std::cout << "Vertex 1:" << std::endl;
        std::cin >> a;
        std::cout << "Vertex 2:" << std::endl;
        std::cin >> b;
        g.addEdge(a, b);
    }

    std::cout << "Displaying all vertices:" << std::endl;
    g.displayNodes();
    std::cout << "Displaying all edges:" << std::endl;
    g.displayEdges();
    g.numNodes();
    g.numEdges();

start:
    int number;
    std::cout << "Do you want to find Indegree, Outdegree and Degree of a vertex ?" << std::endl;
    std::cout << "If yes then write(1) else write(0)." << std::endl;
    std::cin >> number;
    {
        if (number == 1)
        {
            std::cout << "Enter the vertex whose Indegree, Outdegree and Degree you want to find:" << std::endl;
            std::cin >> a;
            std::cout << "Indegree:" << g.inDegree(a) << std::endl;
            std::cout << "Outdegree:" << g.outDegree(a) << std::endl;
            std::cout << "Degree:" << g.Degree(a) << std::endl;
            goto start;
        }

        else
        {
            std::cout << "Thank you!" << std::endl;
        }
    }

start1:
    int number1;
    std::cout << "Do you want to find friends of friends ?" << std::endl;
    std::cout << "If yes then write(1) else write(0)." << std::endl;
    std::cin >> number1;
    {
        if (number1 == 1)
        {
            std::cout << "Enter the node whose friend you want to find:" << std::endl;
            std::cin >> a;
            g.BreadthFirstTraversal(a);
            goto start1;
        }
        else
        {
            std::cout << "Thank you!" << std::endl;
        }
    }
}