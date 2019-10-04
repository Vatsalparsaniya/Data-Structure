class BinarySearchTree {
  constructor(value, leftSubTree = null, rightSubTree = null) {
    if (!value || typeof value !== 'number') {
      throw new Error('Type of data not supported');
    }

    /**
     * @type {number}
     */
    this.value = value;

    /**
     * @type {BinarySearchTree}
     */
    this.leftSubTree = leftSubTree;

    /**
     * @type {BinarySearchTree}
     */
    this.rightSubTree = rightSubTree;
  }

  insertNode(newValue) {
    if (typeof newValue === 'number') {
      if (newValue < this.value) {
        if (this.leftSubTree == null) {
          const newLeftSubTree = new BinarySearchTree(newValue);
          this.leftSubTree = newLeftSubTree;
        } else {
          this.leftSubTree.insertNode(newValue);
        }
      } else {
        if (this.rightSubTree == null) {
          const newRightSubTree = new BinarySearchTree(newValue);
          this.rightSubTree = newRightSubTree;
        } else {
          this.rightSubTree.insertNode(newValue);
        }
      }
    }
  }

  search(value) {
    let searched = false;
    if (value == this.value) {
      searched = true;
    } else {
      if (this.leftSubTree != null) {
        searched = this.leftSubTree.search(value);
      } else if (this.rightSubTree != null) {
        searched = this.rightSubTree.search(value);
      }
    }
    return searched;
  }

  findMin() {
    let minValue = this.value;
    if (this.leftSubTree != null) {
      minValue = this.leftSubTree.findMin();
    }

    return minValue;
  }

  findMax() {
    let maxValue = this.value;
    if (this.rightSubTree != null) {
      maxValue = this.rightSubTree.findMax();
    }
    return maxValue;
  }

  preorder() {
    console.log(this.value);
    if (this.leftSubTree != null) {
      this.leftSubTree.preorder();
    }
    if (this.rightSubTree != null) {
      this.rightSubTree.preorder();
    }
  }

  inorder() {
    if (this.leftSubTree != null) {
      this.leftSubTree.inorder();
    }
    console.log(this.value);
    if (this.rightSubTree != null) {
      this.rightSubTree.inorder();
    }
  }

  postorder() {
    if (this.leftSubTree != null) {
      this.leftSubTree.postorder();
    }
    if (this.rightSubTree != null) {
      this.rightSubTree.postorder();
    }
    console.log(this.value);
  }
}
