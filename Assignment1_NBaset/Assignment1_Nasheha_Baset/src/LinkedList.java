public class LinkedList {

	private Node head;

	// Constructor
	// Traversing and inserting data into each node
	public void insert(int data) {
		Node node = new Node();
		node.data = data;

		if (head == null) {
			head = node;
		} else {
			Node n = head;
			while (n.next != null) {
				n = n.next;

			}
			n.next = node;
		}
	}

	// Traversing and showing function to show what is in each node
	public void show() {
		Node node = head;

		while (node.next != null) {
			System.out.println(node.data);
			node = node.next;
		}

		// Won't print the last element outside the loop because it is null, therefore
		// it needs to be manually printed.
		System.out.println(node.data);

	}

//Function to sort the list of random integers.
	public Node sort() {
		// Node node = head;
		Node x1 = head;
		Node prevx1 = null;
		Node x2 = head;
		Node min = null;
		Node prevmin = null;
		Node temp = null;

		if (x1 == null) {
			System.out.print("List is empty"); // If there is nothing in the linked list (base case)
			return head;
		} else if (x1.next == null) {
			System.out.print("List contains only one node"); // If there is only one node in the linked list (another base case)
			return head;
		}

		while (x1 != null) {
			min = x1;
			x2 = x1;

			while (x2.next != null) {
				if (x2.next.data < min.data) {
					min = x2.next;
					prevmin = x2;
				}

				x2 = x2.next;
			}

			temp = min.next;

			if (x1 == min) {

			} else if (x1 == head) {
				head = min;
				prevmin.next = x1;
				min.next = x1.next;
				x1.next = temp;
			} else {
				prevx1.next = min;
				prevmin.next = x1;
				min.next = x1.next;
				x1.next = temp;
			}

			prevx1 = min;
			x1 = min.next;
		}

		return head;
	}
}



