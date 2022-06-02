/*
Необходимо написать несколько реализаций интерфейса:
ListGraph, хранящий граф в виде массива списков смежности,
MatrixGraph, хранящий граф в виде матрицы смежности,
SetGraph, хранящий граф в виде массива хэш-таблиц/сбалансированных деревьев
поиска, ArcGraph, хранящий граф в виде одного массива пар {from, to}. Также
необходимо реализовать конструктор, принимающий const IGraph&. Такой конструктор
 должен скопировать переданный граф в создаваемый объект. Для каждого класса
создавайте отдельные h и cpp файлы. Число вершин графа задается в конструкторе
каждой реализации.
 */

#include <algorithm>
#include <cstddef>
#include <vector>

#ifndef IGRAPH
#define IGRAPH

struct IGraph {
  virtual ~IGraph() {}

  // Добавление ребра от from к to.
  virtual void AddEdge(int from, int to) = 0;

  virtual int VerticesCount() const = 0;

  virtual std::vector<int> GetNextVertices(int vertex) const = 0;
  virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

inline bool operator==(const IGraph &l, const IGraph &r) {

  if (l.VerticesCount() != r.VerticesCount()) {
    return false;
  }

  for (int i = 0; i < l.VerticesCount(); ++i) {
    std::vector<int> next_l = l.GetNextVertices(i);
    std::vector<int> next_r = r.GetNextVertices(i);
    std::sort(next_l.begin(), next_l.end());
    std::sort(next_r.begin(), next_r.end());
    if (next_l != next_r) {
      return false;
    }

    std::vector<int> prev_l = l.GetPrevVertices(i);
    std::vector<int> prev_r = r.GetPrevVertices(i);
    std::sort(prev_l.begin(), prev_l.end());
    std::sort(prev_r.begin(), prev_r.end());
    if (prev_l != prev_r) {
      return false;
    }
  }
  return true;
}
#endif
