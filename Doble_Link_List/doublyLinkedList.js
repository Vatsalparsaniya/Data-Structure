class Node{
    constructor(val){
        this.val = val;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedList{
    constructor(){
        this.head = null;
        this.tail = null;
        this.length = 0;
    }

    //function push;
    push(val){
        var newNode = new Node(val);
        if(!this.head){
            this.head = newNode;
            this.tail = this.head;
        }else{
        var temp = this.tail;
        temp.next = newNode;
        newNode.prev = temp;
        this.tail = newNode;
        }
        this.length++;
        return this;

    }
    //function 2 pop();

    pop(){
        if(!this.head) return undefined;
        var temp = this.tail;
        if(this.length === 1){
            this.head = null;
            this.tail = null;
        }else {
            this.tail = temp.prev;
            this.tail = null;

        }
        this.length--;
        return temp.val;
    }

    //function 3 shift();
    shift(){
        if(this.length === 0) return undefined;
        var temp = this.head;
        if(this.length === 1) {
            this.head = null;
            this.tail = null;
        }
        else{
           
            this.head = temp.next;
        //temp.next = null;
            this.head.prev = null;
            temp.next = null;
        }
        this.length--;
        return temp.val;
    }

    //function 4 unshift();
    unshift(val){
        var newNode = new Node(val);
        if(this.length === 0){
            this.head = newNode;
            this.tail = this.head;
        }else{
            var current = this.head;
            this.head = newNode;
            newNode.next = current;
            current.prev = newNode;
        }
        this.length++;
        return this;
         
    }

    //function 5 get();
    get(index){
        if(index < 0 || index >= this.length) return undefined;
        
        let half = this.length /2;
        if(index >= half){
            //start from last;
            let current = this.tail;
            var limit = (this.length - index) + 1;
            for(let i = 0; i < limit;i++){
                current = current.prev;
            }
            return current;
        }
        else{
            //start from first
            let current = this.head;
            for(let i = 0;i < index;i++){
                current = current.next;
            }
            return current;
        }
        

    }
    //functino 6 set();
    set(index,value){
        var current = this.get(index);
        if(current != null){ //very import to check if it is null;
            current.val = value;
            return true;
        }
        else{
            return false;
        }
        
    }

    //functino 7 insert();
    insert(index,value){ //return only true or false;
         if(index < 0 || index > this.length) return false;
         if(index === 0) return !!this.unshift(value);
         if(index === this.length) return !!this.push(value);
         var newNode = new Node(value);
         var previousNode = this.get(index - 1);
         var nextNode = this.get(index);
        previousNode.next = newNode;
        newNode.prev   = previousNode;

        newNode.next = nextNode;
        nextNode.prev = newNode;
        return true;
    }
    //function 8 remove();
    remove(index){
        if(index < 0 || index > this.length) return false;
        if(index === 0) return this.shift();
        if(index === this.length -1) return this.pop();
        var currentNode = this.get(index);
        var previousNode = currentNode.prev;
        var nextNode = currentNode.next;
        previousNode.next = nextNode;
        nextNode.prev = previousNode;
        currentNode.next = null;
        currentNode.prev = null;
        this.length--;
        return currentNode;
    }
}


//tested in chrome dev tools
//var list = new DoublyLinkedList();
//  console.log(list.push(10));
//  console.log(list.push(20));
// // console.log(list.push(50));
// console.log(list.length);
// // console.log(list.pop());
// // console.log(list.shift());
// // console.log(list.shift());
// console.log(list.length);
// console.log(list.unshift(50));
// console.log(list.get(0));
// console.log(list.set(0,100));
// console.log(list.insert(1,"Hello"));
// console.log(list.remove(list.length - 1));
// console.log(list);
// console.log(list.length);