/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ispeaktxtmsg;

import java.util.Scanner;

/**
 *
 * @author liuti
 */
public class ISpeakTXTMSG {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        String a = "";
        while(!a.equals("TTYL")){
            a = in.nextLine();
            if(a.equals("CCC")) System.out.println("Canadian Computing Competition");
            else if(a.equals("CU")) System.out.println("see you");
            else if(a.equals(":-)")) System.out.println("I'm happy");
            else if(a.equals(":-(")) System.out.println("I'm unhappy");
            else if(a.equals(";-)")) System.out.println("wink");
            else if(a.equals(":-P")) System.out.println("stick out my tongue");
            else if(a.equals("(~.~)")) System.out.println("sleepy");
            else if(a.equals("TA")) System.out.println("totally awesome");
            else if(a.equals("CUZ")) System.out.println("because");
            else if(a.equals("TY")) System.out.println("thank-you");
            else if(a.equals("YW")) System.out.println("you're welcome");
            else if(!a.equals("TTYL")) System.out.println(a);
        }
        System.out.println("talk to you later");
    }
    
}
