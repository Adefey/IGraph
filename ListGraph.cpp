#include <ListGraph.h>

ListGraph::ListGraph(size_t node_count) : sides(node_count) {}

ListGraph::ListGraph(const IGraph &graph) {
  sides.resize(graph.VerticesCount());
  for (int from = 0; from < static_cast<int>(sides.size()); ++from) {
    std::vector<int> to = graph.GetNextVertices(from);
    for (int side : to) {
      AddEdge(from, side);
    }
  }
}

void ListGraph::AddEdge(int from, int to) { sides[from].push_back(to); }

int ListGraph::VerticesCount() const { return static_cast<int>(sides.size()); }

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
  std::vector<int> res = {};
  for (int i = 0; i < static_cast<int>(sides[vertex].size()); ++i) {
    res.push_back(sides[vertex][i]);
  }
  return res;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
  std::vector<int> res = {};
  for (int i = 0; i < static_cast<int>(sides.size()); ++i) {
    for (int j = 0; j < static_cast<int>(sides[i].size()); ++j) {
      if (sides[i][j] == vertex) {
        res.push_back(i);
      }
    }
  }
  return res;
}
