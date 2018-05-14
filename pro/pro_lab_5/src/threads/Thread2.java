
package threads;

import commonresource.CommonResource1;
import java.util.concurrent.Semaphore;

/**
 *
 * @author vlad
 */
public class Thread2 extends Thread{
    CommonResource1 CR;
    Semaphore sem1,sem2;
    public Thread2(CommonResource1 CR, Semaphore semInit1, Semaphore semInit2){
        super("Thread2");
        System.out.println("Thread2 started");
        this.CR = CR;
        sem1 = semInit1;
        sem2 = semInit2;
	start();
    }    
    
    @Override
    public void run(){
        
        sem1.release();
        System.out.println("Thread2 - release sem1 for Thread1");
        try {
            System.out.println("Thread2 - wait when Thread1 will open sem2");
            sem2.acquire();
        } catch (InterruptedException ex) {
           System.err.println(ex.getMessage());
        }
        
        System.out.println("Thread2 working after opening sem2");
        
       while(true){
            CR.produce();
       }
    }
}
