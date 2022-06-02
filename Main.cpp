#include <iostream>

#include <ArcGraph.h>
#include <IGraph.h>
#include <ListGraph.h>
#include <MatrixGraph.h>
#include <SetGraph.h>
#include <gtest/gtest.h>

TEST(Graphs, EqualArc) {
  ArcGraph a = ArcGraph(5);
  a.AddEdge(1, 2);
  a.AddEdge(3, 2);
  a.AddEdge(4, 1);
  a.AddEdge(1, 0);
  ArcGraph b = ArcGraph(5);
  b.AddEdge(4, 1);
  b.AddEdge(3, 2);
  b.AddEdge(1, 0);
  b.AddEdge(1, 2);
  EXPECT_TRUE(a == b);
}

TEST(Graphs, EqualList) {
  ListGraph a = ListGraph(5);
  a.AddEdge(1, 2);
  a.AddEdge(3, 2);
  a.AddEdge(4, 1);
  a.AddEdge(1, 0);
  ListGraph b = ListGraph(5);
  b.AddEdge(4, 1);
  b.AddEdge(3, 2);
  b.AddEdge(1, 0);
  b.AddEdge(1, 2);
  EXPECT_TRUE(a == b);
}

TEST(Graphs, EqualMatrix) {
  MatrixGraph a = MatrixGraph(5);
  a.AddEdge(1, 2);
  a.AddEdge(3, 2);
  a.AddEdge(4, 1);
  a.AddEdge(1, 0);
  MatrixGraph b = MatrixGraph(5);
  b.AddEdge(4, 1);
  b.AddEdge(3, 2);
  b.AddEdge(1, 0);
  b.AddEdge(1, 2);
  EXPECT_TRUE(a == b);
}

TEST(Graphs, EqualSet) {
  SetGraph a = SetGraph(5);
  a.AddEdge(1, 2);
  a.AddEdge(3, 2);
  a.AddEdge(4, 1);
  a.AddEdge(1, 0);
  SetGraph b = SetGraph(5);
  b.AddEdge(4, 1);
  b.AddEdge(3, 2);
  b.AddEdge(1, 0);
  b.AddEdge(1, 2);
  EXPECT_TRUE(a == b);
}

TEST(Graphs, EqualArcArc) {
  ArcGraph arc = ArcGraph(5);
  arc.AddEdge(1, 2);
  arc.AddEdge(3, 2);
  arc.AddEdge(4, 2);
  arc.AddEdge(1, 3);
  arc.AddEdge(3, 1);
  arc.AddEdge(1, 0);
  arc.AddEdge(3, 0);
  arc.AddEdge(3, 4);
  ArcGraph arc2 = ArcGraph(arc);
  EXPECT_TRUE(arc == arc2);
}

TEST(Graphs, EqualArcList) {
  ArcGraph arc = ArcGraph(5);
  arc.AddEdge(1, 2);
  arc.AddEdge(3, 2);
  arc.AddEdge(4, 2);
  arc.AddEdge(1, 3);
  arc.AddEdge(3, 1);
  arc.AddEdge(1, 0);
  arc.AddEdge(3, 0);
  arc.AddEdge(3, 4);
  ListGraph list = ListGraph(arc);
  EXPECT_TRUE(arc == list);
}

TEST(Graphs, EqualArcMatrix) {
  ArcGraph arc = ArcGraph(5);
  arc.AddEdge(1, 2);
  arc.AddEdge(3, 2);
  arc.AddEdge(4, 2);
  arc.AddEdge(1, 3);
  arc.AddEdge(3, 1);
  arc.AddEdge(1, 0);
  MatrixGraph matrix = MatrixGraph(arc);
  EXPECT_TRUE(arc == matrix);
}

TEST(Graphs, EqualArcSet) {
  ArcGraph arc = ArcGraph(5);
  arc.AddEdge(1, 2);
  arc.AddEdge(3, 2);
  arc.AddEdge(4, 2);
  arc.AddEdge(1, 3);
  arc.AddEdge(3, 1);
  arc.AddEdge(1, 0);
  SetGraph set = SetGraph(arc);
  EXPECT_TRUE(arc == set);
}

TEST(Graphs, EqualBIG) {
  int size = 10000;
  ArcGraph arc = ArcGraph(size);
  for (int i = 0; i < size; ++i) {
    arc.AddEdge(i, size - i - 1);
  }
  ArcGraph arc2 = ArcGraph(arc);
  EXPECT_TRUE(arc == arc2);
  ListGraph list = ListGraph(arc);
  EXPECT_TRUE(arc == list);
  MatrixGraph matrix = MatrixGraph(arc);
  EXPECT_TRUE(arc == matrix);
  SetGraph set = SetGraph(arc);
  EXPECT_TRUE(arc == set);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
