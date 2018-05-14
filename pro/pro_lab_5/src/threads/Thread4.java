
package threads;

import commonresource.CommonResource1;

/**
 *
 * @author vlad
 */
public class Thread4 extends Thread{
    CommonResource1 CR;
    public Thread4(CommonResource1 CR){
        super("Thread4");
        System.out.println("Thread4 started");
        this.CR = CR;
	start();
    }    
    
    @Override
    public void run(){
        while(true){
            CR.produce();
        }
    }
}
