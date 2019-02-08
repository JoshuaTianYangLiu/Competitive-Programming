/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tournamentselection;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class TournamentSelection {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int a = 0;
        for(int i = 0;i<6;i++){
            String c = in.next();
            if(c.equals("W")) a++;
        }
        if(a==0) System.out.println("-1");
        else if(a<=2) System.out.println("3");
        else if(a<=4) System.out.println("2");
        else if(a<=6) System.out.println("1");
    }
    
}
