/* 
 *Student Name: Nasheha Baset
 *University of Texas at Dallas
 *Course: CS 5343 002
 *Instructor: Dr. Neeraj Gupta
 *Assignment: 4
 *Date: November 2, 2019
 *Computer: Lenovo Ideapad 320 running Windows 10
 *IDE: Eclipse	and JGrasp for visualization of the tree	  
 */


//This first function, DIJKShortestPath, is essentially the dijkstra's algorithm to find the shortest path from the origin in a given matrix
class DIJKShortestPath { 
	private static int missPar = -1;  //initializing to -1
 	private static void dijkAlg(int[][] graph,int origin)
	{ 
		int currentVertice = graph[0].length; 
		int[] sPath = new int[currentVertice]; 
		boolean[] addWeight = new boolean[currentVertice]; 
		for (int index = 0; index < currentVertice; index++) 
		{ 
			sPath[index] = Integer.MAX_VALUE;	//MAX_VALUE is a constant that holds the maximum value. In this instance, it holds it for the path
			addWeight[index] = false; 
		} 
		sPath[origin] = 0; 
		int[] parents = new int[currentVertice]; 
		parents[origin] = missPar; 
		for (int i = 1; i < currentVertice; i++) 
		{ 
			int adjacentVertex = -1; 
			int sDist = Integer.MAX_VALUE; 
			for (int index = 0; index < currentVertice; index++) 
			{ 
				if (!addWeight[index] && 
					sPath[index] < sDist) 
				{ 
					adjacentVertex = index; 
					sDist = sPath[index]; 
				} 
			} 
			addWeight[adjacentVertex] = true; 			//Adds weight if true
			for (int index = 0; index < currentVertice; index++) 
			{ 
				int edgeWeight = graph[adjacentVertex][index]; 
				
				if (edgeWeight > 0 && ((sDist + edgeWeight) < sPath[index])) 
				{ 
					parents[index] = adjacentVertex; 
					sPath[index] = sDist + edgeWeight; 
				} 
			} 
		} 

		ShortestPath(origin, sPath, parents);  //This line calls the function to print out the origin and destination for the iteration with the path
	} 
 	
 	//Prints out the shortest path taken using the information from the origin, the distances, and the parents
   //Note: I was struggling with the output, and a GeeksforGeeks blog post helped give an idea of a good way to display the edges and vertices
	private static void ShortestPath(int origin, int[] distances, int[] parents) 
	{ 
		int currentVertice = distances.length; 
		System.out.print("Vertex from Origin (0) \t| Total Weight\t| Path Taken from the Origin to the Desitination"); 
		
		for (int index = 0; index < currentVertice; index++) 
		{ 
			if (index != origin) 
			{ 
				System.out.print("\n" + origin + " to "); 
				System.out.print(index + " \t\t\t| "); 
				System.out.print(distances[index] + "\t\t|"); 
				OriginToDestPath(index, parents);		// calls the function that prints path from origin to destination
			} 
		} 
	} 
	
	//Prints out the path from the origin to destination
   //Note: I was struggling with the output, and a GeeksforGeeks blog post assisted with giving me an idea of how to print this out
	private static void OriginToDestPath(int currentVertex, int[] parents) 
	{ 
		
		
		if (currentVertex == missPar) 
		{ 
			return; 
		} 
		OriginToDestPath(parents[currentVertex], parents); 
		System.out.print(currentVertex + " "); 
	} 
	
	
	
	//This is where you want to put in your matrix, as well as call dijkstra's Algorithm. Calling the function should have everything print automatically, since its all contained in the same function
	public static void main(String[] args) 
	{ 
		int[][] graph = { { 0, 1, 1, 0, 0, 0, 0, 0, 0, 1}, { 1, 0, 2, 2, 0, 0, 0, 0, 0, 2}, { 1, 2, 0, 3, 3, 0, 0, 0, 3, 0}, { 0, 2, 3, 0, 1, 1, 0, 0, 0, 0}, { 0, 0, 3, 1, 0, 2, 2, 0, 0, 0}, { 0, 0, 0, 1, 2, 0, 3, 3, 0, 0}, { 0, 0, 0, 0, 2, 3, 0, 1, 1, 0}, { 0, 0, 0, 0, 0, 3, 1, 0, 2, 1}, { 0, 0, 3, 0, 0, 0, 1, 2, 0, 3}, { 1, 2, 0, 0, 0, 0, 0, 1, 3, 0}};
		dijkAlg(graph, 0); 
	} 
} 

