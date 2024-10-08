class Solution {
public:


    bool canWePlace(vector<int> &stalls, int dist, int cows){
        int cntCows = 1, last = stalls[0];
        for(int i = 1; i < stalls.size(); i++){
            if(stalls[i] - last >= dist) {
                cntCows++;
                last = stalls[i];
            }
            if(cntCows >= cows) return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls[n-1] - stalls[0];
        while(low <= high){
            int mid = (low + high) / 2;
            if(canWePlace(stalls, mid, k) == true){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high;
    }
};

//geekforgeet submition because my spoj not working properly