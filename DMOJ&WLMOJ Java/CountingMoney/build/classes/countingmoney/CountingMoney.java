/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package countingmoney;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/**
 *
 * @author Joshua
 */
public class CountingMoney {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        List<Integer> h;
        BufferedReader input;
        String temp = "";
        int times = 0;
        input = new BufferedReader(new InputStreamReader(System.in));
        try{
        temp = input.readLine();
        times = Integer.parseInt(temp);
        }catch(Exception e){}
        for(int i = 0; i<times; i++){
            try{
            temp = input.readLine();
            }catch(Exception e){}
            String[] xStr = temp.split(" ");
            String a = xStr[0];
            int b = Integer.parseInt(xStr[1]);
            if(a.equals("B")){
                h=negativeBase(b,-2);
                for(int j=h.size()-1;j>0;j--){
                System.out.print(h.get(j));
                }
                System.out.println(h.get(0));
            }else{
                System.out.println(baseTen(b));
            }
        }
    }
    public static List<Integer> negativeBase(int integer, int base) {
        List<Integer> digits = new ArrayList<>();
        int prev = 0;
        while (integer != 0) {
            int i = 0;
            prev = integer;
            if(prev>0){
                i = Math.abs(integer % base);
                integer = integer / base;
            }else if(prev<0){
                integer+=base;
                i = Math.abs(integer%base);
                integer = integer/base;
            }
            digits.add(i);
        }
        return digits;
    }
    public static int baseTen(int integer){
        String s = Integer.toString(integer);
        int total = 0;
        for(int i = 0; i<s.length(); i++){
            int temp = Integer.parseInt(String.valueOf(s.charAt(i)));
            total += temp*Math.pow(-2,s.length()-1-i);
        }
        return total;
    }
}
