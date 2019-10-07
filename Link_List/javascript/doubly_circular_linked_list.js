//This is a program for Doubly Circular Linkedlist in Javascript
// It performs basic operation of adding an element at the last,
// adding an element at a specified index and deleting an element at an index
class doublyCircularLinkedlist
{
    constructor()
    {
        this.size = 0;
        this.head = null;
        this.element = 
        class node{
           constructor(d)
           {   
               this.prev = null;
               this.next = null;
               this.data = d;
           }
        } 
    }

    // Inserts an element at the last

    insert(data)
    {  
       this.size++;
       let new_node = new this.element(data);
       if(this.head === null)
       {   
           
           this.head = new_node;
           this.head.prev = new_node;
           this.head.next = new_node;
       }
       else
       {   
           
           let last_node = this.head;
           while(last_node.next !== this.head)
           {
               last_node = last_node.next;
           }
           last_node.next = new_node;
           new_node.prev = last_node;
           new_node.next = this.head;
           this.head.prev = new_node;
       }
    }

    //Inserts element at that index

    insertAt(data,index)
    {
      if(index>this.size-1 || index<0) throw "invalid index";
      else{
       this.size++;
       let curr_node = this.head, i = index;
       let new_node = new this.element(data);
      if(index===0)
    {   
        new_node.prev = this.head.prev;
        this.head.prev.next = new_node;
        this.head.prev = new_node
        new_node.next = this.head;
        this.head = new_node;
    }
    else
    {
     while(i--!==0)
     {
      curr_node = curr_node.next;
     }
    curr_node.prev.next = new_node;
    new_node.prev = curr_node.prev;
    new_node.next = curr_node;
    curr_node.prev = new_node;
    }
}}

  //Deletes an element at the specified index 

  deleteAt(index)
{ 
  if(index>this.size-1 || index<0) throw "invalid index";
  else{
   this.size--;
   let curr_node = this.head; let i = index;
  while(i!==0)
  {
      curr_node = curr_node.next;
      i--;
  }
  if(index===0)
   this.head = curr_node.next;

  curr_node.prev.next = curr_node.next;
  curr_node.next.prev = curr_node.prev;
}}

    //Prints elements with arrows to show where they point to, for easy visualization

    print()
    {   
        let curr_node = this.head;
        console.log(this.size);
        for(let i = 0; i<this.size; i++)
        {
            console.log(`${curr_node.prev.data} <== ${curr_node.data} ==> ${curr_node.next.data}`);
            curr_node = curr_node.next;
        }
    }
}

//Demo operations

let my_list = new doublyCircularLinkedlist();
my_list.insert(1);            //1
my_list.insert(2);            //12
my_list.insert(3);            //123
my_list.insertAt(0,0);        //0123
my_list.insertAt(4,3);        //01243
my_list.insert(6);            //012436
my_list.deleteAt(3);          //01236
my_list.print();

