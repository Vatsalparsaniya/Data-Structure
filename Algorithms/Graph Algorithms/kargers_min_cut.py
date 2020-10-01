"""
Karger’s Min Cut algorithm
--------------------------
input should be in the file "input-graph.txt"
There should be one line for each vertex.
The first entry in each line represents the vertex number, the remaining numbers in each line encode the edges from that vertex.
For e.g. line 2 is
2 123 134 10 ...
which represents that vertex 2 has edges to vertices numbered 123, 134 10,.. and so on.
"""

from random import randint
class DisjointSet:
    def __init__(self,v):
        self.v=v
        self.p=self
        self.rank=0

    def link(x,y):
        if x.rank>y.rank:
            y.p=x
            return y
        else:
            x.p=y
            if x.rank==y.rank:
                y.rank+=1
            return x
    def findSet(x):
        if x!=x.p:
            x.p=DisjointSet.findSet(x.p)
        return x.p
    def sameComponent(x,y):
        if DisjointSet.findSet(x)==DisjointSet.findSet(y):
            return True
        return False
    def union(x,y):
        DisjointSet.link(DisjointSet.findSet(x),DisjointSet.findSet(y))

def parseFile(filename):
    with open(filename,'r') as al:
        content = al.readlines()
    adj_list = [x.strip().split() for x in content]
    edges=[]#contains edges - list of tuple
    vertices=[]#contains vertices - list of int
    for  a_list in adj_list:
        vertices.append(int(a_list[0]))
        for i in range(1,len(a_list)):
            edges.append((int(a_list[0]),int(a_list[i])))


    #to remove duplicates
    vertices=list(set(vertices))
    edges=list(set(edges))
    #to remove (b,a) if (a.b) exists
    for edge in range(len(edges)-1,-1,-1):
        if (edges[edge][1],edges[edge][0]) in edges:
            print("[INFO]:removing ",edges[edge])
            del edges[edge]
        #to remove self-loops
        elif edges[edge][0]==edges[edge][1]:
            print("[INFO]:removing ",edges[edge])
            del edges[edge]
    #print(edges)
    return vertices,edges
def main(vertices,edges):
    min_cut=len(vertices)
    for i in range(100):
        e=edges[:]
        V=vertices[:]
        DSForest=dict()
        for vertex in V:
            DSForest.update({vertex:DisjointSet(vertex)})
        #v- number of vertices
        v=len(V)
        #continue till number of components becomes 2
        while(v>2):
            edge=randint(0,len(e)-1)
            print("Edge picked = ",e[edge])
            #join components
            if(DisjointSet.findSet(DSForest[e[edge][0]])!=DisjointSet.findSet(DSForest[e[edge][1]])):
                DisjointSet.union(DSForest[e[edge][0]],DSForest[e[edge][1]])
                v-=1
            #remove processed edge
            print("[INFO]:removing edge",e[edge])
            del e[edge]
        #remove edges edges belonging to same components(self-loop)
        for edge in range(len(e)-1,-1,-1):
            if DisjointSet.sameComponent(DSForest[e[edge][0]],DSForest[e[edge][1]]):
                print("[INFO]In same component : removing edge",e[edge])
                del e[edge]
            else:
                print("[INFO]In different component : ",e[edge])
        for j in DSForest.keys():
            print("vertex= ",j," Parent : ",DSForest[j].p.v," Rank : ",DSForest[j].rank)
        print("Remaining Edges : ",e)
        print("Number of cuts required : ",len(e))
        #update min-cut
        if len(e)<min_cut:
            min_cut=len(e)
    return min_cut
if __name__=='__main__':
    vertices,edges=parseFile("input-graph.txt")
    print("Vertices : ",vertices)
    print("Edges : ",edges)
    min_cut=main(vertices,edges)
    print("\nMin-cut = ",min_cut,end="\n\n")
