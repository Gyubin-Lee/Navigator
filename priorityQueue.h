#ifndef P_QUEUE_H
#define P_QUEUE_H

#define MAX_ITEM 100

#include "node.h"
#include <iostream>

using namespace std;

class PriorityQueue
{
private:
    Node *item[MAX_ITEM];
    int maxIndex = 0;

    bool greater(int i, int j)
    {
        return item[i]->dist > item[j]->dist;
    }

    void exch(int i, int j)
    {
        Node *swap = item[i];
        item[i] = item[j];
        item[j] = swap;
    }

    void swim(int k)
    {
        while (k > 1 && greater(k / 2, k))
        {
            exch(k, k / 2);
            k = k / 2;
        }
    }

    void sink(int k)
    {
        while (2 * k <= maxIndex)
        {
            int j = 2 * k;
            if (j < maxIndex && greater(j, j + 1))
                j++;
            if (!greater(k, j))
                break;
            exch(k, j);
            k = j;
        }
    }

public:
    PriorityQueue()
    {
        item[0] = new Node(0);
    }

    void push(Node *node)
    {
        if (maxIndex >= MAX_ITEM - 1)
        {
            cout << "No entry" << endl;
            return;
        }
        item[++maxIndex] = node;
        swim(maxIndex);
    }

    Node *pop()
    {
        Node *min;

        if (maxIndex == 0)
        {
            cout << "No item to pop" << endl;
            min = new Node(-1);
            return min;
        }
        min = item[1];
        exch(1, maxIndex--);
        sink(1);
        return min;
    }

    void printItem()
    {
        int i = 1;
        for (i = 1; i <= maxIndex; i++)
        {
            cout << "(" << item[i]->id << ", " << item[i]->dist << ") ";
        }
        cout << endl;
    }

    void decreaseKey(int id, int newDist)
    {
        int i = 1;
        while (i <= maxIndex)
        {
            if (item[i]->id == id)
                break;
            i++;
        }
        Node *temp = item[i];
        temp->dist = newDist;
        swim(i);
    }

    int isEmpty()
    {
        return maxIndex == 0;
    }
};

#endif