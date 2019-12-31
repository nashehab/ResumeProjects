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

public class Main {

	public static void main(String[] args) {
		BinarySearchTree binTree = new BinarySearchTree();

		binTree.addNode(100, "first");
		binTree.addNode(50, "second");
		binTree.addNode(200, "third");
		binTree.addNode(150, "fourth");
		binTree.addNode(300, "fifth");
		binTree.addNode(25, "sixth");
		binTree.addNode(75, "seventh");
		binTree.addNode(12, "eighth");
		binTree.addNode(37, "ninth");
		binTree.addNode(125, "tenth");
		binTree.addNode(175, "eleventh");
		binTree.addNode(250, "twelveth");
		binTree.addNode(320, "thirteenth");
		binTree.addNode(67, "fourteenth");
		binTree.addNode(87, "fifteenth");
		binTree.addNode(94, "sixteenth");
		binTree.addNode(89, "seventeenth");
		binTree.addNode(92, "eighteenth");
		binTree.addNode(88, "nineteenth");

		binTree.inOrderTrav(binTree.root);
		
		System.out.println("Removal of 100");
		binTree.remove(100);
		
		binTree.inOrderTrav(binTree.root);
		
	}

};
