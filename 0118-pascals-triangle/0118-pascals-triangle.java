class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList();
        List<Integer> lastRow = new ArrayList<>();
        lastRow.add(1);
        ans.add(lastRow);
        for(int i=1;i<numRows;i++) {
            List<Integer> newRow = new ArrayList();
            newRow.add(1);
            for(int j=1;j<lastRow.size();j++) {
               int sum = lastRow.get(j-1)+lastRow.get(j);
               newRow.add(sum); 
            }
            newRow.add(1);
            ans.add(newRow);
            lastRow = newRow;
        }
        return ans;
    }
}