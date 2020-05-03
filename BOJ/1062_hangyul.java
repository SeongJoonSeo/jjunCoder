import java.util.*;
public class Main{
   static int N, K;
   static boolean dic[][];
   //단어들이 가지고 있는 알파벳 배열
   
   static int mapping[] = {0,0,0,1,2,3,4,5,0,6,7,8,9,0,10,11,12,13,14, 0,15,16,17,18,19,20};
   //a,c,i,n,t를 제외하고 매핑   a,b,c,d,e,f,g,h,i,j,k,l,m,n, o, p, q, r, s, t, u, v, w, x, y, z
         
   static boolean visited[] = new boolean [21];
   //가르친 알파벳 배열.
   public static void main(String args[]) {
      Scanner scan = new Scanner(System.in);
      N = scan.nextInt();
      K = scan.nextInt();
      dic = new boolean[N][21];
      
      for(int i = 0; i < N; i++) {
         String t= scan.next();
         int len = t.length();
         for(int j = 0; j < len; j++) {
            if(t.charAt(j)=='a'||t.charAt(j)=='c'||t.charAt(j)=='i'||t.charAt(j)=='n'||t.charAt(j)=='t')
               continue;
            int idx = t.charAt(j)-'a';
            dic[i][mapping[idx]] = true;
         }
      }//a,c,i,n,t는 무조건 포함되야함.
      
      if(K < 5) {
         System.out.println(0);
         return ;
      }//최소 5개 이상은 가르쳐야 단어를 알 수 있음.
      
      comb(0,K-5);
      //5개를 제외한 나머지 21개중 조합 고르기.
      
      System.out.println(max);
   }
   static int max = 0;
   
   
   static void comb(int start, int step) {
      if(step == 0) {
         int result = 0;
      
         for(int j = 0; j < N; j++) {
            boolean count = true;
            for(int i = 0; i < 21; i++) {
               if(dic[j][i] && !visited[i]) {
                  count = false;
                  //단어에는 포함되있는데 가르친거에 포함되있지 않으면 break;
                  break;
               }
            }
            if(count) {
               result++;
            }
         }
         if(result > max) max = result;
         return;
      } 
      
      for(int i = start; i < 21; i++) {
         if(!visited[i]) {
            visited[i] = true;
            comb(i+1, step-1);
            visited[i] = false;
         }
      }
   }
}