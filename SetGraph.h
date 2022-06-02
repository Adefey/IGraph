// SetGraph, хранящий граф в виде массива хэш-таблиц/сбалансированных деревьев
// поиска

#include <IGraph.h>
#include <unordered_set>
#include <vector>

#ifndef SETGRAPH
#define SETGRAPH

struct SetGraph : public IGraph {
private:
  std::vector<std::unordered_set<int>> nodes;
  std::vector<std::unordered_set<int>> nodes_r;

public:
  SetGraph(size_t node_count);
  SetGraph(const IGraph &graph);
  ~SetGraph() = default;

  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;
  std::vector<int> GetPrevVertices(int vertex) const override;
};

#endif
