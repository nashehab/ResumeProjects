/* 
 *Student Name: Nasheha Baset
 *University of Texas at Dallas
 *Course: CS 5343 002
 *Instructor: Dr. Neeraj Gupta
 *Assignment: 3
 *Date: October 19, 2019
 *Computer: Lenovo Ideapad 320 running Windows 10
 *IDE: Eclipse		  
 */






import java.util.Arrays;

public class MinHeap {
	
	static int[] makeheap(int RandomArray[]) {
		int heap[] = new int[RandomArray.length]; 
		heap [0] = 0; 
		for (int index = 1; index < RandomArray.length; index++) {
			int heapIndex = heap[0] + 1;
			heap[heapIndex] = RandomArray[index];
			heap[0] = heap[0]+1;
			percolateUp(heap, heap[0]);
		}
		
		return heap;
	}
	
	static void percolateUp(int heap[], int index) {
		int parent = index/2; 
		if (parent>0) {
		if (heap[index]>heap[parent]) {
			int temp = heap[parent];
			heap[parent] = heap[index];
			heap[index] = temp;
			percolateUp(heap, parent);
		}
		
		}
	}
	static void heapify(int RandomArray[], int size, int index) 
	{ 
		int parent = index; // This will make the largest number the root, and work from there as to which will be the right and the left
		int leftChild = 2 * index;
		int rightChild = 2 * index + 1;
		

		if(RandomArray[0] >= leftChild) { //compares it to array zero
			int max = leftChild;
			if (RandomArray[0] >= rightChild) {
				if(RandomArray[leftChild] < RandomArray[rightChild]) {
					max = rightChild;
				}
				
			}
			if (RandomArray[max] > RandomArray[parent]) {
				int temp2 = RandomArray[parent];
				RandomArray[parent] = RandomArray[max];
				RandomArray[max] = temp2;
				heapify (RandomArray, size, max);
			}
			
		}
		
	 
	} 
	 
	static void heapSort(int RandomArray[], int size)  //Heap sort function
	{ 
		int temp3 = 0;
		while (RandomArray[0] > 0) {
			
			temp3 = RandomArray[1]; //Swaps the root with the last value
			RandomArray[1] = RandomArray[RandomArray[0]];
			RandomArray[RandomArray[0]] = temp3;
			
			RandomArray[0] = RandomArray[0]-1; //decreasing the size of the array (deletes the last node after its replaced)
			
			heapify(RandomArray, size, 1);
			

		}
		
	
	} 


	static void printArray(int RandomArray[], int size) //prints the array
	{ 
		for (int index = 0; index < RandomArray.length; ++index) 
			System.out.print(RandomArray[index] + " "); 
		System.out.println(); 
	} 


	public static void main(String[] args) 
	{ 

		// Need to figure out a more efficient way to do this
		int rand_int1 = (int) (Math.random() * 99 + 1); // generates random integers between 1 and 99
		int rand_int2 = (int) (Math.random() * 99 + 1); // had to repeat it 20 times, otherwise the same number keeps
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
		int rand_int16 = (int) (Math.random() * 99 + 1);
		int rand_int17 = (int) (Math.random() * 99 + 1);
		int rand_int18 = (int) (Math.random() * 99 + 1);
		int rand_int19 = (int) (Math.random() * 99 + 1);
		int rand_int20 = (int) (Math.random() * 99 + 1);

		// This needs to be more efficient too

	

		int RandomArray[] = new int[21];
		RandomArray[0] = RandomArray.length-1; // figure out how to make this the index every time

		RandomArray[1] = rand_int1;
		RandomArray[2] = rand_int2;
		RandomArray[3] = rand_int3;
		RandomArray[4] = rand_int4;
		RandomArray[5] = rand_int5;
		RandomArray[6] = rand_int6;
		RandomArray[7] = rand_int7;
		RandomArray[8] = rand_int8;
		RandomArray[9] = rand_int9;
		RandomArray[10] = rand_int10;
		RandomArray[11] = rand_int11;
		RandomArray[12] = rand_int12;
		RandomArray[13] = rand_int13;
		RandomArray[14] = rand_int14;
		RandomArray[15] = rand_int15; 
		RandomArray[16] = rand_int16;
		RandomArray[17] = rand_int17;
		RandomArray[18] = rand_int18;
		RandomArray[19] = rand_int19;
		RandomArray[20] = rand_int20;
		
		System.out.println("The initial array is ");
		System.out.println(Arrays.toString(RandomArray)); //This will print out the raw array (unsorted, unheaped)
		int size = RandomArray.length;  //This is needed to print and run the rest properly
		//int index = size / 2 - 1;
	
		System.out.println("The initial heap is ");
		int heap[] = makeheap(RandomArray);
		printArray(heap, size);
		
		heapSort(heap, size); 

		System.out.println("The sorted array is "); 
		printArray(heap, size);
	} 
} 




