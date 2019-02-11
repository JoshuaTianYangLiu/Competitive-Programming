/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package distinctnumbers;

import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author liuti
 */
public class DistinctNumbers {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int y = in.nextInt();
        do{
            y++;
        }while(!dNum(y));
        System.out.println(y);
    }
    static boolean dNum(int a){
        String b = String.valueOf(a);
        boolean[] c = new boolean[10];
        Arrays.fill(c,true);
        for(int i =0; i<b.length(); i++){
            int d = Integer.parseInt(b.substring(i, i+1));
            if(c[d]) c[d]=false;
            else return false;
        }
        return true;
    }
}
