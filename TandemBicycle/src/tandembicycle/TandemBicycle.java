/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tandembicycle;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class TandemBicycle {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        BufferedReader input;
        String temp = "";
        input = new BufferedReader(new InputStreamReader(System.in));
        temp = input.readLine();
        int q = Integer.parseInt(temp);
        temp = input.readLine();
        int size = Integer.parseInt(temp);
        int[] a = new int[size];
        int[] b = new int[size];
        String[] tempS;
        temp = input.readLine();
        tempS = temp.split(" ");
        for(int i =0; i<size; i++){
            a[i]=Integer.parseInt(tempS[i]);
        }
        String[] tempSb;
        temp = input.readLine();
        tempSb = temp.split(" ");
        for(int i =0; i<size; i++){
            b[i]=Integer.parseInt(tempSb[i]);
        }
        Arrays.sort(a);
        Arrays.sort(b);
        int total =0;
        if(q ==2){
            for(int i=0; i<size; i++){
                if(a[i]>b[size-1-i]) total+=a[i];
                else total+=b[size-1-i];
            }
        }else{
            for(int i=0; i<size; i++){
                if(a[i]>b[i]) total+=a[i];
                else total+=b[i];
            }
        }
        System.out.println(total);
    }
    
}
