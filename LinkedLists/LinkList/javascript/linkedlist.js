// This is the javascript program for a linked list. It does basic addition, deletion of the
// elements in the list.

class linkedlist{
    constructor()
    {
    this.size = 0;
    this.head = null;

//Node object declared as a class member
    
    this.elem  = 
    class element{
        constructor(d)
        {
          this.data = d;
          this.next = null;
        }
    }
}

//Insert an element at the last of the list

insert(data)
    {   
        this.size++;
        let new_node = new this.elem(data);

        if(this.head === null)
        {
        this.head = new_node;
        
        }
        else{
            let last_node = this.head;

            while(last_node.next !== null)
            last_node = last_node.next;
            last_node.next = new_node;
        }
    }

//insert an element at the specified index

insertAt(data,index)
    {
    this.size++;
    let curr_node = this.head, prev_node = curr_node, i = index;
    let new_node = new this.elem(data);
    if(i===0)
    {   
        new_node.next = this.head;
        this.head = new_node;
    }
    else
    {
    while(i--!==0)
    {
      prev_node = curr_node;
      curr_node = curr_node.next;
    }
    prev_node.next = new_node;
    new_node.next = curr_node;

}
    }

//delete an element at the specified index

deleteAt(index) 
    {   
        this.size--;
        let curr_node = this.head,prev_node = curr_node, i = index;
        if(i===0)
        {
        this.head = curr_node.next;
        curr_node.next = null;
        }
        else
        {
        while(i--!==0)
        {
        prev_node = curr_node;
        curr_node = curr_node.next;
        }
        prev_node.next = curr_node.next;
        curr_node.next = null;
    }
    }

//print the elemets of the list

print()
    {
        let node = this.head;
        while(node!==null)
        {
        console.log(node.data);
        node = node.next;
        }
        console.log(`size: ${this.size}`);
    }
    
}

//Demo list

let my_list = new linkedlist();
my_list.insert(4);
my_list.insert(6);
my_list.insert(8);
my_list.insert(10);
my_list.print();