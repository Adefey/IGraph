// MatrixGraph, хранящий граф в виде матрицы смежности

#include <IGraph.h>
#include <vector>

#ifndef MATRIXGRAPH
#define MATRIXGRAPH

struct MatrixGraph : public IGraph {
private:
  std::vector<std::vector<bool>> sides;

public:
  MatrixGraph(size_t node_count);
  MatrixGraph(const IGraph &graph);
  ~MatrixGraph() = default;

  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;
  std::vector<int> GetPrevVertices(int vertex) const override;
};

#endif
