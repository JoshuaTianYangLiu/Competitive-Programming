/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mrwhite.scarnival;

import java.io.*;
import java.util.*;

/**
 *
 * @author liutianyang
 */
public class MrWhiteSCarnival {
    static List<Integer> base = new ArrayList<>();
    static List<Integer> power = new ArrayList<>();
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        int answer = 1;
        int partAnswer = 0;
        primeFactor(a);
        for(int i = 0;i<base.size();i++){
            for(int j = 0; j<power.get(i)+1; j++){
                partAnswer+= Math.pow(base.get(i),j);
            }
            answer*=partAnswer;
            partAnswer=0;
        }
        if (a==1){
            System.out.println(1);
        }else{
        System.out.println(answer);
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
    
}
