void main(){
  dfs graph=dfs(4);
  graph.newEdge(0,1);
  graph.newEdge(0,2);
  graph.newEdge(1,2);
  graph.newEdge(2,0);
  graph.newEdge(2,3);
  graph.newEdge(3,3);
  graph.traverse(0);
}

class dfs{  
  int vertices;
  static List<List<int>> address;
  static Set<int> visited={};
  
  dfs(this.vertices){
    address = List<List<int>>(this.vertices);
    for(int index=0;index<this.vertices;index++){
      address[index]=List<int>();
    }
    
  }
  
  void newEdge(int start,int end){
        address[start].add(end);
  }
  
  void traverse(int vertex){
    print(vertex);
    visited.add(vertex);
    int length = address[vertex].length;
    for(int index=0;index<length;index++){
      if(!visited.contains(address[vertex].elementAt(index))){
        traverse(address[vertex].elementAt(index));
      }
    }
  }

}