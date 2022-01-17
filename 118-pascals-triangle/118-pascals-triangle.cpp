class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        vector<int> temp(numRows,0); 
        temp[0]=1;
        res[0].push_back(1);
        for(int i=1; i<numRows; i++){
            for(int j=numRows-1; j>0; j--){
                temp[j]+=temp[j-1];
            }
            for(int j=0; j<numRows; j++){
                if(temp[j]!=0) res[i].push_back(temp[j]);
                else break;
            }
        }
        return res;
    }
};