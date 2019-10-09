// Java program to print Depth First Search traversal from a given source vertex
import java.io.*;
import java.util.*;

// Graph class represents a directed graph using adjacency list
class Graph {
    private int num_of_vertices;
    private LinkedList<Integer> adj[];  // adjacency list

    // parameterized constructor
    Graph(int v) {
        num_of_vertices = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; i++)
            adj[i] = new LinkedList<Integer>();
    }

    // adds an edge into the graph
    void addEdge(int v, int w) {
        adj[v].add(w);
    }

    // prints DFS traversal from a given source vertex
    // uses DFSUtil(..) for recursive calls
    void DFS(int v) {
        // mark all the vertices as not visited (set as false by default in java) 
        boolean visited[] = new boolean[num_of_vertices];

        // Call the recursive helper function to print DFS traversal
        DFSUtil(v, visited);
    }

    // helper function called by DFS(..) for recursive calls
    void DFSUtil(int v, boolean visited[]) {
        // mark the current node as visited and print it
        visited[v] = true;
        System.out.print(v + " ");

        // recur from all the vertices adjacent to current vertex
        Iterator<Integer> i = adj[v].listIterator();
        while (i.hasNext()) {
            int n = i.next();
            if (!visited[n])
                DFSUtil(n, visited);
        }
    }


    // Driver Program
    public static void main(String args[]) {
        Graph g = new Graph(5);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(1, 4);
        g.addEdge(1, 3);
        g.addEdge(2, 4);
        g.addEdge(3, 4);

        /*
            0 -> 1 -> 3
            |  / |  /
            V L  V L
             2 -> 4
        */

        System.out.println("Depth First Traversal starting from vertex 0:");

        g.DFS(0);
    }
}