/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package listminhard;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class ListMinHard {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        List<Integer> a = new ArrayList<Integer>();
        Scanner in = new Scanner(System.in);
        int b = in.nextInt();
        for(int i = 0 ; i<b; i++){
            a.add(in.nextInt());
        }
        Collections.sort(a);
        //Must faster ^
        
        for(int i = 0; i<b; i++){
            System.out.println(a.get(i));
        } 
    }
    
}
