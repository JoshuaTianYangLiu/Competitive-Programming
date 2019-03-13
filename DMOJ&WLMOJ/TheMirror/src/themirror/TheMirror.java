/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package themirror;
import java.util.Scanner;

/**
 *
 * @author liuti
 */
public class TheMirror {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner input;
        
        input = new Scanner(System.in);
        int times = input.nextInt();
        input.nextLine();
        for (int a=0; a<times; a++){
            int answer=0;
            String temp = input.nextLine();
            String[] xStr = temp.split(" ");
            int x[] = new int[2];
            x[0] = Integer.parseInt(xStr[0]);
            x[1] = Integer.parseInt(xStr[1]);
            
            for(int i = x[0]; i<x[1]; i++){
                if(isPrime(i)){
                    answer++;
                }
            }
            System.out.println(answer);
        }
        
    }
    public static boolean isPrime(int x){
        if(x==2) return true;
        for (int i = 2; i<Math.sqrt(x)+1;i++){
            if (x%i==0) return false;
        }
        if(x==1)return false;
        return true;
    }
}
