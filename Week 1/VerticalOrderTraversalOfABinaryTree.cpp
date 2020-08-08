/*
Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.

Example 1:
Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation: 
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).
*/

//Min and Max for x coordinate
 void findMinMaxx( TreeNode* node, int *min, int *max, int hd)
    {
        if (node == NULL) return;
        if (hd < *min)  *min = hd;
        else if (hd > *max) *max = hd;

        findMinMaxx(node->left, min, max, hd-1);
        findMinMaxx(node->right, min, max, hd+1);
    }

//Min and Max for y Coordinate
     void findMinMaxy( TreeNode* node, int *min, int *max, int hd)
    {
        if (node == NULL) return;
        if (hd < *min)  *min = hd;
        else if (hd > *max) *max = hd;
         
        findMinMaxy(node->left, min, max, hd-1);
        findMinMaxy(node->right, min, max, hd-1);
    }   
        
//Printing nodes for psrticular coordinate

    void printVerticalLine(TreeNode* node, int line_no,int y, int hd1,int hd2,vector<int > *v3)
    {
        if (node == NULL) return;
        if (hd1 == line_no && hd2==y)
            v3->push_back(node->val);

        printVerticalLine(node->left, line_no,y, hd1-1,hd2-1,v3);
        printVerticalLine(node->right, line_no,y, hd1+1,hd2-1,v3);
    }
    
//traversing each coordinate and searching in whole tree    
    void verticalOrder(TreeNode* root,vector<vector<int>> *v1)
    {
    int minx = 0, maxx = 0,x,y,miny=0,maxy=0;
        
    findMinMaxx(root, &minx, &maxx, 0);
    findMinMaxy(root, &miny, &maxy, 0);
        
    for (x = minx; x <= maxx; x++)
    {
        vector<int> v2;
        for(y=maxy;y>=miny;y--)
        {
            vector<int> v3;
            printVerticalLine(root, x,y, 0,0,&v3);
            sort(v3.begin(),v3.end());
            for(int i=0;i<v3.size();i++)
                v2.push_back(v3[i]);
        }
        v1->push_back(v2);
    }
    }

//Driver Code
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v1;
        verticalOrder(root,&v1);
        return v1;
    }
};
