/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package greatsequence;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author liuti
 */
public class GreatSequence {

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
        int n,sum,times = 0;
        String[] xStr = temp.split(" ");    
        n = Integer.parseInt(xStr[0]);
        sum = Integer.parseInt(xStr[1]);
        times = Integer.parseInt(xStr[2]);
    }
    
}
