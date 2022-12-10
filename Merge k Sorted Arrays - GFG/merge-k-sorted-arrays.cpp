//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class data{
    public:
    int val,apos,vpos;
    data(int value , int ap , int vp){
        val = value;
        apos = ap;
        vpos = vp;
    }
};

class mycmp{
    public:
    bool operator()(data &a , data &b){
        return  a.val > b.val;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        
        priority_queue<data, vector<data> , mycmp > pq;
        for(int i=0;i<k;i++){
            data d(arr[i][0],i,0);
            pq.push(d);
        }
        vector<int> ans;
        while(!pq.empty()){
            data cur = pq.top();
            pq.pop();
            ans.push_back(cur.val);
            int ap = cur.apos;
            int vp = cur.vpos;
           
            if(vp+1 < arr[ap].size()){
                data p(arr[ap][vp+1],ap,vp+1);
                pq.push(p);
            }
        }
        return ans;
    }
};














//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends