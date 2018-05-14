
package commonresource;

import stack.Stack;

/**
 *
 * @author vlad
 */
public class CommonResource1 {
    public static final int maxSize = 100;
    public static final int minSize = 0;
    Stack stack = new Stack(maxSize, minSize); 
    int ind = 0;
    boolean IsEmpty = ind  == minSize;
    boolean IsFull = ind == maxSize;
    	
    synchronized public void consume()
    {
        while (IsEmpty){
            try
            {	wait(); 
            }
            catch (InterruptedException e)
            {	
                
                System.err.println("InterruptedException" + e.getMessage());
            }
        }
        
        try{
            System.out.println("Element : " + stack.pop() + " - was consumed");
            ind--;
        }
        catch(Stack.EmptyStackException e){
            System.err.println(" " + e.getMessage());
        }
        
        IsEmpty = ind == minSize;
	IsFull = false;

        notify();
    }
	
	synchronized public void produce ()
	{
            while (IsFull){
                try
                {
                    wait();
                    
                }
                catch (InterruptedException e)
                {	System.out.println("InterruptedException");
                }
            }
            stack.push(ind);
            System.out.println("Element : " + ind +" - was produced");
            //System.out.println(" size = " + stack.getSize());
            ind++;
            IsFull = ind == maxSize;
            IsEmpty = false;
            notify();
	}
}
