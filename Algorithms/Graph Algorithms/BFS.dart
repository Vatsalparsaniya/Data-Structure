import 'dart:collection'; 

void main(){
  bfs b=bfs(4);
  b.addEdge(0, 1); 
  b.addEdge(0, 2); 
  b.addEdge(1, 2); 
  b.addEdge(2, 0); 
  b.addEdge(2, 3); 
  b.addEdge(3, 3); 
  b.traverse(0);
}

class bfs{
  List<List<int>>address;
  Set<int> visited= {};
  Queue<int> queue = Queue<int>(); 
  int vertices;
  
  bfs(this.vertices){
    address=List<List<int>>(this.vertices);  
    for(int index=0;index<this.vertices;index++){
      address[index]=List<int>();
    }
  }
  
  void addEdge(int start, int end){
    address[start].add(end);
  }
  
  void traverse(int start){
    visited.add(start);
    queue.add(start);
    while(queue.isNotEmpty){
      int visit=queue.removeFirst();
      print(visit);
      
      for(int index=0;index<address[visit].length;index++){
        int vertex = address[visit].elementAt(index);
        if(!visited.contains(vertex)){
        
          queue.add(vertex);
          visited.add(vertex);
          
        }
      }
    }
  }
  
}