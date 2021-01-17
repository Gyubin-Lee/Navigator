#include "dijkstra.h"
#include <stack>

Node **dijkstra(Node **nodeList, int **dist, int vertex, int start)
{
    PriorityQueue nodeQueue = PriorityQueue();

    int j;
    for (j = 0; j < vertex; j++)
    {
        nodeQueue.push(nodeList[j]);
    }

    nodeQueue.decreaseKey(start, 0);

    while (!nodeQueue.isEmpty())
    {
        Node *temp = nodeQueue.pop();
        int tid = temp->id;
        int i, tDist;
        for (i = 0; i < vertex; i++)
        {
            tDist = dist[tid - 1][i];
            if (tDist < 1001)
            {
                int maybeShorter = nodeList[tid - 1]->dist + dist[tid - 1][i];
                if (nodeList[i]->dist > maybeShorter)
                {
                    nodeQueue.decreaseKey(i + 1, maybeShorter);
                    nodeList[i]->prev = temp;
                }
            }
        }
    }

    return nodeList;
}

void printResult(Node **nodeList, int dest)
{
    Node *result = nodeList[dest - 1];

    if (result->dist > 1000)
        cout << "그곳엔 도달할 수 없습니다!" << endl;
    else
    {
        cout << "최단 경로: ";
        Node *temp = result;
        stack<Node *> tStack;
        while (temp)
        {
            tStack.push(temp);
            temp = temp->prev;
        }
        while (!tStack.empty())
        {
            temp = tStack.top();
            cout << temp->id;
            if (tStack.size() > 1)
                cout << "-> ";
            tStack.pop();
        }

        cout << "\n최단 경로의 거리: " << result->dist << endl;
    }
}