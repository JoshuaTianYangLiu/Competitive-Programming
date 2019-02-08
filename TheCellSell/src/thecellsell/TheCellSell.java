/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package thecellsell;

import java.text.DecimalFormat;
import java.time.temporal.TemporalQueries;
import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class TheCellSell {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int dO = in.nextInt();
        int e = in.nextInt();
        int w = in.nextInt();
        int dA =dO;
        int dB =dO;
        if(dO<=100) dA =0;
        else dA-=100;
        int totalaB = dA*25 + e*15 + w*20;
        if(dO<=250) dB = 0;
        else dB-=250;
        int totalbB = dB*45 + e*35 + w*25;
        double totala = (double)totalaB/100;
        double totalb = (double)totalbB/100;
        System.out.println("Plan A costs "+totala);
        System.out.println("Plan B costs "+totalb);
        if(totala>totalb) System.out.println("Plan B is cheapest.");
        else if(totala<totalb) System.out.println("Plan A is cheapest.");
        else System.out.println("Plan A and B are the same price.");
    }
    
}
