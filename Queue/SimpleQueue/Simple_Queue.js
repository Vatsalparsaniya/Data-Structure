class Queue {
    constructor() {
      this.queue = [];
    }
  
    add(element) {
      this.queue.push(element);
    }
  
    remove() {
      if (this.isEmpty()) {
        return 'Empty Queue';
      }
      return this.queue.shift();
    }
  
    peek() {
      if (this.isEmpty()) {
        return 'Empty Queue';
      }
  
      return this.queue[0];
    }
  
    isEmpty() {
      return this.queue.length === 0;
    }
  }
  