/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication7;

import java.util.List;

/**
 *
 * @author Joshua
 */
public class JavaApplication7 {
    public static void check1(){
        boolean a = false;
        boolean b = false;
        boolean c = false;
        boolean d = false;
        
        boolean check = true;
        

        
        for(int i = 1; i<16; i++){
            boolean start = a&&b;
        
            boolean finish = a||b;
            
            if(start==finish){
            }else{
                check = false;
            }
            if(!a){
                a=true;
            }else{
                if(!b){
                    a=false;
                    b=true;
                }else{
                    if(!c){
                        a=false;
                        b=false;
                        c=true;
                    }else{
                        if(!d){
                            a=false;
                            b=false;
                            c=false;
                            d=true;
                        }
                    }
                }
            }
        }
        System.out.println(check); 
    }
    public static void check2(){
        for(int a = 1; a<17; a++){
            for(int b = a; b<17; b++){
                for(int c = b; c<17; c++){
                    if(a+b>c && b+c>a && a+c>b && a!=b && b!=c && a!=c && a+b+c<17){
                        System.out.println(a+" "+b+" "+c);
                    }
                }
            }
        }
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        check1();
        check2();
        
    }
}
