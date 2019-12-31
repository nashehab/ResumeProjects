//Name: Nasheha Baset
//Class: CS 5343.002
//Due Date: November 17, 2019
//Assignment: 5

import java.util.*;


public class TopSortDFS { // Here to detect how the data was inputed initially for the graph and save the
							// data for later use
	static class outeredges {
		int source, destination;

		public outeredges(int sour, int dest) {
			source = sour;
			destination = dest;
		}
	}
	

	// DepthFirstSearch Algorithm that goes in and sorts out the vertices based on
	// the connectivity
	private static int DepthFirstSearch(int n, int curr, boolean[] visited, int[] TopoOrder,
			Map<Integer, List<outeredges>> graph) {

		//To keep track if it has been visited during traversal
		visited[curr] = true;

		List<outeredges> outedges = graph.get(curr);
		//continue on with the search while listing the best topological order as its going through
		if (outedges != null)
			for (outeredges visitededge : outedges)
				if (!visited[visitededge.destination]) {
					n = DepthFirstSearch(n, visitededge.destination, visited, TopoOrder, graph);
				}
				// This statement will tell me is there is a cycle present, but it won't tell me
				// which vertices are involved (possible stack needed here)
				else {
	//				System.out.println("<" + graph.get(curr) + ", " + graph.get(curr) + ">");
					System.out.println("There is a cycle present that is created by the edge connecting the vertices "+ curr + " & " + visitededge.destination + ".");
				}
		TopoOrder[n] = curr;
		return n - 1;

	}

	//takes the information from DFS and implements topologial sort with an output order in the end.
	public static int[] topSort(Map<Integer, List<outeredges>> graph, int totalVert) {

		int[] TopoOrder = new int[totalVert];
		
		boolean[] visited = new boolean[totalVert];

		int n = totalVert - 1;
		
		for (int curr = 0; curr < totalVert; curr++)
			
			if (!visited[curr])
				n = DepthFirstSearch(n, curr, visited, TopoOrder, graph);

		return TopoOrder;

	}

	public static void main(String[] args) {

		final int N = 16; // Graph using an adjacency list (matrix was a little difficult to do)
		Map<Integer, List<outeredges>> g = new HashMap<>();
		
		for (int n = 0; n < N; n++)
			
			g.put(n, new ArrayList<>());
		
		g.get(0).add(new outeredges(0, 5));
		g.get(0).add(new outeredges(0, 6));
		g.get(1).add(new outeredges(1, 2));
		g.get(2).add(new outeredges(2, 8));
		g.get(3).add(new outeredges(3, 4));
		g.get(4).add(new outeredges(4, 9));
		g.get(6).add(new outeredges(6, 7));
		g.get(7).add(new outeredges(7, 1));
		g.get(8).add(new outeredges(8, 3));
		g.get(9).add(new outeredges(9, 10));
		g.get(10).add(new outeredges(10, 11));
		g.get(11).add(new outeredges(11, 12));
		g.get(11).add(new outeredges(11, 13));
		g.get(12).add(new outeredges(12, 14));
		g.get(12).add(new outeredges(12, 15));
		//g.get(9).add(new outeredges(9,8));
		
		//commenting the last line of this data above out will show you what an acyclic graph will output
		

		int[] TopoOrder = topSort(g, N);

		// Printout of Topological Order
		System.out.println(java.util.Arrays.toString(TopoOrder));
	}

}