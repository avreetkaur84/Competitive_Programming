class Solution {

    public:
    
        int function(int m, int n, int r, int d, int &cnt) {
    
            if (r == m && d == n) {
    
                cnt++;
    
                return cnt;  
    
            }
    
            if (r > m || d > n) return cnt;  
    
    
    
            function(m, n, r + 1, d, cnt);
    
            function(m, n, r, d + 1, cnt);
    
    
    
            return cnt;  
    
        }
    
    
    
        int uniquePaths(int m, int n) {
    
            int cnt = 0;
    
            function(m - 1, n - 1, 0, 0, cnt);
    
            return cnt; 
    
        }
    
    };