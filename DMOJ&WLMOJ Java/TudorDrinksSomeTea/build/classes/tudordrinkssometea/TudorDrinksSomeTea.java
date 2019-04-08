/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tudordrinkssometea;
import java.util.*;
/**
 *
 * @author liuti
 */
public class TudorDrinksSomeTea {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner input;
        int answer = 0;
        input = new Scanner(System.in);
        for (int i = 0 ; i<5; i++){
            if (input.nextLine().equals("P")) answer++;
        }
        System.out.println(answer);
    }
    
}
