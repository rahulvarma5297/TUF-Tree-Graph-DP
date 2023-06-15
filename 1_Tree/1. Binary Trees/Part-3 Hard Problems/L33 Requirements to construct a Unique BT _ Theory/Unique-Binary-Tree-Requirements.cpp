//* https://practice.geeksforgeeks.org/problems/unique-binary-tree-requirements/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=unique-binary-tree-requirements
//* https://youtu.be/9GMECGQgWrQ

class Solution
{
public:
    bool isPossible(int a,int b)
    {
        //code here
        
        return ((a==2 || b==2) && (a != b) ? true : false);
    }
};