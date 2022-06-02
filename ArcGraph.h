// ArcGraph, хранящий граф в виде одного массива пар {from, to}

#include <IGraph.h>
#include <vector>

#ifndef ARCGRAPH
#define ARCGRAPH

struct FromTo {
  int from;
  int to;
  FromTo(int from, int to);
};

struct ArcGraph : public IGraph {
private:
  std::vector<FromTo> sides;
  size_t count;

public:
  ArcGraph(size_t node_count);
  ArcGraph(const IGraph &graph);
  ~ArcGraph() = default;

  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;
  std::vector<int> GetPrevVertices(int vertex) const override;
};

#endif
