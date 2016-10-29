import java.io.*;
class Node{
	public int item;
	public Node next;
	public Node(int val){ 
		item = val; 
	}
	public void displayNode(){ 
		System.out.print("[" + item + "]"); 
	}
}
class LinkedList{
	private Node start;
	private Node end;
	public LinkedList(){
		start = null;
		end = null;
	}
	public boolean isEmpty(){ 
		return start==null; 
	}
	public void insertEnd(int val){//Insert node at the end of list
		Node newNode = new Node(val);
		if( isEmpty() )
			start = newNode;
		else
			end.next = newNode;
		end = newNode;
	}
	public int deleteStart(){//delete the node from the beginning of the list
		int temp = start.item;
		if(start.next == null)
			end = null;
		start = start.next;
		return temp;
	}
	public void displayList(){
		Node current = start;
		while(current != null)
		{
			current.displayNode();
			current = current.next;
		}
		System.out.println("");
	}
}
class Queue{
	private LinkedList listObj;
	public Queue(){
		listObj = new LinkedList(); 
	}
	public boolean isEmpty(){ 
		return listObj.isEmpty(); 
	}
	public void insert(int k){ 
		listObj.insertEnd(k); 
	}
	public int delete(){ 
		return listObj.deleteStart(); 
	}
	public void display(){
		System.out.print("Queue [start to end]: ");
		listObj.displayList();
	}
}
class ListQueueBlog{
	public static void main(String[] args){ 
		Queue demo = new Queue();
		System.out.println("Inserting two elements into the queue");
		demo.insert(10);
		demo.insert(20);
		demo.display();
		System.out.println("Inserting one more element into the queue at the end");
		demo.insert(30);
		demo.display();
		System.out.println("Deleting one element from the front");
		demo.delete();
		demo.display(); 
	} 
}
