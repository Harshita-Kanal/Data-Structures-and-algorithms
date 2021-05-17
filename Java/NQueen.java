import java.util.*;

class Solution8 {
    String board[][];
    boolean colums[];
    boolean left[];
    boolean right[];
    Set<List<String>>lists;
    public List<List<String>> solveNQueens(int n) {
         board = new String[n][n];
        for (String arr[] : board) {
            Arrays.fill(arr, ".");
        }
        lists=new HashSet<>();
         colums = new boolean[n];
         left = new boolean[2 * n - 1];
         right = new boolean[2 * n - 1];
         solve(0,n);
         return new ArrayList<>(lists);
    }
    void solve(int i,int n)
    {
        if (i==n)
        {
            List<String>list=new ArrayList<>();
            for (int i1=0;i1<board.length;i1++)
            {
                String res="";
                for (int j1=0;j1<board[0].length;j1++)
                {
                    res=res+board[i1][j1];
                }
                list.add(res);
            }
            lists.add(list);
            return;
        }
        for (int col=0;col<n;col++)
        {
            if (issafe(i,col,n)==true)
            {
                board[i][col]="Q";
                colums[col]=true;
                left[i+col]=true;
                right[i-col+n-1]=true;
                solve(i+1,n);
                board[i][col]=".";
                colums[col]=false;
                left[i+col]=false;
                right[i-col+n-1]=false;
            }
        }

    }
    boolean issafe(int i,int j,int n)
    {
        if (colums[j]==true)
        {
            return false;

        }
        if (left[i+j]==true)
        {
            return false;

        }
        if (right[i-j+n-1]==true)
        {
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int n=scanner.nextInt();
        Solution8 solution8=new Solution8();
        System.out.println(solution8.solveNQueens(n));
    }

}
