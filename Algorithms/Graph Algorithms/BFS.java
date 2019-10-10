package BFS;
// Java program to print Breadth First Search traversal from a given source vertex.
import java.io.*; 
import java.util.*; 
  
// Graph class represents a directed graph using adjacency list. 
class Graph 
{ 
    private int num_of_vertices;
    private LinkedList<Integer> adj[];  //Adjacency List
  
    Graph(int v) //Parameterized Constructor
    { 
        num_of_vertices = v; 
        adj = new LinkedList[v]; 
        for (int i=0; i<v; ++i) 
            adj[i] = new LinkedList(); 
    } 
  
    //addEdge Function adds an edge into the graph.
    void addEdge(int v,int w) 
    { 
        adj[v].add(w); 
    } 
  
    // below function prints BFS traversal from a given source vertex.
    void BFS(int s) 
    {  
        boolean visited[] = new boolean[num_of_vertices]; //By default all the vertices are set to false as they are not visited.

        LinkedList<Integer> queue = new LinkedList<Integer>(); //a queue for BFS
  
        visited[s]=true; //Mark current node as visited by setting it to true.
        queue.add(s); // enqueue the visited node.
  
        while (queue.size() != 0) 
        { 
            s = queue.poll();  // Dequeue a vertex from queue
            System.out.print(s+" ");  //print that vertex.
  
            // If a adjacent vertex has not been visited, then mark it as visited and enqueue it from queue.
            Iterator<Integer> i = adj[s].listIterator(); 
            while (i.hasNext()) 
            { 
                int n = i.next(); 
                if (!visited[n]) 
                { 
                    visited[n] = true; 
                    queue.add(n); 
                } 
            } 
        } 
    } 
  
    public static void main(String args[]) 
    { 
        Graph g = new Graph(5); 
  
        g.addEdge(0, 1); 
        g.addEdge(0, 2); 
        g.addEdge(1, 2); 
        g.addEdge(1, 4); 
        g.addEdge(1, 3); 
        g.addEdge(2, 4); 
        g.addEdge(3, 4); 
  
        System.out.println("Breadth First Traversal starting from vertex 0 : "); 
  
        g.BFS(0); 
    } 
} 