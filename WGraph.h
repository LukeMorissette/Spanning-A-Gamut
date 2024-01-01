#ifndef WGraph_H
#define WGraph_H

#include <cstdlib>
#include <deque>
#include <set>
#include <stack>
#include <iostream>
#include <limits>

//a weighted, undirected WGraph implemented with adjacency matrix
//fixed size

typedef unsigned int VertexID;

class WGraph{
public: 
  WGraph();
  WGraph(unsigned int sz);
  ~WGraph();
  void addEdge(VertexID i, VertexID j, double w);
  void removeEdge(VertexID i, VertexID j);
  bool areAdjacent(VertexID i, VertexID j);
  double cheapestCost(VertexID i, VertexID j);
  void calcFW();
  void createKruskal();
  bool AvoidLoop(VertexID start, VertexID target);
  void printKruskal();

private:
  double** m_adj; //is there an edge between two vertices and what's the weight of the edge
  double** m_conn; //more general, is there a path between a start and a finish and what's the cost (all parts summed)
  unsigned int m_size; //nodes in WGraph (fixed)

};

#endif