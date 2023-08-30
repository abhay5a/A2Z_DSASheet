#include<bits/stdc++.h>
using namespace std;

//Remove Outermost Paranthesis (Ques 111)

    string removeOuterParentheses(string S) {
        string res; //Ek res string leli h jisme store krenge answer ko
        int opened = 0; //Ye isilie lia h jisse ye dekh ske ki outside paranthesis available h ya nii
        for (char c : S) { //Loop chalaya S me c se 
            if (c == '(' && opened++ > 0) res += c; //check kro ki kya c ( h..agr h and opened ko ek bdhakr check kro ki kya vo 0 se bda h..agr dono h to res me vo character daaldo..varna rhne do..bcoz phir vo open ya closing paranthesis me aa jaega 
            if (c == ')' && opened-- > 1) res += c;//same cheez yha ki h..check kia h aur phir opened ko dekha h ki kya vo 1 se bda h ki chota//agr  bda h to character to res me daaldo.
        }
        return res; //res to return krado
    }

//Reverse words in a given string/Palindrome check (Ques 112)

string reverseWords(string s) {
    int n=s.size();  
  int i=0;
  int l=0,r=0; //Ye two pointer approach h..jisme humne ek l lia h aur ek r lia h
  reverse(s.begin(),s.end()); //sbse pehle poori string ko reverse krdo..
  while(i<n) // phir loop chalao aur i ko dekhte chalo
  {
    while(i<n && s[i]!=' ') //jha bhi s[i] space mil jae..vhi pr i ko rokdo aur r me i ko daldo..
    {
      s[r++]=s[i++];
    }
    if(l<r)//ab jha bhi ruke ho r ko lekr vha tk l se jo ki abhi kisi word ke starting me hoga..
    {
      reverse(s.begin()+l,s.begin()+r);//l se lekr r-1 tk poora reverse krdo
      s[r]=' ';//ab jha bhi r h vha pr ek space dedo..bcoz agr ek se jyada space hui to ek hi space rhe..
      r++;//ab r ko aage bdha do
      l=r;//aur l ko next word ki starting me le aao
    }
    i++;//i ko bdhate rho jisse vo check krta rhe..ki space kha kha h string me
  }
  string str=s.substr(0,r-1); //jb poora string bnkr aaega to usme ek space last me bachi rhegi to usko htane ke lie..0 se r-1 tk substring lelo..
  return str;
}

//Largest odd number in a string (Ques 113)

string largestOddNumber(string num) { //odd number 2 se divisible nii hota h
    for (int i = num.size() - 1; i >= 0; --i) //yha string ke peeche se loop chala dia h..jisse last to last character check krte jae..
        if ((num[i] - '0') % 2)//character ko uski ASCII value se check kia kya vo 2 se divisible h..agr h to poora string Odd hoga
            return num.substr(0, i + 1); 
    return string();//varna ek khali string return krdo
}

//Longest common prefix (Ques 114)

string commonPrefix(vector<string>& arr,int n){
  string res=""; //ek khali string leli
  sort(arr.begin(),arr.end()); //pehle saare strings ko sort kia increasing order me
  string first=arr[0]; //first vali ko uthaya jo ki sbse choti h
  string last=arr[n-1]; //last vali ko uthaya jo ki sbse bdi h
  for(int i=0;i<first.size();i++)
  {
    if(first[i]!=last[i]) break; //ab character to character compare kia..jbtk koi bhi character alg na mil jae..jaise hi mile loop se bahar aa jao
    res+=first[i];//jo bhi character same mile usko ek string me daaldo
  }
  if(res.size()==0) return to_string(-1);//agr string khali hi rh jae..to -1 return krdo
  else return res;//varna string return krdo
}

//Isomerphic Strings (Ques 115)

bool areIsomorphic(string &str1, string &str2)
{
    int l1=str1.size();
    int l2=str2.size();
    if(l1!=l2) return false; //agr length same nii hogi to isomorphic to nii ho skti
    int m1[256]={0}; //ek frequency array lia h jo str1 ke character ko str2 ke characters se map krne me help krega
    int m2[256]={0};//ye vala str2 ke character ko str1 ke character se map krne me help krega
    for(int i=0;i<l1;i++)
    {
        if(!m1[str1[i]] and !m2[str2[i]]) //agr m1 me str1[i] nii h to aur m2 me str2[i] nii h
        {
            m1[str1[i]]=str2[i];//to str1[i] ke indexing pr str2[i] ko daaldo
            m2[str2[i]]=str1[i];//same here
        }
        else if(m1[str1[i]]!=str2[i]) return false; //varna agr pehle se tha str1[i] to usko dekho ki kya vha pr str2[i] h..agr nii h to false return krdo
    }
    return true;//varna true return krdo
}

//Check whether one String is rotation of other (Ques 116)

