#include <ArcGraph.h>

FromTo::FromTo(int from, int to) {
  this->from = from;
  this->to = to;
}

ArcGraph::ArcGraph(size_t node_count) : count(node_count) {}

ArcGraph::ArcGraph(const IGraph &graph) {
  count = graph.VerticesCount();
  for (int from = 0; from < static_cast<int>(count); ++from) {
    std::vector<int> to = graph.GetNextVertices(from);
    for (int side : to) {
      AddEdge(from, side);
    }
  }
}

void ArcGraph::AddEdge(int from, int to) { sides.push_back(FromTo(from, to)); }

int ArcGraph::VerticesCount() const { return count; }

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
  std::vector<int> res = {};
  for (FromTo side : sides) {
    if (side.from == vertex) {
      res.push_back(side.to);
    }
  }
  return res;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
  std::vector<int> res = {};
  for (FromTo side : sides) {
    if (side.to == vertex) {
      res.push_back(side.from);
    }
  }
  return res;
}
