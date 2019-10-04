/**
 * Implementation of stack with an array
 */

class Stack {
  constructor() {
    this.stack = [];
  }
  
  // Insert an element on top of the stack
  push(element) {
    this.stack.push(element);
  }
  
  //Removes the element at the top of the stack and returns that same element
  pop() {
    if (this.isEmpty()) 
    return 'Stack is empty!';
    return this.stack.pop();
  }
  
  // Returns the element that is on top of the stack
  peek() {
    if (this.isEmpty()) 
    return 'Stack is empty';
    return this.stack[this.stack.length - 1];
  }
  
  // helper method
  isEmpty() {
    return !this.stack.length;
  }
}