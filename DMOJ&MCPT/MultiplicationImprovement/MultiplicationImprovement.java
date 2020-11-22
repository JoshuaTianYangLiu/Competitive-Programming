/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package multiplicationimprovement;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class MultiplicationImprovement {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        st = new StringTokenizer(br.readLine(),"x");
        int a = st.countTokens();
        int b[] = new int[a];
        long prod=1;
        for(int i=0; i<a; i++){
            b[i]=readInt();
            prod*=b[i];
        }
        Arrays.sort(b);
        String out="";
        for(int i=0; i<a; i++)out+=b[i]+"x";
        System.out.println(out.substring(0,out.length()-1));
        System.out.println(prod);
    }



    static int readInt() throws IOException {
         return Integer.parseInt(st.nextToken());
    }
}
