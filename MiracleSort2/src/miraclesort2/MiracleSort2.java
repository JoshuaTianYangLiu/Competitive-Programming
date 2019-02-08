/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package miraclesort2;

import java.util.*;
import sun.management.snmp.jvminstr.NotificationTargetImpl;
/**
 *
 * @author Joshua
 */
public class MiracleSort2 {

    /**
     * @param args the command line arguments
     */
    static List<Long> nL = new ArrayList<Long>();
    static List<Long> pL = new ArrayList<Long>();
    static List<Integer> in = new ArrayList<Integer>();
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner input = new Scanner(System.in);
        int size = input.nextInt();
        long temp = 0;
        long[] a = new long[size];
        for(int i = 0; i<size; i++){
            temp = input.nextLong();
            if(temp< -2147483648){
                nL.add(temp);
            }else if(temp > 2147483647 ){
                pL.add(temp);
            }else{
                in.add((int)temp);
            }
        }     
        long mem;
        for(int i = 0; i<nL.size()-1; i++){
            for(int j=i+1; j<nL.size(); j++){
                if(nL.get(j)<nL.get(i))
                {
                    mem = nL.get(i);
                    nL.set(i, nL.get(j));
                    nL.set(j, mem);
                }
            }
        }
        for(int i = 0; i<pL.size()-1; i++){
            for(int j=i+1; j<pL.size(); j++){
                if(pL.get(j)<pL.get(i))
                {
                    mem = pL.get(i);
                    pL.set(i, pL.get(j));
                    pL.set(j, mem);
                }
            }
        }
        for(int i = 0; i<in.size()-1; i++){
            for(int j=i+1; j<in.size(); j++){
                if(in.get(j)<in.get(i))
                {
                    mem = in.get(i);
                    in.set(i, in.get(j));
                    in.set(j, (int)mem);
                }
            }
        }
        for(int i = 0; i<nL.size(); i++){
            System.out.println(nL.get(i));
        }
        for(int i = 0; i<in.size(); i++){
            System.out.println(in.get(i));
        }
        for(int i = 0; i<pL.size(); i++){
            System.out.println(pL.get(i));
        }
    }
    
}
