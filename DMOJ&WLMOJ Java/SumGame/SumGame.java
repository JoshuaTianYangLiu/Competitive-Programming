/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sumgame;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 *
 * @author liuti
 */
public class SumGame {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String temp = in.readLine();
        int size = Integer.parseInt(temp);
        StringTokenizer st = new StringTokenizer(in.readLine());
        int a[] = new int[size];
        int b[] = new int[size];
        for(int i=0;i<size; i++){
            a[i]=Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(in.readLine());
        for(int i=0;i<size; i++){
            b[i]=Integer.parseInt(st.nextToken());
        }
        
        
        System.out.println(sum(a,b,size));
    }
    static int sum(int a[], int b[],int size){
        int aT = 0;
        int bT = 0;
        for(int j =0; j<size; j++){
                aT+=a[j];
                bT+=b[j];
            }
        if(aT==bT) return size;
        for(int i = size-1; i>=0; i--){
            aT-=a[i];
            bT-=b[i];
            if(aT==bT){
                return i;
            }
        }
        return 0;
    }
}
