#include "WGraph.h"

#include <queue>
#include <set>

WGraph::WGraph(){
  m_size = 0;
  m_adj = NULL;
  m_conn = NULL;
}

WGraph::WGraph(unsigned int sz){
  m_size = sz;
  //allocate sz * sz adj matrix
  m_adj = new double*[sz];
  m_conn = new double*[sz];
  for(int i = 0; i < m_size; ++i){
    m_adj[i] = new double[sz];
    m_conn[i] = new double[sz];
  }
  //start with edges
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_adj[i][j] = std::numeric_limits<double>::max(); //essentially infinity
      m_conn[i][j] = std::numeric_limits<double>::max();
    }
  }
}

WGraph::~WGraph(){
  //release memory
}

void WGraph::addEdge(VertexID i, VertexID j, double w){
  if(i < m_size && j < m_size){
    m_adj[i][j] = w;
    m_adj[j][i] = w;
  }
}

void WGraph::removeEdge(VertexID i, VertexID j){
  if(i < m_size && j < m_size){
    m_adj[i][j] = std::numeric_limits<double>::max();
    m_adj[j][i] = std::numeric_limits<double>::max();
  }
}

bool WGraph::areAdjacent(VertexID i, VertexID j){
  return (m_adj[i][j] < std::numeric_limits<double>::max());
}


/*void WGraph::calcFW(){ //runtime complexity O(v^3)
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_conn[i][j] = m_adj[i][j]; //start with conn == adj matrix
    }
  }
  for(int im = 0; im < m_size; ++ im){ //intermediate points --> transitive closure
    for(int source = 0; source < m_size; ++source){ //source = starting point
      for(int sink = 0; sink <m_size; ++sink){ //sink = ending point
        if(source == sink){
          continue;
        }else if(m_conn[source][im] != std::numeric_limits<double>::max() &&
          m_conn[im][sink] != std::numeric_limits<double>::max() &&
          m_conn[source][sink] > m_conn[source][im] + m_conn[im][sink]){
           m_conn[source][sink] = m_conn[source][im] + m_conn[im][sink];
        }
      }
    }
  }
}*/

bool WGraph::AvoidLoop(VertexID start, VertexID target) { //Used Inspiration from Print DST code
  std::stack<VertexID> stk;
  std::set<VertexID> visited;
  stk.push(start);
  while (!stk.empty()) {
    VertexID current = stk.top();
    stk.pop();
    if (current == target) {
      std::cout << "True" << std::endl;
      return true;
    }

    if (visited.count(current) != 0) {
      continue;
    }

    visited.insert(current);

    for (unsigned int k = 0; k < m_size; ++k) {
      if (m_conn[current][k] != std::numeric_limits<double>::max() && visited.count(k) == 0) {
        stk.push(k);
      }
    }
  }

  return false; // No loop found
}


void WGraph::createKruskal(){
    double** temp = new double*[m_size]; //We will be altering the m_adj matrix, so this will be used to repopulate it
    for (int i = 0; i < m_size; ++i) {
        temp[i] = new double[m_size];
    }
    for (int i = 0; i < m_size; ++i) {
      for (int j = 0; j < m_size; ++j) {
        temp[i][j] = m_adj[i][j];
      }
    }
    int count = 1;

    while(count < m_size){
        double min[3] = {0,0,std::numeric_limits<double>::max()}; //Creates an array that can act as an edge
        for (int i = 0; i < m_size; i++){
            for(int j = 0; j < m_size; j++){
                if (m_adj[i][j] < min[2] && m_adj[i][j] != std::numeric_limits<double>::max()){
                    min[0] = i;
                    min[1] = j;
                    min[2] = m_adj[i][j]; //loops through finding new mins and updating the edge array
                }
            }
        }
        VertexID z = min[0]; //Conveverting from double to avoid a syntax error
        VertexID f = min[1];
        bool loop = AvoidLoop(z,f); //Uses a DST to make sure there isn't already a path between these two Vertexes

        if(loop == false){
            m_conn[z][f] = min[2];
            m_conn[f][z] = min[2];
            m_adj[z][f] = std::numeric_limits<double>::max() ;
            m_adj[f][z] = std::numeric_limits<double>::max() ;
            count++; //Add to count. There will be one less edge then there are rows or columns
        }
        else{
          m_adj[z][f] = std::numeric_limits<double>::max() ; //Remove from adjacncy matrix to avoid infinite loop
          m_adj[f][z] = std::numeric_limits<double>::max() ;
        }
    }
      for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
          m_adj[i][j] = temp[i][j]; //Repopulate m_adj with the original matrix
      }
    }
    for (int i = 0; i < m_size; ++i) {
      delete[] temp[i];
      }
    delete[] temp; //avoid data leak
}

void WGraph::printKruskal(){
    double z = 0;
    for (int i = 0; i < m_size; i++){
            std::cout << std::endl;
            for(int j = 0; j < m_size; j++){            
            if(m_conn[i][j] != std::numeric_limits<double>::max()){
              std::cout << m_conn[i][j] << "  ";
              z = z + m_conn[i][j];
        }
            else{
              std::cout << "INF  ";
            }
        }
    }
  std::cout << std::endl;
  std::cout << "Total: " << z/2 << std::endl;
}
double WGraph::cheapestCost(VertexID i, VertexID j){
  return m_conn[i][j]; //constant
}