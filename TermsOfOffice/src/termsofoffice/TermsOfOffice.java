/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package termsofoffice;

import java.util.*;

/**
 *
 * @author Joshua
 */
public class TermsOfOffice {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        for(int i = a; i<=b; i+=60){
            System.out.println("All positions change in year "+i);
        }
    }
    
}
