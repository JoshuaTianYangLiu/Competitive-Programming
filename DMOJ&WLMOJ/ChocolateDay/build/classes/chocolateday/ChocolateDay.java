/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chocolateday;

import com.sun.org.apache.xalan.internal.xsltc.compiler.util.Type;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author Joshua
 */
public class ChocolateDay {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        BufferedReader input = null;
        String temp = "";
        try{
        input = new BufferedReader(new InputStreamReader(System.in));
        temp = input.readLine();
        }catch(IOException e){}
        int size =0;
        int times = 0;
        String[] xStr = temp.split(" ");    
        size = Integer.parseInt(xStr[0]);
        times = Integer.parseInt(xStr[1]);
        int[] cups= new int[size];
        for(int i = 0; i<times;i++){
            try{
                temp=input.readLine();
            }catch(Exception e){}
            int a = 0;
            int b = 0;
            int c = 0;
            String[] temp1;
            temp1 = temp.split(" ");
            a = Integer.parseInt(temp1[0]);
            b = Integer.parseInt(temp1[1]);
            c = Integer.parseInt(temp1[2]);
            for(int j = a; j<=b; j++){
               cups[j-1]+=c;
            }
        }
        int limit = 0;
        try {
            temp=input.readLine();
        } catch (Exception e) {}
        limit = Integer.parseInt(temp);
        for(int i = size; i>0; i--){
            for(int j = 0; j<size-i+1;j++){
                int total=0;
                for(int k = j;k<i+j;k++){
                    total+=cups[k];
                }
                if(total<=limit){
                    System.out.println(i);
                    System.exit(0);
                }
            }
        }
        System.out.println("0");
    }
}
