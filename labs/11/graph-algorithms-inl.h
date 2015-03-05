//Camden Wagner
//graph-algorithms-inl.h

#define INFINITY 999999
/**
 * Returns whether two vertices dest is reachable from src in the Graph g using
 *  depth-first search
 * @param src - source vertex
 * @param dest - destination vertex
 * @param g - pointer to Graph object
 * @return true if a path exists
 */
template <typename V, typename E, typename W>
bool reachableDFS(V src, V dest, Graph<V,E,W>* g) {
  HashTable<V,V>* isVisited = new HashTable<V,V>();
  return recursiveDFS(src, dest, g, isVisited);
}

template <typename V, typename E, typename W>
bool recursiveDFS(V src, V dest, Graph<V,E,W>* g, HashTable<V,V>* isVisited) {
  if (src == dest) {
    return true;
  }
  isVisited->insert(src, src);
  vector<V> neighbors = g->getNeighbors(src);
  int neighborLength = neighbors.size();
  for (int i = 0; i < neighborLength; i++) {
    if (!isVisited->containsKey(neighbors.back())) {
      if (recursiveDFS(neighbors.back(), dest, g, isVisited)) {
        return true;
      }
    }
    neighbors.pop_back();
  }
  return false;
}

/**
 * Returns the shortest length path found from the vertex src
 * to the vertex dest, using an unweighted breadth-first search of the graph.
 * @param src - source vertex
 * @param dest - destination vertex
 * @param g - pointer to Graph object
 * @return vector<V> - sequence of vertices in path from src to dest
 * @error throws runtime_error if no path exists
 */
template <typename V, typename E, typename W>
vector<V> shortestLengthPathBFS(V src, V dest, Graph<V,E,W>* g) {
  vector<V> path;
  vector<V> tempPath;
  ArrayQueue<V> queue;
  HashTable<V,V> routes;
  queue.enqueue(src);
  while (!queue.isEmpty()) {
    if (queue.getFront() == dest) {
      tempPath.push_back(dest);
      while (tempPath.back() != src) {
        tempPath.push_back(routes.get(tempPath.back()));
      }
      int tempPathLength = tempPath.size();
      for (int j = 0; j < tempPathLength; j++) {
        path.push_back(tempPath.back());
        tempPath.pop_back();
      }

      return path;
    }
    vector<V> neighbors = g->getNeighbors(queue.getFront());
    int neighborLength = neighbors.size();
    for (int i = 0; i < neighborLength; i++) {
      if (!routes.containsKey(neighbors.back())) {
        routes.insert(neighbors.back(), queue.getFront());
      }
      queue.enqueue(neighbors.back());
      neighbors.pop_back();
    }
    queue.dequeue();
  }
  throw std::runtime_error("No path exists.");
}


/**
 * dijkstra calculates the single source minimum distance to all other
 *   vertices in the graph from a src node
 * @param src - source vertex
 * @param g - pointer to Graph object to search
 * @return Dictionary<V,W> - Dictionary of vertices and their distance
 *    from src
 */
template <typename V, typename E, typename W>
Dictionary<V,W>* dijkstras(V src, Graph<V,E,W>* g) {
  BinaryHeap<W,V> PQ;
  HashTable<V,W>* DIST = new HashTable<V,W>();
  vector<V> vertices = g->getVertices();
  while (!vertices.empty()) {
    DIST->insert(vertices.back(), INFINITY);
    vertices.pop_back();
  }
  HashTable<V,bool> COMPLETED;
  vertices = g->getVertices();
  while (!vertices.empty()) {
    COMPLETED.insert(vertices.back(), false);
    vertices.pop_back();
  }
  
  PQ.insert(0, src);
  DIST->update(src, 0);

  while (!PQ.isEmpty()) {
    V u = PQ.removeMin();
    if (COMPLETED.get(u)) {
      continue;
    }
    COMPLETED.update(u, true);
    vector<V> neighbors = g->getNeighbors(u);
    int neighborLength = neighbors.size();
    for (int i = 0; i < neighborLength; i++) {
      V v = neighbors.back();
      neighbors.pop_back();
      Edge<V,E,W> edge = g->getEdge(u,v);
      W cost = edge.getWeight();
      if (!DIST->containsKey(v)) {
        DIST->update(v, DIST->get(u)+cost);
        PQ.insert(DIST->get(v), v);
      } else if (DIST->get(v) > DIST->get(u)+cost) {
        DIST->update(v, DIST->get(u)+cost);
        PQ.insert(DIST->get(v), v);
      }
    }
  }

  return DIST;
}
