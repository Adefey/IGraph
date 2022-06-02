// ListGraph, хранящий граф в виде массива списков смежности

#include <IGraph.h>
#include <vector>

#ifndef LISTRAPH
#define LISTGRAPH

struct ListGraph : public IGraph {
private:
  std::vector<std::vector<int>> sides;

public:
  ListGraph(size_t node_count);
  ListGraph(const IGraph &graph);
  ~ListGraph() = default;

  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;
  std::vector<int> GetPrevVertices(int vertex) const override;
};

#endif
