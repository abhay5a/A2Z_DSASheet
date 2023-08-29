#include<bits/stdc++.h>
using namespace std;

//Remove Outermost Paranthesis (Ques 111)
    string removeOuterParentheses(string S) {
        string res;
        int opened = 0;
        for (char c : S) {
            if (c == '(' && opened++ > 0) res += c;
            if (c == ')' && opened-- > 1) res += c;
        }
        return res;
    }

//Reverse words in a given string/Palindrome check (Ques 112)
string reverseWords(string s) {
    int n=s.size();  
  int i=0;
  int l=0,r=0;
  reverse(s.begin(),s.end());
  while(i<n)
  {
    while(i<n && s[i]!=' ')
    {
      s[r++]=s[i++];
    }
    if(l<r)
    {
      reverse(s.begin()+l,s.begin()+r);
      s[r]=' ';
      r++;
      l=r;
    }
    i++;
  }
  string str=s.substr(0,r-1);
  return str;
}

//Largest odd number in a string (Ques 113)
string largestOddNumber(string num) {
    for (int i = num.size() - 1; i >= 0; --i)
        if ((num[i] - '0') % 2)
            return num.substr(0, i + 1);
    return string();
}

//Longest common prefix (Ques 114)
string commonPrefix(vector<string>& arr,int n){
  string res="";
  sort(arr.begin(),arr.end());
  string first=arr[0];
  string last=arr[n-1];
  for(int i=0;i<first.size();i++)
  {
    if(first[i]!=last[i]) break;
    res+=first[i];
  }
  if(res.size()==0) return to_string(-1);
  else return res;
}

//Isomerphic Strings (Ques 115)
bool areIsomorphic(string &str1, string &str2)
{
    int l1=str1.size();
    int l2=str2.size();
    if(l1!=l2) return false;
    int m1[256]={0};
    int m2[256]={0};
    for(int i=0;i<l1;i++)
    {
        if(!m1[str1[i]] and !m2[str2[i]])
        {
            m1[str1[i]]=str2[i];
            m2[str2[i]]=str1[i];
        }
        else if(m1[str1[i]]!=str2[i]) return false;
    }
    return true;
}

//Check whether one String is rotation of other (Ques 116)
int isCyclicRotation(string &p, string &q) 
{
    return p.length() == q.length() && (p+p).find(q) != string::npos;
} 

//Check if two strings are anagram of each other (Ques 117)
bool areKAnagrams(string str1, string str2, int k) {
        // code here
        int n1=str1.size();
        int n2=str2.size();
        
        if(n1!=n2) return false;
        map<char,int> mp;
        int cnt=0;
        for(int i=0;i<n1;i++)
        {
            mp[str1[i]]++;
        }
        for(int i=0;i<n2;i++)
        {
            if(mp[str2[i]]>0) {
                mp[str2[i]]--;
            }
            else cnt++;
        }
        return (cnt<=k)?true:false;
    }


int main()
{
    return 0;
}