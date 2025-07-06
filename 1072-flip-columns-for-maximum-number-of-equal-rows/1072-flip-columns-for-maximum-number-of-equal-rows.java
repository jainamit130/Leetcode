class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        Map<String,Integer> mp = new HashMap<>();
        for(int i=0;i<matrix.length;i++) {
            String str = new String();
            String strrev = new String();
            for(int j=0;j<matrix[0].length;j++) {
                str+=matrix[i][j];
                if(matrix[i][j]==0){
                    strrev+=1;
                } else {
                    strrev+=0;
                }
            }

            if(str.charAt(0)=='0'){
                mp.put(str,mp.getOrDefault(str,0)+1);
            } else {
                mp.put(strrev,mp.getOrDefault(strrev,0)+1);
            }
        }

        return Collections.max(mp.values());
    }
}