/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chocolatedaytest;

/**
 *
 * @author Joshua
 */
public class ChocolateDayTest {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int size = 10;
        int limit = 50;
        int cups[] = {6,7,7,8,4,1,4,6,8,8};
        for(int i = size; i>0; i--){
            for(int j = 0; j<size-i+1;j++){
                int total=0;
                for(int k = j;k<i+j;k++){
                    total+=cups[k];
                }
                if(total==limit){
                    System.out.println(i);
                    System.exit(0);
                }
            }
        }
    }
    
}
