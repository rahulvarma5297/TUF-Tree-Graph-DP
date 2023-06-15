//* https://practice.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-adjacency-list
//* https://youtu.be/OsNklbh9gYI

class Solution {
    // Function to return the adjacency list for each vertex.
    public ArrayList<ArrayList<Integer>> printGraph(
        int V, ArrayList<ArrayList<Integer>> adj) {
        // Code here
        
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        
        for(int i = 0; i < V; i++){
            ArrayList<Integer> temp = new ArrayList<Integer>();
            temp.add(i);
            
            for(int x : adj.get(i)){
                temp.add(x);
            }
            
            ans.add(temp);
        }
        
        return ans;
    }
}