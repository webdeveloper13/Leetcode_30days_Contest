class Solution {
    public String stringShift(String s, int[][] shift) {
            int left = 0;
            int right =0;
            for(int i = 0;i<shift.length;i++)
            {

                if(shift[i][0]==0)
                {
                    left += shift[i][1];
                }

                else
                {
                    right += shift[i][1];
                }
            }

          int val = left - right;
          if(val>s.length()|| -val>s.length())
          {
              val = val%s.length();
          }
        
          if(val<0)
          {
              val = val + s.length();
          }
        
          return s.substring(val) + s.substring(0,val);

        }
}