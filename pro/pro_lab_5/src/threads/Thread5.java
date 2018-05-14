
package threads;

import commonresource.CommonResource1;

/**
 *
 * @author vlad
 */
public class Thread5 extends Thread{
    CommonResource1 CR;
    public Thread5(CommonResource1 CR){
        super("Thread5");
        System.out.println("Thread5 started");
        this.CR = CR;
	start();
    }    
    
    @Override
    public void run(){
        while(true){
            CR.consume();
        }
    }
}
