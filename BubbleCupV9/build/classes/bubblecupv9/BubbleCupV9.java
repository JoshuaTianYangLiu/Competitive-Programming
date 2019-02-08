/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bubblecupv9;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author liuti
 */
public class BubbleCupV9 {

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
        int a,b,c,cost= 0;
        String[] xStr = temp.split(" ");    
        a = Integer.parseInt(xStr[0]);
        b = Integer.parseInt(xStr[1]);
        c = Integer.parseInt(xStr[2]);
        String bin="";
        for(int i = 0; i<a; i++){
            bin+=decToBin(i,a);
        }
        for(int i=0;i<bin.length();i++){
            if(String.valueOf(bin.charAt(i)).equals("0")){
                cost+=b;
            }else{
                cost+=c;
            }
        }
        System.out.println(cost);
        System.out.println(decToBin(12,32));
        System.out.println(decToBin(12,32));
        
    }
    public static String decToBin(int x,int largest){
        double sizeD;
        sizeD = (Math.log((double)largest-1)/Math.log(2.0d));
        int size = (int)sizeD;
        String binR = Integer.toString(x,2);
        String zeros = "";
        for(int i=0;i<size-binR.length()+1;i++){
            zeros+="0";
        }
        return zeros+binR;
        //This question is bs
        
    }
}
