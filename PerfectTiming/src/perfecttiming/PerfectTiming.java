/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package perfecttiming;

import java.util.*;
import java.io.*;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

/**
 *
 * @author Joshua
 */
public class PerfectTiming {

    /**
     * @param args the command line arguments
     */

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int aX = in.nextInt();
        int aY = in.nextInt();
        int bX = in.nextInt();
        int bY = in.nextInt();
        int time[] = new int[6];
        int e = Math.abs(bX-aX)+Math.abs(bY-aY);
        String f = in.next();
        String g[] = f.split(":");
        for(int i=0; i<6; i++){
            time[i]= Integer.parseInt(g[i]);
        }
        LocalDateTime k = LocalDateTime.now();
        k = LocalDateTime.of(time[0],time[1],time[2],time[3],time[4],time[5]);
        k=k.plusSeconds(e);
        DateTimeFormatter format = DateTimeFormatter.ofPattern("yyyy:MM:dd:HH:mm:ss");
        System.out.println(format.format(k));
    }
}
