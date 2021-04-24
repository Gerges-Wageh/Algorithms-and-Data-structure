#include <bits/stdc++.h>
#include <iostream>
// Finding longest common substring naively 
// Time complexity: O(N*N*M) ;where N is the length of the shortest string ans M is the length of the other
// Space Complexity: O(1)  
using namespace std;
int main(){
	string t,s,ans;
	cin>>t>>s;
	for(unsigned int i=0;i<s.length();i++){
		for(unsigned int j=i;j<s.length();j++){
			string temp = s.substr(i,j-i+1);
			unsigned int x = 0;
			for(unsigned int k=0;k<t.length();k++){
				if(s[x]==t[k])
					x++;
				else if(x==temp.length()){
						break;
				}
				else{
					x=0;
				}
			}
			if(x == temp.length()){
				if(temp.length()>ans.length())
					ans = temp;
			}
		}
	}
	cout<<ans;
	return 0;
}
