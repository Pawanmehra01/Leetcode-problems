class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nger(n);
        vector<int>ngel(n,-1);
        stack<int>s;
        for(int i =0 ;i < n ;i ++){
            while(!s.empty() && heights[s.top()]>= heights[i]){
                s.pop();
            }
            if(!s.empty()){
                ngel[i] = s.top();
            }
            s.push(i);
        }
       
       while(!s.empty())s.pop();

        for(int i = n-1 ;i>=0 ;i -- ){
            while(!s.empty() && heights[s.top()]>= heights[i]){
                s.pop();
            }
            if(!s.empty()){
                nger[i] = s.top();
            }else{
                nger[i] = n ;
            }
            s.push(i);
        }
        int maxArea = 0 ;
        for(int i = 0 ;i < n ;i ++){
            int breadth  = nger[i]-ngel[i]-1 ;
            maxArea = max(maxArea , heights[i]*breadth );

        }
    return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m =matrix[0].size();
        int MaxArea = INT_MIN;
        vector<int>heights(m,0);
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j< m;j ++){
                if(matrix[i][j]=='1')heights[j]++;
                if(matrix[i][j]=='0')heights[j] = 0;
            }
            int Area = largestRectangleArea(heights);
            MaxArea = max(Area,MaxArea);
        }
        return MaxArea;
    }
};