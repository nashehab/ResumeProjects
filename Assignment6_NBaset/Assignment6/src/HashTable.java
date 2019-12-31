//Name: Nasheha Baset
//Class: CS 5343.002
//Due Date: December 1, 2019
//Assignment: 6

import java.util.*;
import java.io.File;			//Read online that this is needed to open a text file
import java.io.FileNotFoundException;	//Also part of opening a text file
import java.io.FileReader;		//Also needed to open a text file
import java.io.BufferedReader;	//According to GeeksforGeeks, this is the best option to read a file
import java.io.IOException;		//It forced me to throw an exception due to an out of bounds issue
import java.io.InputStreamReader;

public class HashTable {		// Creating the initial Hash Table that is needed
	private String[] hashTable;
	private int col;			//Initializing variables that shouldn't be changed outside of this function
	private int load;
	public HashTable() {
		hashTable = new String[50];
		for (int i = 0; i < 50; i++)
			hashTable[i] = null;
		col = 0;
		load = 0;
	}
	public HashTable(int n) {		// creating the actual hash table
		hashTable = new String[n];
		for (int i = 0; i < n; i++)
			hashTable[i] = null;
		col = 0;
		load = 0;
	}
	public void load(File file) throws IOException {   //for some reason, eclipse forced me to add the "throws IOException" or it wouldn't run
		BufferedReader buffread = new BufferedReader(new FileReader(file));	//GeeksforGeeks suggested using BufferedReader
		String newWord;
		while ((newWord = buffread.readLine()) != null)
			add(newWord);
		buffread.close();		//closing the buffered reader after the file is read
	}
	public void add(String newWord) {
		if (load + 1 >= hashTable.length)
			newHashTable();
		int Key = newWord.hashCode() % hashTable.length;
		int probing = 1;
		while (true) {
			if (hashTable[Key] == null) {
				hashTable[Key] = newWord;
				load++;
				break;
			}
			col++;
			Key += (probing * probing); 					// quadratic probing
			probing++;
			Key = Key % hashTable.length;
		}
	}
	private void newHashTable() {								// If the load is above .5, a new table is created, and the load and collisions are reset to 0
		System.out.println("Increasing table size to " + hashTable.length * 2);
		String[] newTable = hashTable;
		col = 0;
		load = 0;
		hashTable = new String[hashTable.length * 2 + 1];		// Not sure how to rehash to a table of a prime without using buckets
		for (int i = 0; i < newTable.length; i++)
			if (newTable[i] != null)
				add(newTable[i]);
	}
	boolean search(String newWord) {
		int Key = newWord.hashCode() % hashTable.length;
		int probing = 1;
		while (true) {
			if (hashTable[Key] == null) {
				return false;
			}
			else if (hashTable[Key].equalsIgnoreCase(newWord)) {
				return true;
			}
			Key += (probing * probing); 				// linear probing
			probing++;
			Key = Key % hashTable.length;
			if (Key == newWord.hashCode() % hashTable.length || probing == hashTable.length)
				return false;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader buffread = new BufferedReader(new InputStreamReader(System.in));
		HashTable hash = new HashTable(53);										//Initial hash table with 53 places to input
		hash.load(new File("Homework6Words.txt"));	//loads the file and hashes
		String newWord;
		while (true) {								// Interactive search for the word in the library
			System.out.println("What word would you like to search:");		
			newWord = buffread.readLine();
			if (hash.search(newWord))
				System.out.println("Word Found");
			else
				System.out.println("Word Not Found");
		}
	}

}