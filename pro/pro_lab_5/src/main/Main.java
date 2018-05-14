package main;

import commonresource.*;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.ReentrantLock;
import threads.*;

/**
 *
 * @author vlad
 */
public class Main {

    public static void main(String[] args) {
        Semaphore sem1 = new Semaphore(0, true);
        Semaphore sem2 = new Semaphore(0, true);
        
        ReentrantLock mutex = new ReentrantLock();
        
        CommonResource1 CR1 = new CommonResource1();
        CommonResource2 CR2 = new CommonResource2();
        //new Thread1(CR1,sem1,sem2);
        //new Thread2(CR1,sem1,sem2);
        //new Thread4(CR1);
        //new Thread5(CR1);
        
        CyclicBarrier br1 = new CyclicBarrier(2), br2 = new CyclicBarrier(2);
        
        new Thread3(CR2,br1,br2,mutex);
        new Thread6(CR2,br1,br2,mutex);
    }
    
}
