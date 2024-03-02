// Question Link : https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/counting-the-subarrays-4187713a/
// Code : 

#include<bits/stdc++.h>
using namespace std;

#define ll long long 

int main(){

    int n; cin >> n;
	double a[n],pref[n+1];
	pref[0]=a[0];
	for(int i=0;i<n;i++){
		cin >> a[i];
		pref[i+1]=pref[i]+a[i]; // prefix array
	}
	
	vector<pair<int,int>>ans;

	for(int i=0;i<n;i++){
		int start=i+1,end=i+1,len=0;
		double rem,dif;
		while(end<=n){
			len= end-start+1;
			dif= pref[end]-pref[start-1]; // sum of subarray

			if(len!=n){
				rem= (pref[n]-dif)/(n-len); // sum of remaining subarray
			}else{
				rem=0;
			}
			if(dif/len > rem){
				ans.push_back({start,end}); 
			}
			end++;
		}
	}

	sort(ans.begin(),ans.end());
	cout<< ans.size() <<'\n';
	for(auto i:ans)
	cout << i.first << ' ' << i.second << '\n';







	return 0;
}