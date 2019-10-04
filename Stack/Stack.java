
public class Stack {

	int stackSize;
	int arr[];
	int top;

	Stack(int stackSize) {
		this.stackSize = stackSize;
		this.arr = new int[stackSize];
		this.top = -1;
	}

	public void push(int ele) {
		if (!isFull()) {
			top++;
			arr[top] = ele;
			System.out.println("Pushing :" + ele);
		} else {
			System.out.println("Stack is full.");
		}
	}

	public int pop() {
		if (!isEmpty()) {
			int returnedTop = top;
			top--;
			System.out.println("Popping :" + arr[returnedTop]);
			return arr[returnedTop];

		} else {
			System.out.println("Stack is empty !");
			return -1;
		}
	}

	public int peek() {
		if (!this.isEmpty())
			return arr[top];
		else {
			System.out.println("Stack is Empty");
			return -1;
		}
	}

	public boolean isEmpty() {
		return (top == -1);
	}

	public boolean isFull() {
		return (stackSize - 1 == top);
	}

	public static void main(String[] args) {
		Stack StackObj = new Stack(10);
		StackObj.pop();
		System.out.println("Started pushing...");
		StackObj.push(1);
		StackObj.push(20);
		StackObj.push(9);
		StackObj.push(14);
		System.out.println("Started poping...");
		StackObj.pop();
		StackObj.pop();
		StackObj.pop();
	}
}
