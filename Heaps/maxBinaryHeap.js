class MaxBinaryHeap{
    constructor(){
        this.values = [];
      
    }

    //function bubbleUp();
    bubbleUp(){
        var index = this.values.length -1;
        while(index > 0){
            var itsParent = Math.floor((index - 1) / 2);
            if(this.values[itsParent] >= this.values[index]) break;
            var temp = this.values[index];
            this.values[index] = this.values[itsParent];
            this.values[itsParent] = temp;
            index = itsParent;
            
        }
    }
    //insert function;
    insert(val){
        this.values.push(val);
        this.bubbleUp();
        return this.values;
    }
    
}

//Test
// var heap = new MaxBinaryHeap();
// console.log(heap.insert(100));
// console.log(heap.insert(80));
// console.log(heap.insert(120));
// console.log(heap.insert(101));
// console.log(heap.insert(100));
// console.log(heap.insert(80));
// console.log(heap.insert(120));
// console.log(heap.insert(1000));