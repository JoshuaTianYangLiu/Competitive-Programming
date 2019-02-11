/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package itscoldhere;

import java.io.*;

/**
 *
 * @author liuti
 */
public class ItsColdHere {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String temp = in.readLine();
        String[] a;
        a=temp.split(" ");
        String b = a[0];
        int c = Integer.parseInt(a[1]);
        while(!a[0].equals("Waterloo")){
            temp = in.readLine();
            a=temp.split(" ");
            int d = Integer.parseInt(a[1]);
            if(d<c){
                b=a[0];
                c=d;
            }
        }
        System.out.println(b);
    }
    
}
