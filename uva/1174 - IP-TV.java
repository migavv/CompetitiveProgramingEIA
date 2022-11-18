package uva1174;

import java.util.*;

public class Main {
    static int N;
    static Vertex[] G;
    static final int INF = Integer.MAX_VALUE;

    static class Vertex {
        int id;
        List<Edge> adjacencyList = new ArrayList<>();

        public Vertex(int id) {
            this.id = id;
        }
    }
    static class Edge {
        Vertex to;
        int weight;

        public Edge(Vertex to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    static class QueueItem implements Comparable<QueueItem>{
        Vertex v;
        int distance;

        public QueueItem(Vertex v, int distance) {
            this.v = v;
            this.distance = distance;
        }

        @Override
        public int compareTo(QueueItem o) {
            return this.distance - o.distance;
        }
    }

    static int prim(int s) {
        boolean[] inTree = new boolean[N];
        int[] distance = new int[N];
        int[] parent = new int[N];
        int cost = 0;

        Arrays.fill(distance, INF);
        Arrays.fill(parent, -1);
        distance[s] = 0;

        PriorityQueue<QueueItem> Q = new PriorityQueue<>();
        Q.offer(new QueueItem(G[s], 0));
        while(!Q.isEmpty()) {
            QueueItem qi = Q.poll();
            Vertex v = qi.v;
            if(!inTree[v.id]) {
                inTree[v.id] = true;
                for(Edge edge : v.adjacencyList) {
                    Vertex w = edge.to;
                    int weight = edge.weight;
                    if(!inTree[w.id] && weight < distance[w.id]) {
                        distance[w.id] = weight;
                        parent[w.id] = v.id;
                        Q.offer(new QueueItem(w, weight));
                    }
                }
            }
        }
        for (int i = 0; i < N; i++)
            cost += distance[i];
        return cost;
    }
}
