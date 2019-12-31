/* 
 *Student Name: Nasheha Baset
 *University of Texas at Dallas
 *Course: CS 5343 002
 *Instructor: Dr. Neeraj Gupta
 *Assignment: 2
 *Date: September 25, 2019
 *Computer: Lenovo Ideapad 320 running Windows 10
 *IDE: JGrasp			  
 */

public class BinarySearchTree {

	Node root;

	public void addNode(int key, String data) { // adding new nodes to the binary tree
		Node newNode = new Node(key, data); // initializing the new node and passing over the key, which in my case is
											// the key
		if (root == null) { // if this is the root element of the tree...
			root = newNode; // then the new node becomes the root
		} else { // if this is not the root element of the tree, then we sent it currently as the
					// root as we set the parent and the child
			Node treeNode = root;
			Node parNode;
			while (true) {
				parNode = treeNode; // pNode is the parent node, which is currently the current node, which is the
									// root
				if (key < treeNode.key) { // if the key in the new node is less than the current node, then the
											// new node is the left child
					treeNode = treeNode.lChild;
					if (treeNode == null) { // if the left child doesn't have any children, then this will place the
											// new node to the left of it
						parNode.lChild = newNode;
						return;
					}
				}else {
					treeNode = treeNode.rChild; // if the key in the new node is greater than the current node,
												// then it becomes the right child
					if (treeNode == null) { // if the right child has no children, then the new node will be placed
											// to the right
						parNode.rChild = newNode;
						return;
					}
				}
			}
		}
	}

	/*
	 * There should be a more efficient way to do this than to repeat the loop over
	 * and over.
	 */

	public void inOrderTrav(Node treeNode) { // This should do an in order traversal through the tree
		if (treeNode != null) { // making sure that there is key in the node
			inOrderTrav(treeNode.lChild); // Traverses all the way to the left to read the smallest key point
			System.out.println(treeNode); // outputs the smallest key point
			inOrderTrav(treeNode.rChild); // Traverses to the next smallest key point which is the right child
		} // This should continue looping until all of the points are read
	}

	public boolean remove(int key) { // This should give a T/F if a key was able to be removed
		Node currentNode = root; // find the node in the code
		Node parNode = root; // we are starting at the top of the tree

		boolean mayberChild = true;
		while (currentNode.key != key) { // while the node that we are on is not the key, we want to keep looking
			parNode = currentNode;
			if (key < currentNode.key) { // look through the left if the key is less than the current node's key
				mayberChild = true;
				currentNode = currentNode.rChild;
			} else { // otherwise, it is a right child
				mayberChild = false;
				currentNode = currentNode.lChild;
			}
			if (currentNode == null)
				return false;
		}
		if (currentNode.rChild == null && currentNode.lChild == null) { // if the current node doesn't have children
																		// (left and right)
			if (currentNode == root) { // if the current node is the root
				root = null; // then just set the root to null
			} else if (mayberChild) {
				parNode.rChild = null; // deletes the node and it's parent of the left child
			} else {
				parNode.lChild = null; // same as the else if case, only for the right child
			}
		} 
		else if (currentNode.lChild == null) { // asking if the right child is equal to null
			if (currentNode == root)
				root = currentNode.rChild; // to move the root to the left child
			else if (mayberChild)
				parNode.rChild = currentNode.rChild;
			else
				parNode.lChild = currentNode.rChild;
		} 
		else if (currentNode.rChild == null) { // if there is no left child
			if (currentNode == root)
				root = currentNode.lChild;

			else if (mayberChild)
				parNode.rChild = currentNode.lChild;
			else
				parNode.lChild = currentNode.rChild;
		} 
		else { // Situation where there are two children involved
			Node replace = getReplaceNode(currentNode);
			if (currentNode == root)
				root = replace;
			else if (mayberChild)
				parNode.rChild = replace;
			else
				parNode.lChild = replace;
			replace.rChild = currentNode.rChild;
		}
		return true;
	}
	public Node getReplaceNode(Node newReplaceNode) {
		Node replaceParent = newReplaceNode;
		Node replace = newReplaceNode;
		Node currentNode = newReplaceNode.lChild;
		while (currentNode!=null) {
			replaceParent = replace;
			replace = currentNode;
			currentNode = currentNode.rChild;
		}
	
	
	if(replace != newReplaceNode.lChild){
		replaceParent.rChild = replace.lChild;
		replace.lChild = newReplaceNode.lChild;
	}
	return replace;
	}
};
