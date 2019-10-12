
// creating object for queue class 
var queue = new Queue(); 
              
  
// Testing dequeue and pop on an empty queue 
// returns Underflow 
console.log(queue.dequeue()); 
  
// returns true 
console.log(queue.isEmpty()); 
  
// Adding elements to the queue 
// queue contains [10, 20, 30, 40, 50] 
queue.enqueue(10); 
queue.enqueue(20); 
queue.enqueue(30); 
queue.enqueue(40); 
queue.enqueue(50); 
queue.enqueue(60); 
  
// returns 10 
console.log(queue.front()); 
  
// removes 10 from the queue 
// queue contains [20, 30, 40, 50, 60] 
console.log(queue.dequeue()); 
  
// returns 20 
console.log(queue.front()); 
  
// removes 20 
// queue contains [30, 40, 50, 60] 
console.log(queue.dequeue()); 
  
// printing the elements of the queue 
// prints [30, 40, 50, 60] 
console.log(queue.printQueue()); 
