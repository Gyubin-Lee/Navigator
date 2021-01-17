#ifndef DJST_h
#define DJST_h

#include "priorityQueue.h"

Node **dijkstra(Node **nodeList, int **dist, int vertex, int start);
void printResult(Node **nodeList, int dest);

#endif