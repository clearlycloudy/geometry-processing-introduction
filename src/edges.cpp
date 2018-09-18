#include "edges.h"

#include <set>
#include <algorithm>
#include <utility>
#include <cassert>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  // ADD YOUR CODE HERE

  std::set<std::pair<int,int>> s;
  
  int num_rows = F.rows();

  //assumes faces are triangles
  for( int i = 0 ; i < num_rows; ++i ){

      //map pairs of sorted vert ids -> undirected edge
      int arr[3] = { F(i,0), F(i,1), F(i,2) };

      std::sort(arr,arr+3);

      s.insert( {arr[0],arr[1]} );
      s.insert( {arr[1],arr[2]} );
      s.insert( {arr[0],arr[2]} );
  }

  E.resize( s.size(), 2 );

  int row = 0;
  for( auto & i : s ){
      E(row,0) = i.first;
      E(row,1) = i.second;
      ++row;
  }
    
  return E;
}
