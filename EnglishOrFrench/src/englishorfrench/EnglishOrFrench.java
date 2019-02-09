/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package englishorfrench;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

/**
 *
 * @author Joshua
 */
public class EnglishOrFrench {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        BufferedReader input;
        String temp = "";
        input = new BufferedReader(new InputStreamReader(System.in));
        int size = Integer.parseInt(input.readLine());
        String a="";
        int b[] = new int[2];
        for(int i=0;i<size; i++){
            a=input.readLine();
            for(int j=0;j<a.length(); j++){
                if(a.charAt(j)=='t'||a.charAt(j)=='T') b[0]++;
                else if (a.charAt(j)=='s'||a.charAt(j)=='S') b[1]++;
            }
        }
        a = a.toLowerCase();
        if(b[0]==b[1]) System.out.println("French");
        else if(b[0]>b[1]) System.out.println("English");
        else System.out.println("French");
    }
}
