
package threads;

import commonresource.CommonResource2;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.locks.ReentrantLock;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author vlad
 */
public class Thread3 extends Thread{
    private CommonResource2 cr2;
    private CyclicBarrier cb1,cb2;
    private ReentrantLock mutex;
        public Thread3(CommonResource2 cr2,CyclicBarrier cb1, CyclicBarrier cb2,ReentrantLock mutex){
        super("Thread3");
        System.out.println("Thread3 started");
        this.cr2 = cr2;
        this.cb1 = cb1;
        this.cb2 = cb2;
        this.mutex = mutex;
	start();
    }    
    
    @Override
    public void run(){
        int i = 9;
        while(true){
            System.out.println("Thread3 wait sync with Thread6 with CyclicBarrier_1");
            try {
                cb1.await();
            } catch (InterruptedException ex) {
                System.out.println(ex.getMessage());
            } catch (BrokenBarrierException ex) {
                System.out.println(ex.getMessage());
            }
            System.out.println("Thread3 work after sync with Thread6 with CyclicBarrier_1");
            
            System.out.println("Thread3 lock mutex and started working with CR2");
            
            mutex.lock();
            
            System.out.println("Thread3 modify CR2");
            
            cr2.val_1 = i;
            cr2.val_2 = 2*i;
            cr2.val_3 = i*i;
            cr2.val_4 = i*i*i;
            cr2.val_5 = (2*i)/(i*i);
            cr2.val_6 = (i*i)/(i*i*i);
            cr2.val_7 = true;
            cr2.val_8 = false;            
            
            mutex.unlock();
            
            System.out.println("Thread3 unlock mutex and finished working with CR2");
            
            System.out.println("Thread3 wait sync with Thread6 with CyclicBarrier_2");
            
            try {
                cb2.await();
            } catch (InterruptedException ex) {
                System.out.println(ex.getMessage());
            } catch (BrokenBarrierException ex) {
                System.out.println(ex.getMessage());
            }
            
            System.out.println("Thread3 work after sync with Thread6 with CyclicBarrier_2");
        }
    }
}