int isCyclicRotation(string &p, string &q) 
{
    return p.length() == q.length() && (p+p).find(q) != string::npos; //isme sbse pehle to ye check kia ki length dono ki same ho..uske baad ye check krenge ki agr me p ko p se add krke usme q ko dhoondhu..agr q mil jaata h to shi h aur agr q nii milta h string::npos tk mtlb jbtk string khtm na jae..mtlb q ko dhoondhte hue end tk na jaana pde..to return true hoga..varna agr koi bhi ek condition false hui to false return hoga.
} 

//Check if two strings are anagram of each other (Ques 117)

bool areKAnagrams(string str1, string str2, int k) { //Anagram mtlb characters ko alg alg jgah pr rkhkr jo string bne
        // code here
        int n1=str1.size();
        int n2=str2.size();
        
        if(n1!=n2) return false;
        map<char,int> mp; //ek map ke lia h..jisse check krunga ki konsa character kitni baar aaya h
        int cnt=0;
        for(int i=0;i<n1;i++)
        {
            mp[str1[i]]++; //pehle jha jha character tha vha pr usko 1 add krdia
        }
        for(int i=0;i<n2;i++)
        {
            if(mp[str2[i]]>0) {//ab jha jha same character mila vha pr 1 subtract krdia
                mp[str2[i]]--;
            }
            else cnt++; 
        }
        return (cnt<=k)?true:false; //ab check krlo 
    }

//Sort Characters by Frequency (Ques 118)

string sortByFrequency(int n, string& s)
{
    unordered_map<char,int> mp;
    priority_queue<pair<int,char>> pq;
    string res="";
    for(char c:s)
    {
        mp[c]++;
    }
    for(auto it:mp)
    {
        pq.push({it.second,it.first});
    }
    while(!pq.empty())
    {
        auto temp=pq.top();
        int freq=temp.first;
        char c=temp.second;
        res+=string(freq,c);
        pq.pop();
    }
    return res;
}

//Maximum Nesting Depth of Paranthesis (Ques 119)

 int maxDepth(string s) {
    int ans=0;
  int maxans = INT_MIN;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='(')
    ans++;
    else if(s[i]==')')
    ans--;

    maxans= max(ans,maxans);
  }
  return maxans; 
    }

//Roman Number to Integer and vice versa (Ques 120)

  int romanToInt(string s) {
        map<char,int> mp;
        mp.insert(make_pair('I',1));
        mp.insert(make_pair('V',5));
        mp.insert(make_pair('X',10));
        mp.insert(make_pair('L',50));
        mp.insert(make_pair('C',100));
        mp.insert(make_pair('D',500));
        mp.insert(make_pair('M',1000));
        int len=s.size(),num,sum=0;
        for(int i=0;i<len;)
        {
            if(i==(len-1) or mp[s[i]]>=mp[s[i+1]])
            {
                num=mp[s[i]]; 
                i++;
            }
            else {
                num=mp[s[i+1]]-mp[s[i]];
                i=i+2;
            }
            sum+=num;
        }
        return sum;
    }
    
//Implement Atoi (Ques 121)

int myAtoi(string s) {
    string str=s;
    int sign = 1, base = 0, i = 0;
 
    // if whitespaces then ignore.
    while (str[i] == ' ') {
        i++;
    }

     if (str[i] == '-' || str[i] == '+') {
        sign = 1 - 2 * (str[i++] == '-');
    }
 
    // checking for valid input
    while (str[i] >= '0' && str[i] <= '9') {
        // handling overflow test case
        if (base > INT_MAX / 10
            || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }
        base = 10 * base + (str[i++] - '0');
    }
    return base * sign;
    }

//Count No. of Substrings (Ques 122)

int countSubStrings(string str, int k) 
{
    // Write your code here.
    int n = str.length();
 
    // Initialize result
    int res = 0;
 
    // To store count of characters from 'a' to 'z'
    int cnt[26];
 
    // Consider all substrings beginning with
    // str[i]
    for (int i = 0; i < n; i++)
    {
        int dist_count = 0;
 
        // Initializing array with 0
        memset(cnt, 0, sizeof(cnt));
 
        // Consider all substrings between str[i..j]
        for (int j=i; j<n; j++)
        {
            // If this is a new character for this
            // substring, increment dist_count.
            if (cnt[str[j] - 'a'] == 0)
                dist_count++;
 
            // Increment count of current character
            cnt[str[j] - 'a']++;
 
            // If distinct character count becomes k,
            // then increment result.
            if (dist_count == k)
                res++;
            if(dist_count > k) break;
        }
    }
    return res;
}

//Longest Palindromic Substring[Without DP] (Ques 123)

bool check(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        vector<string> substring;
        for(int i=0; i<n; i++){
            string temp = "";
            for(int j=i; j<n; j++){
                temp += s[j];
                substring.push_back(temp);
            }
        }
        int max_len = 0;
        string finalans = substring[0];
        int m = substring.size();
        for(int i=0; i<m; i++){
            int s = substring[i].size();
            if(check(substring[i], 0, s-1)){
                if(s > max_len){
                    max_len = s;
                    finalans = substring[i];
                }
            }       
        }
        return finalans;
    }

//Reverse Every Word in a string (Ques 125)

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


int main()
{
    return 0;
}