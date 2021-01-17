#ifndef Node_H
#define Node_H
#define MAX_DIST 1000

class Node
{
public:
    int id;   // Key
    int dist; // Value
    Node *prev;

    Node()
    {
    }

    Node(int id_)
    {
        id = id_;
        dist = MAX_DIST + 1;
        prev = 0;
    }
};

#endif