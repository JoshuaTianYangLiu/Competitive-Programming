/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package miraclesort;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class MiracleSort {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner input = new Scanner(System.in);
        int size = input.nextInt();
        long[] a = new long[size];
        for(int i = 0; i<size; i++){
            a[i] = input.nextLong();
        }
        long mem = 0 ;
        for(int i = 1; i<size; i++){
            NEXTINT:
            for(int j=1; j<=i; j++){
                if(a[j-1]<a[i]&&a[j]>a[i]){
                    mem = a[i];
                    for(int x = j; x>=j; x--){
                        a[x]=a[x-1];
                    }
                    a[j]= mem;
                    break NEXTINT;
                }
                if(a[i]<a[0]){
                    mem = a[i];
                    for(int x = i; x>0; x--){
                        a[x]=a[x-1];
                    }
                    a[0]= mem;
                    break NEXTINT;
                }
                
            }
        }
        for(int i = 0; i<size; i++){
            System.out.println(a[i]);
        }
    }
}
