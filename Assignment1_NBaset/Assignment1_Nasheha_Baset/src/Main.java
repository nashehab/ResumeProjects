
/* 
 *Student Name: Nasheha Baset
 *University of Texas at Dallas
 *Course: CS 5343 002
 *Instructor: Dr. Neeraj Gupta
 *Assignment: 1
 *Date: September 7, 2019
 *Computer: Lenovo Ideapad 320 running Windows 10
 *IDE: Eclipse Java 2018-12
 * 			  
 */

public class Main {

	public static void main(String[] args) {

		// FUTURE ME: create a more effiencent way to generate the numbers
		int rand_int1 = (int) (Math.random() * 99 + 1); // generates random integers between 1 and 99
		int rand_int2 = (int) (Math.random() * 99 + 1); // must repeat (by copying and pasting) 15 times, otherwise the same number keeps
														// printing
		int rand_int3 = (int) (Math.random() * 99 + 1);
		int rand_int4 = (int) (Math.random() * 99 + 1);
		int rand_int5 = (int) (Math.random() * 99 + 1);
		int rand_int6 = (int) (Math.random() * 99 + 1);
		int rand_int7 = (int) (Math.random() * 99 + 1);
		int rand_int8 = (int) (Math.random() * 99 + 1);
		int rand_int9 = (int) (Math.random() * 99 + 1);
		int rand_int10 = (int) (Math.random() * 99 + 1);
		int rand_int11 = (int) (Math.random() * 99 + 1);
		int rand_int12 = (int) (Math.random() * 99 + 1);
		int rand_int13 = (int) (Math.random() * 99 + 1);
		int rand_int14 = (int) (Math.random() * 99 + 1);
		int rand_int15 = (int) (Math.random() * 99 + 1);

		// FUTURE ME: make this more efficient instead of doing it one at a time
		LinkedList list = new LinkedList();
		list.insert(rand_int1);
		list.insert(rand_int2);
		list.insert(rand_int3);
		list.insert(rand_int4);
		list.insert(rand_int5);
		list.insert(rand_int6);
		list.insert(rand_int7);
		list.insert(rand_int8);
		list.insert(rand_int9);
		list.insert(rand_int10);
		list.insert(rand_int11);
		list.insert(rand_int12);
		list.insert(rand_int13);
		list.insert(rand_int14);
		list.insert(rand_int15);

		// Displays the values that are in each node
		System.out.println("Random integers presented in the list, UNSORTED:");
		list.show(); 												// shows the random list before sorting

		System.out.println(""); 									// Empty line to separate the lists

		System.out.println("Random integers presented in the list, SORTED in ascending order:");
		list.sort(); 												// sorts the random list from smallest to largest
		list.show(); 												// shows the new random sorted list
	}

}



