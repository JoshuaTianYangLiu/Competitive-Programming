/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rsanumbers;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author liuti
 */
public class RSANumbers {
    static List<Integer> base = new ArrayList<>();
    static List<Integer> power = new ArrayList<>();
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int a = 0;
        int b = 0;
        Scanner input;
        int answer = 0;
        input = new Scanner(System.in);
        a=input.nextInt();
        b=input.nextInt();
        int counter = 0;
        for (int i=a; i<b+1;i++){
            
            primeFactor(i);
            if(listUsed(1)&&listUsedPower(1)&&power.get(1).equals(1)&&!listUsed(2)&&power.get(0).equals(1)){
                counter++;
            }
            base = new ArrayList<>();
            power = new ArrayList<>();
        }
        System.out.println("The number of RSA numbers between " + a +" and " + b+" is "+counter);
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
    public static boolean listUsedPower(int position){
        try{
            power.get(position);
            return true;
        }catch(Exception e){
            return false;
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
        //if(x!=0)
        {
            if(x % i==0){
                return true;
            }
        }
        return false;
    }
}
