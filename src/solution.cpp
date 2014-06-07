#include "solution.hpp"

Solution::Solution(unsigned no_nodes_in_graph, Node *node)
: no_nodes_in_graph(no_nodes_in_graph)
, length(0)
{
  nodes.push_back(node);
  no_unique_nodes = 1;
}

Node* Solution::get_last_node() {
  return this->nodes[this->nodes.size() - 1];
}

unsigned Solution::get_cummulated_length(Edge *edge) const {
  unsigned node_size = edge->get_n2()->get_value().size();
  return this->length + node_size - edge->get_weight();
}

void Solution::visit(Node *node) {
  no_visits[node] += 1;
  if(no_visits[node] == 1) { no_unique_nodes += 1; }
}

Node* Solution::add_edge(Edge *edge) {
  Node *node = edge->get_n2();
  edges.push_back(edge);
  nodes.push_back(node);
  length = get_cummulated_length(edge);
  visit(node);
  return node;
}

double Solution::get_quality() {
  return (double)no_unique_nodes / no_nodes_in_graph;
}

ostream& operator<<(ostream& os, const Solution& solution) {
  vector<Node *> nodes = solution.get_nodes();
  os << "Solution(" << nodes.size() << "), length: " << solution.get_length() << endl;
  for (unsigned i = 0, len = nodes.size(); i < len; ++i) {
    os << nodes[i]->get_index() << endl;
  }
  return os;
}
