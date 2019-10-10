import java.util.*;
//contributed by hk1997
public class edit_distance{

  public static  int minDistance(String word1, String word2) {
        int n=word1.length(),m=word2.length();
        int[][] dp=new int[n+1][m+1];
        //filling for base cases
        for(int i=0;i<=n;i++)
            dp[i][0]=i;
        for(int j=0;j<=m;j++)
            dp[0][j]=j;
        //normal table filling
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1.charAt(i-1)==word2.charAt(j-1)){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+Math.min(dp[i-1][j],Math.min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];

    }

  public static void main(String[] args){
    //driver code
    Scanner hk= new Scanner(System.in);
    String s1=hk.next();
    String s2=hk.next();
    System.out.println(minDistance(s1,s2));
  }
}
