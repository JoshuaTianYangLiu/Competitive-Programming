/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tudordrinksmoretea;
import java.util.*;
/**
 *
 * @author liuti
 */
public class TudorDrinksMoreTea {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner input;
        int answer = 0;
        boolean x = true;
        input = new Scanner(System.in);
        for (int i = 0 ; i<7; i++){
            if (input.nextLine().equals("J")){
                if(x){
                    answer++;
                    x=false;
                }
            }else{
                x=true;
            }
        }
        System.out.println(answer);
    }
    
}
