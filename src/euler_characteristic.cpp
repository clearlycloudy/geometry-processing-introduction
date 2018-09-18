#include "euler_characteristic.h"
#include "edges.h"

#include <unordered_set>

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;
  // ADD YOUR CODE HERE

  Eigen::MatrixXi e = edges(F);

  int num_faces = F.rows();

  int num_edges = e.rows();

  std::unordered_set<int> s;

  for( int i = 0; i < num_faces; ++i ){
      s.insert( F(i,0) );
      s.insert( F(i,1) );
      s.insert( F(i,2) );
  }

  int num_verts = s.size();

  Chi = num_verts - num_edges + num_faces;
  
  return Chi;
}
