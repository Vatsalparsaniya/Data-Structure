import java.util.*;

class LCS
{
  public static List < String > LCS (String A, String B, int a, int b,
				     int[][] K)
  {
    if (a == 0 || b == 0)
      {
	return new ArrayList <> (Collections.nCopies (1, ""));
      }
    if (A.charAt (a - 1) == B.charAt (b - 1))
      {
	List < String > lcs = LCS (A, B, a - 1, b - 1, K);
	for (int i = 0; i < lcs.size (); i++)
	  {
	    lcs.set (i, lcs.get (i) + (A.charAt (a - 1)));
	  }
	return lcs;
      }
    if (K[a - 1][b] > K[a][b - 1])
      return LCS (A, B, a - 1, b, K);
    if (K[a][b - 1] > K[a - 1][b])
      return LCS (A, B, a, b - 1, K);
    List < String > top = LCS (A, B, a - 1, b, K);
    List < String > left = LCS (A, B, a, b - 1, K);
    top.addAll (left);
    return top;
  }

  public static void LL (String A, String B, int[][] K)
  {
    for (int i = 1; i <= A.length (); i++)
      {
	for (int j = 1; j <= B.length (); j++)
	  {
	    if (A.charAt (i - 1) == B.charAt (j - 1))
	      K[i][j] = K[i - 1][j - 1] + 1;

	    else
	      K[i][j] = Integer.max (K[i - 1][j], K[i][j - 1]);
	  }
      }
  }

  public static Set < String > LCS (String A, String B, int[][] K)
  {
    LL (A, B, K);
    List < String > lcs = LCS (A, B, A.length (), B.length (), K);
    return new HashSet <> (lcs);
  }

  public static String LongestString (String[] array)
  {
    int maxLength = 0;
    String longestString = null;
  for (String ans:array)
      {
	if (ans.length () > maxLength)
	  {
	    maxLength = ans.length ();
	    longestString = ans;
	  }
      }
    return longestString;
  }

  public static void main (String[] args)
  {
    Scanner sc = new Scanner (System.in);
    String A = sc.next ();
    String B = sc.next ();
    int[][] K = new int[A.length () + 1][B.length () + 1];
    Set < String > lcs = LCS (A, B, K);
    String[]array = lcs.toArray (new String[0]);
    String maxStr = LongestString (array);
    System.out.println (maxStr.length ());
    System.out.println (lcs.size ());
  for (String ans:lcs)
      {
	System.out.println (ans);
      }
  }
}
