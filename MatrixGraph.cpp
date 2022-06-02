#include <MatrixGraph.h>

MatrixGraph::MatrixGraph(size_t node_count) : sides(node_count) {
  for (int i = 0; i < static_cast<int>(node_count); ++i) {
    sides[i].assign(node_count, false);
  }
}

MatrixGraph::MatrixGraph(const IGraph &graph) {
  sides.resize(graph.VerticesCount());
  for (int i = 0; i < static_cast<int>(sides.size()); ++i) {
    sides[i].assign(sides.size(), false);
  }

  for (int from = 0; from < static_cast<int>(sides.size()); ++from) {
    std::vector<int> to = graph.GetNextVertices(from);
    for (int side : to) {
      AddEdge(from, side);
    }
  }
}

void MatrixGraph::AddEdge(int from, int to) { sides[from][to] = true; }

int MatrixGraph::VerticesCount() const {
  return static_cast<int>(sides.size());
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
  std::vector<int> res = {};
  for (int i = 0; i < static_cast<int>(sides.size()); ++i) {
    if (sides[vertex][i] == true) {
      res.push_back(i);
    }
  }
  return res;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
  std::vector<int> res = {};
  for (int i = 0; i < static_cast<int>(sides.size()); ++i) {
    if (sides[i][vertex] == true) {
      res.push_back(i);
    }
  }
  return res;
}
