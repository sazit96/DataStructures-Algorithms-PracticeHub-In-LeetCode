class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>a;
        for(string it : operations)
        {
            if(it=="+") a.push_back( a[a.size()-1] + a[a.size()-2] );
            else if(it=="D") a.push_back( 2 * a.back() );
            else if(it=="C") a.pop_back();
            else a.push_back(stoi(it));
        }
        int sum=0;
        for(int i : a) sum+=i;
        return sum;
    }
};