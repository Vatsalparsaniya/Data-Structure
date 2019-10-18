public class Node {
    int value;
    Node nextNode;

    public Node(int v) {
        value = v;
        nextNode = null;
    }

    public int getValue() {
        return this.value;
    }

    public Node getNextNode() {
        return this.nextNode;
    }

    public void setNextNode(Node n) {
        this.nextNode = n;
    }
}