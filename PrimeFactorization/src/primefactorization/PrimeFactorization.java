/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package primefactorization;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class PrimeFactorization {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static List<Integer> base = new ArrayList<>();
    static List<Integer> power = new ArrayList<>();
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException{
        // TODO code application logic here
        //Too slow
        int size = readInt();
        for(int c=0; c<size; c++){
            int a = readInt();
            int answer = 1;
            int partAnswer = 0;
            primeFactor(a);
            String b ="";
            for(int i = 0;i<base.size();i++){
                for(int j = 0; j<power.get(i); j++){
                    b+=base.get(i)+" ";
                }
            }
            b=b.trim();
            System.out.println(b);
        }
    }
    public static void primeFactor(int x){
        int original = x;
        int position = 0;
        for(int i =2; i<(original/2)+1; i++){
            do{
                if(divisible(x,i)){
                    if(listUsed(position)){
                        power.set(position,power.get(position)+1);
                        x=x/i;
                    }else{
                    base.add(position,i);
                    power.add(position, 1);
                    x=x/i;
                    }
                }
            }while(divisible(x,i));
            if (listUsed(position)){
                position++;
            } 
        }
        if (!listUsed(0)){
            base.add(original);
            power.add(1);
        }
    }
    public static boolean listUsed(int position){
        try{
            base.get(position);
            return true;
        }catch(Exception e){
            return false;
        }
    }
    public static boolean divisible(int x,int i){
        if(x!=0){
            if(x % i==0){
                return true;
            }
        }
        return false;
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
