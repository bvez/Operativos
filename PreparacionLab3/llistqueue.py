#   Data Structures and Algorithms Using Python
#
#   Rance D. Necaise
#   Wiley, 2011
#
#   8.2   Implementing the Queue
#   8.2.3 Using a Linked List
#
#   vk, 2014
#   ab, 2018 

# Implementation of the Queue ADT using a linked list.
# Contiene método excahnge Tarea 3 Colas Horario 0583 (2018-1)

class Queue:
    # Creates an empty queue.
    def __init__(self):
        self._qhead = None
        self._qtail = None
        self._count = 0

    # Returns True if the queue is empty or False otherwise.
    def isEmpty(self):
        return self._qhead is None

    # Returns the number of items in the queue.
    def __len__(self):
        return self._count

    # Adds the given item to the queue.
    def enqueue(self, pid, burst,turnaround=0):
        node = _QueueNode(pid, burst,turnaround)
        if self.isEmpty():
            self._qhead = node
        else:
            self._qtail.next = node

        self._qtail = node
        self._count += 1

    def enqueueSJF(self,pid,burst,turnaround=0):
        node = _QueueNode(pid,burst,turnaround)
        if self.isEmpty():
            self._qhead = node
        else:
            ptr = self._qhead
            ptrPrev = None
            while (ptr is not None) and (ptr.burst <= node.burst):
                ptrPrev = ptr
                ptr = ptr.next
            
            ptr = ptrPrev
                
            if ptr is None:
                node.next = self._qhead
                self._qhead = node
            else:
                node.next = ptr.next
                ptr.next = node

    def enqueuePriority(self,priority,pid,burst,turnaround=0):
        node = _QueuePriorityNode(priority,pid,burst,turnaround)
        if self.isEmpty():
            self._qhead = node
        else:
            ptr = self._qhead
            ptrPrev = None
            while (ptr is not None) and (ptr.priority >= node.priority):
                ptrPrev = ptr
                ptr = ptr.next

            ptr = ptrPrev

            if ptr is None:
                node.next = self._qhead
                self._qhead = node
            else:
                node.next = ptr.next
                ptr.next = node
	
    # Removes and returns the first item in the queue.
    def dequeue(self):
        assert not self.isEmpty(), "Cannot dequeue from an empty queue."
        node = self._qhead
        if self._qhead is self._qtail:
            self._qtail = None
        self._qhead = self._qhead.next
        self._count -= 1
        return node.pid

            
    def printQueue(self):        
        t = self._qhead
        while t is not None:
            print(t.pid,end=" ")
            t = t.next
        print("")
    
    def printStatistics(self):
        t = self._qhead
        tp = 0
        while t is not None:
            tp += t.turnaround
            print("Pid del proceso:",t.pid,"Tiempo de retorno:",t.turnaround)
            t = t.next        
        print("Tiempo promedio de retorno:",tp/self._count)
       
        
    def schedulingRR(self, quantum):
        q = Queue()
        t = 0
        ptr = self._qhead
        while True:            
            if ptr is None:
                break
            else:
                if ptr.burst <= quantum:
                    t += ptr.burst
                    ptr.turnaround = t 
                    ptr.burst = 0
                    q.enqueue(ptr.pid, ptr.burst, ptr.turnaround)
                    self.dequeue()
                else:
                    t += quantum
                    ptr.burst -= quantum                    
                    self.enqueue(ptr.pid, ptr.burst, ptr.turnaround)
                    self.dequeue()
            ptr = ptr.next        
        q.printStatistics()    

    def schedulingFCFS(self):
        q = Queue()
        t = 0
        ptr = self._qhead
        while ptr is not None:
            t += ptr.burst
            ptr.turnaround = t 
            ptr.burst = 0
            q.enqueue(ptr.pid, ptr.burst, ptr.turnaround)
            self.dequeue()
            ptr = ptr.next
        q.printStatistics()    
	
    def schedulingSJF(self):
        q = Queue()
        t = 0
        ptr = self._qhead
        while ptr is not None:
            t+=ptr.burst
            ptr.turnaround = t
            ptr.burst = 0
            q.enqueue(ptr.pid,ptr.burst,ptr.turnaround)
            self.dequeue()
            ptr = ptr.next
        q.printStatistics()

    def schedulingPriority(self):
        q = Queue()
        t = 0
        ptr = self._qhead
        while ptr is not None:
            t += ptr.burst
            ptr.turnaround = t
            ptr.burst = 0
            q.enqueue(ptr.pid,ptr.burst,ptr.turnaround)
            self.dequeue()
            ptr = ptr.next
        q.printStatistics()

    def __iter__(self):
        return QueueIterator(self._qhead) 


class QueueIterator:
    def __init__(self, head):
        self.curNode = head

    def __iter__(self):
        return self
    
    def __next__(self):
        if self.curNode is None:
            raise StopIteration
        else:
            item = self.curNode.item
            self.curNode = self.curNode.next
            return item
        
# The private storage class for creating the linked list nodes.
class _QueueNode(object):
    def __init__(self, pid, burst = 0, turnaround=0):
        self.pid = pid
        self.burst = burst
        self.turnaround = turnaround
        self.next = None
        
class _QueuePriorityNode:
    def __init__(self,priority,pid,burst=0,turnaround=0):
        self.priority = priority
        self.pid = pid
        self.burst=burst
        self.turnaround = turnaround
        self.next = None

def main():
    q = Queue()
   
    """q.enqueue(1,3)
    q.enqueue(2,6)
    q.enqueue(3,4)
    q.enqueue(4,5)
    q.enqueue(5,2)"""
	
    
    #q.schedulingRR(4) 
    #q.schedulingFCFS()
    
    """
    assert q.isEmpty(), "---> isEmpty error"
    try:
        q.dequeue()
    except AssertionError:
        pass

    q.enqueue(1)
    assert not q.isEmpty(), "---> isEmpty error"
    q.enqueue(2)
    q.enqueue(2)
    assert len(q) == 3, "---> __len__ error"
    q.enqueue(3)
    assert q.dequeue() == 1, "---> dequeue error"

    print('All tests are ok')
    """
	
    """q.enqueueSJF(1,3)
    q.enqueueSJF(2,6)
    q.enqueueSJF(3,4)
    q.enqueueSJF(4,5)
    q.enqueueSJF(5,2)
    #q.enqueueSJF(6,4)
    #q.enqueueSJF(7,4)
    
    q.schedulingSJF()"""

    q.enqueuePriority(2,1,3)
    q.enqueuePriority(4,2,6)
    q.enqueuePriority(1,3,4)
    q.enqueuePriority(5,4,5)
    q.enqueuePriority(3,5,2)

    q.schedulingPriority()
	
if __name__ == "__main__":
    main()
		
	
