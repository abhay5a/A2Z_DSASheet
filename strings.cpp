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


int main()
{
    return 0;
}