/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package snowball.fight;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author Joshua
 */
public class SnowballFight {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        BufferedReader input = null;
        int a[] = new int[2];
        int b[]= new int[2];
        String temp = "";
        try{
        input = new BufferedReader(new InputStreamReader(System.in));
        temp = input.readLine();
        }catch(IOException e){}
        String[] tempArr =temp.split(" ");
        a[0]=Integer.parseInt(tempArr[0]);
        a[1]=Integer.parseInt(tempArr[1]);
        try {
            temp=input.readLine();
        } catch (Exception e) {}
        tempArr =  temp.split(" ");
        b[0]=Integer.parseInt(tempArr[0]);
        b[1]=Integer.parseInt(tempArr[1]);
        if((a[0]-1)*b[1]==(b[0]-1)*a[1]){
            System.out.println("-1");
        }else if((a[0]-1)*b[1]<(b[0]-1)*a[1]){
            System.out.println("2");
        }else if((a[0]-1)*b[1]>(b[0]-1)*a[1]){
            System.out.println("1");
        }
    }
}
