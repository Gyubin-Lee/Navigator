#include "dijkstra.h"
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int j, k;
    int vertex, edge;
    int start;

    cout << "지점의 개수를 입력해주세요: ";
    cin >> vertex;

    Node **nodeList = new Node *[vertex];

    for (j = 0; j < vertex; j++)
    {
        nodeList[j] = new Node(j + 1);
    }

    int **dist = new int *[vertex];
    for (j = 0; j < vertex; j++)
    {
        dist[j] = new int[vertex];
    }

    for (j = 0; j < vertex; j++)
    {
        for (k = 0; k < vertex; k++)
        {
            dist[j][k] = 1001;
        }
    }

    cout << "도로의 개수를 입력해주세요: ";
    cin >> edge;

    j = 0;
    while (j < edge)
    {
        int u, v, d;
        cout << "시작 지점 id, 도착 지점 id, 거리를 입력해주세요(" << j + 1 << "/" << edge << "):";
        cin >> u >> v >> d;
        dist[u - 1][v - 1] = d;
        j++;
    }

    cout << "시작점의 id를 입력해주세요: ";
    cin >> start;

    cout << "시작점에서 출발하는 최적의 경로를 탐색하는 중입니다" << endl;

    nodeList = dijkstra(nodeList, dist, vertex, start);

    int dest;
    cout << "최적의 경로 탐색이 완료되었습니다" << endl;

    char com;
    while (1)
    {
        cout << "원하시는 목적지의 id를 입력하세요: ";
        cin >> dest;

        printResult(nodeList, dest);
        cout << "다른 목적지도 가는 길도 찾아볼까요?(Y/n)";
        cin >> com;
        if (com == 'Y')
            continue;
        else
            break;
    }
}