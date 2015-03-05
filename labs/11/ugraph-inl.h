/**
 * inserts an undirected edge into the graph.
 * @param src - source vertex for the directed edge.  If src is not already
 *              in the graph, it is inserted as a vertex
 * @param dest - destination vertex for the edge.  If dest is not already in
 *              the graph, it is inserted as a vertex
 * @param label - label for edge
 * @param weight (optional) - weight for edge; 1 if not provided
 * @error throws runtime_error if edge already exists
 */
template <typename V, typename E, typename W>
void UGraph<V,E,W>::insertEdge(V src, V dest, E label, W weight) {
  Graph<V,E,W>::insertEdge(src,dest,label,weight);
  Graph<V,E,W>::insertEdge(dest,src,label,weight);
}

/**
 * Removes undirected edge from src--dest from the graph
 * @param src - vertex label of source node
 * @param dest - vertex label of destination node
 * @error throws runtime_error if src--dest is not in the graph.
 */
template <typename V, typename E, typename W>
void UGraph<V,E,W>::removeEdge(V src, V dest) {
  //TODO: complete this method
  Graph<V,E,W>::removeEdge(src, dest);
  Graph<V,E,W>::removeEdge(dest, src);
}

/**
 * Returns a vector of all edges in the graph.
 * @return vector< Edge<V,E,W> > - vector of Edge objects, one for
 *  each edge in the graph
 */
template <typename V, typename E, typename W>
vector<Edge<V,E,W> > UGraph<V,E,W>::getEdges() {
  //TODO: get edges from Graph version, remove "duplicates"
  //e.g., remove dest->src and keep src->dest
  vector<Edge<V,E,W> > edges;
  //return val ^
  vector<Edge<V,E,W> > allEdges = Graph<V,E,W>::getEdges();

  int allEdgesLength = allEdges.size();
  for (int i = 0; i < allEdgesLength; i++) {
    bool isDuplicate = false;
    int edgesLength = edges.size();
    for (int j = 0; j < edgesLength; j++) {
      if (allEdges.back().getDest() == edges[j].getSrc()) {
        isDuplicate = true;
      }
    }
    if (!isDuplicate) {
      edges.push_back(allEdges.back());
    }
    allEdges.pop_back();
  }

  //loop through allEdges
  //  insert allEdges.front to edges if
  //    edges!contain the reciprocal of allEdges.front
  //  else remove allEdges.front
  //

  return edges;
  
}

/* outputs Graph object to file in GraphViz format.  For undirected graphs,
 *  this is in the format for neato
 */
template <typename V, typename E, typename W>
void UGraph<V,E,W>::graphViz(std::string filename) {
  std::ofstream out(filename.c_str());
  
  Queue<Pair<V,vector<Edge<V,E,W> >* > >* it =
      Graph<V,E,W>::outgoingEdges.getItems();
  out << "graph G{\n" ;
  out << "  node [ shape=plaintext fontsize=8 ];\n";
  out << "  edge [ penwidth=3];\n";
  while (!it->isEmpty()) {
    Pair<V,vector<Edge<V,E,W> >* > next = it->dequeue();
    V src = next.first;
    vector<Edge<V,E,W> >* neighb = next.second;
    for (int i = 0; i < neighb->size(); ++i) {
      V dest = neighb->at(i).getDest();
      if(src>dest) continue; 
      W len = neighb->at(i).getWeight();
      out << "  \"" << src << "\" -- \"";
      out << dest << "\" [ len=" << len << "];\n";
    }
  }
  out << "}\n";
  delete it;
  out.close();
}

