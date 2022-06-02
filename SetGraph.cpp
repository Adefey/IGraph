#include <SetGraph.h>

SetGraph::SetGraph(size_t node_count)
    : nodes(node_count), nodes_r(node_count) {}

SetGraph::SetGraph(const IGraph &graph) {
  nodes.resize(graph.VerticesCount());
  nodes_r.resize(graph.VerticesCount());
  for (int i = 0; i < static_cast<int>(nodes.size()); ++i) {
    std::vector<int> next = graph.GetNextVertices(i);
    for (int j = 0; j < static_cast<int>(next.size()); ++j) {
      AddEdge(i, next[j]);
    }
  }
}

void SetGraph::AddEdge(int from, int to) {
  nodes[from].insert(to);
  nodes_r[to].insert(from);
}

int SetGraph::VerticesCount() const { return static_cast<int>(nodes.size()); }

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
  std::vector<int> res = std::vector<int>(nodes[vertex].size());
  std::copy(nodes[vertex].begin(), nodes[vertex].end(), res.begin());
  return res;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
  std::vector<int> res = std::vector<int>(nodes_r[vertex].size());
  std::copy(nodes_r[vertex].begin(), nodes_r[vertex].end(), res.begin());
  return res;
}
