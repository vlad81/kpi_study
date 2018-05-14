
package threads;

import commonresource.CommonResource2;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.locks.ReentrantLock;

/**
 *
 * @author vlad
 */
public class Thread6 extends Thread{
    private CyclicBarrier cb1,cb2;
    private CommonResource2 cr2;
    private ReentrantLock mutex;
    public Thread6(CommonResource2 cr2, CyclicBarrier cb1, CyclicBarrier cb2, ReentrantLock mutex){
        super("Thread6");
        System.out.println("Thread6 started");
        this.cr2 = cr2;
        this.cb1 = cb1;
        this.cb2 = cb2;
        this.mutex = mutex;
	start();
    }    
    
    @Override
    public void run(){
        while(true){
            System.out.println("Thread6 wait sync with Thread3 with CyclicBarrier_1");
            try {
                cb1.await();
            } catch (InterruptedException ex) {
                System.out.println(ex.getMessage());
            } catch (BrokenBarrierException ex) {
                System.out.println(ex.getMessage());
            }
             System.out.println("Thread6 work after sync with Thread3 with CyclicBarrier_1");

             System.out.println("Thread6 wait sync with Thread3 with CyclicBarrier_2");
            try {
                cb2.await();
            } catch (InterruptedException ex) {
                System.out.println(ex.getMessage());
            } catch (BrokenBarrierException ex) {
                System.out.println(ex.getMessage());
            }
            System.out.println("Thread6 work after sync with Thread3 with CyclicBarrier_2");
            
            System.out.println("Thread6 lock mutex and start to use with CR2");
            mutex.lock();
                System.out.println("val1 = " + cr2.val_1 + "\n" + 
                                    "val2 = " + cr2.val_2 + "\n" +
                                    "val3 = " + cr2.val_3 + "\n" +
                                    "val4 = " + cr2.val_4 + "\n" +
                                     "val5 = " + cr2.val_5 + "\n" +
                                     "val6 = " + cr2.val_6 + "\n" +
                                     "val7 = " + cr2.val_7 + "\n" +
                                      "val8 = " + cr2.val_8);
            mutex.unlock();
            System.out.println("Thread6 lock mutex and start to use with CR2");
        }
        
    }
}
