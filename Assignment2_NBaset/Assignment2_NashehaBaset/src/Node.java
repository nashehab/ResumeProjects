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

public class Node {
	int key; // key contained in the node, technically the key
	String data;	//data contained within
	
	Node lChild; // left child node
	Node rChild; // right child node

	Node(int key, String data) {
		this.key = key;
		this.data = data;
	}

	public String toString() {		//double check this to see if there is another way to show this
		return key + " was the " + data + " item on the list.";
	}


};