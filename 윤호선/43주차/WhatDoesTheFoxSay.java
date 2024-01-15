import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class WhatDoesTheFoxSay {
    public static void main(String[] args) throws IOException {
        final String QUESTION_END="what does the fox say?";

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCase = Integer.parseInt(br.readLine());
        StringBuffer ans=new StringBuffer();

        while (testCase-- > 0) {
            ArrayList<String> foxSay=new ArrayList<>();
            Set<String> saySet = new HashSet<>();
            StringTokenizer st = new StringTokenizer(br.readLine());

            while(st.hasMoreTokens()){
                foxSay.add(st.nextToken());
            }
            String lyric=br.readLine();
            while(!lyric.equals(QUESTION_END)){
                String[] animalSay=lyric.split(" ");
                saySet.add(animalSay[2]);
                lyric=br.readLine();
            }
            for(String say:foxSay){
                if(saySet.contains(say))continue;
                ans.append(say).append(" ");
            }
        }
        System.out.println(ans);
    }
}
