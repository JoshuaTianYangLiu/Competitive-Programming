/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package americanadian;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class AmeriCanadian {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        String a = "";
        do{
            a=in.nextLine();
            if(a.length()>4){
                if(a.substring(a.length()-2,a.length()).equals("or") && !a.subSequence(a.length()-3, a.length()-2).equals("o")){
                    a=a.substring(0,a.length()-2)+"our";
                }
            }
            if(!(a.equals("quit!"))){
                System.out.println(a);
            }
        }while(!a.equals("quit!"));
    }
    
}
