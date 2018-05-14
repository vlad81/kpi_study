package threads;

import commonresource.CommonResource1;
import java.util.concurrent.Semaphore;

/**
 *
 * @author vlad
 */
public class Thread1 extends Thread{
    
    CommonResource1 CR;
    Semaphore sem1,sem2;
    
    public Thread1(CommonResource1 CR, Semaphore semInit1, Semaphore semInit2){
        super("Thread1");
        System.out.println("Thread1 started");
        this.CR = CR;
        sem1 = semInit1;
        sem2 = semInit2;
	start();      
    }    
    
    @Override
    public void run(){
        while(true){
            sem2.release();
            System.out.println("Thread1 - release sem2 for Thread2");
            try {
                System.out.println("Thread1 - wait when Thread2 will open sem1");
                sem1.acquire();
            } catch (InterruptedException ex) {
               System.err.println(ex.getMessage());
            }
            System.out.println("Thread1 working after opening sem1");
            
            CR.produce();
        }
    }
}
