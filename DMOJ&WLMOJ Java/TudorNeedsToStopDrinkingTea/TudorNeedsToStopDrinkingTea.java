/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tudorneedstostopdrinkingtea;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author liuti
 */
public class TudorNeedsToStopDrinkingTea {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        BufferedReader input;
        String temp = "";
        try{
        input = new BufferedReader(new InputStreamReader(System.in));
        temp = input.readLine();
        }catch(IOException e){}
        long a,b,c,d = 0;
        String[] xStr = temp.split(" ");    
        a = Long.parselong(xStr[0]);
        b = Long.parselong(xStr[1]);
        c = Long.parselong(xStr[2]);
        d = Long.parselong(xStr[3]);
        int counter = 0;
        for(int i=a; i<b+1;i++){
            for(int j=c;j<d+1;j++){
                if(isRelativelyPrime(i,j)) counter++;
            }
        }
        System.out.println(counter);
    }  
    public static boolean isRelativelyPrime(long x,long y){
        long t;
        while (y!=0){
            t=y;
            y=x%y;
            x=t;
        }
        return x==1;
    
    }
}
