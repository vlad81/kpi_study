package stack;

import java.lang.Throwable;
/**
 *
 * @author vlad
 */
public class Stack {
    private int size;
    private final int maxSize;
    private final int minSize;
    private Node head;
    public Stack(int maxSize, int minSize){
        head = null;
        size = 0;
        this.maxSize = maxSize;
        this.minSize = minSize;
    }
    
    public int getSize(){
        return size;
    }
    
    public void push(int el){
        if(size < maxSize){
            if(head == null){
                head = new Node(el);
                size++;
            }
            else{
                Node node = new Node(el);
                node.setNext(head);
                head = node;
                size++;
            }
        }
        return;
    }
    
    public int pop() throws EmptyStackException{
        if(size > minSize){
            Node node = head;
            if(size > 1)
                head = head.getNext();
            else
                head = null;           
            size--;
            return node.getElem();         
        }
        else{
            throw new EmptyStackException("Stack is empty exception");
        }
    }
    
    
    private class Node{
        private final int el;
        private Node next;
        public Node(int el){
            this.el = el;
            next = null;
        }
        
        public void setNext(Node next){
            this.next = next;
        }
        
        public Node getNext(){
            return next;
        }
        
        public int getElem(){
            return el;
        }
               
    }
    
    public class EmptyStackException extends Exception{
       EmptyStackException(String mes){
           super(mes);
       }
    }
    
}
