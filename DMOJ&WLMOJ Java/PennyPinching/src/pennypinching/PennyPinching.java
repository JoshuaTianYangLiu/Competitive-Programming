/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package pennypinching;

import java.util.*;
import java.io.*;
import java.text.DecimalFormat;

/**
 *
 * @author Joshua
 */


public class PennyPinching {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = 10;//readInt()
        double total =0;
        Random r = new Random();
        double testTotal=(double)r.nextInt(5000)/100.0;
        double testOut=testTotal;
        double testIn[] = new double[10];
        for(int i=1; i<size; i++){
            testIn[i]=(double)r.nextInt(500)/100.0;
            testTotal-=testIn[i];
        }
        testIn[9]=testTotal;
        
        ArrayList<Double> upList[] = new ArrayList[7];
        for(int i=0; i<7; i++) upList[i] = new ArrayList<Double>();
        for(int i=0; i<size; i++){
            double a = testIn[i];//readDouble
            double temp =a;
            temp = round(a);
            double tempA = a;
            tempA*=100;
            tempA=Math.round(tempA);
            tempA%=10;
            tempA = Math.round(tempA);
            if((tempA>2&&tempA<5)||(tempA>7&&tempA<10)){
                upList[(int)tempA-3].add(a);
            }else{
                total+=round(temp);
            }
        }
        int start =0;
        int end = 6;
        while(start!=end){
            if(upList[start].size()==0){
                start++;
            }else if(upList[end].size()==0){
                end--;
            }else{
                total+=round(upList[start].remove(upList[start].size()-1)+upList[end].remove(upList[end].size()-1));
            }
        }
        double temp =0;
        for(int i=0; i<upList[start].size(); i++){
            temp+=upList[start].get(i);
            if(i%2==1){
                total+=round(temp);
            }
        }
        total+=round(temp);
        DecimalFormat dc = new DecimalFormat("0.00");
        System.out.println(dc.format(total));
        System.out.println(dc.format(testOut));
        for(int i=0; i<size; i++)System.out.print(testIn[i]+" ");
    }

    static double round(double a){
        a*=20;
        a=Math.round(a);
        a/=20;
        return a;
    }
    static String next () throws IOException {
        if (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
         return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
         return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
          return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }
}
