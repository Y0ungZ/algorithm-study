class Solution {
    public int[] solution(int n, long left, long right) {
        int size = (int)(right - left) + 1;
        int[] answer = new int[size];
        int idx = 0;
        long from = left;
        long to = right; 
        for(;from <= to;from++){
            long col = from % (long)n;    //열
            long row = from / (long)n + 1;  //행 + 1
           
            if(row > col)answer[idx] = (int)row;
            else answer[idx] = (int)(col + (long)1);
            idx++;
        }
        return answer;
    }
}