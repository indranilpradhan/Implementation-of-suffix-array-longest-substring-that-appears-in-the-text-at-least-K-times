#include <bits/stdc++.h>
#include <string.h>
#include <iostream> 
using namespace std;
#define ll long long int

struct suffix
{
 	ll index;
 	ll sortindex;
 	ll asciival;
 	string suf;
 	pair<ll,ll> p;
};

bool comp(suffix a, suffix b)
{
	if(a.p.first != b.p.first)
		return a.p.first < b.p.first;
	else
		return a.p.second < b.p.second;
}

void suffixarray(string st,ll m)
{
	//cout<<"here"<<st<<endl;
	//ll length = st.length();
	//st = st+st;
	ll len = st.length();
	suffix s[len];
	for(ll i=0; i<len;i++)
	{
		s[i].index = i;
		s[i].suf = st.substr(i, len-i);
		s[i].asciival = st.at(i)-'a';
		s[i].sortindex = i;
	}
	for(ll i=0; i<len;i++)
	{
		if(i==len-1)
		{
			s[i].p.first = s[i].asciival;
			s[i].p.second = -1;	
		}
		else
		{
			s[i].p.first = s[i].asciival;
			s[i].p.second = s[i+1].asciival;
		}
	}
	// for(ll i=0; i<len;i++)
	// {
	// //	cout<<s[i].suf<<" "<<s[i].index<<" "<<s[i].p.first<<" "<<s[i].p.second<<endl;
	// }
//	cout<<"==================================="<<endl;
	ll loopcount = (ll)log2((double)len);
	ll k = 1;
	ll indexarr[len];
	while(loopcount>0)
	{
		sort(s, s+len, comp);
	// 	for(ll i=0; i<len;i++)
	// 	{
	// //		cout<<s[i].suf<<" "<<s[i].index<<" "<<s[i].p.first<<" "<<s[i].p.second<<endl;
	// 	}
	//	cout<<"==================================="<<endl;
		int rank=0;
		for(ll i=0; i < len; i++)
		{
			if(i == 0)
			{
			//	cout<<s[i].suf<<" "<<rank<<" "<<s[i].p.first<<" "<<s[i].p.second<<endl;
				indexarr[s[i].index] = rank;
			}
			else
			{
				if(s[i].p.first == s[i-1].p.first && s[i].p.second == s[i-1].p.second)
				{
			//		cout<<s[i].suf<<" "<<rank<<" "<<s[i].p.first<<" "<<s[i].p.second<<endl;
					indexarr[s[i].index] = rank;
				}
				else
				{
			//		cout<<"here"<<endl;
					rank++;
			//		cout<<s[i].suf<<" "<<rank<<" "<<s[i].p.first<<" "<<s[i].p.second<<endl;
					indexarr[s[i].index] = rank;
				}
			}
		}
	//	cout<<"==================================="<<endl;
	// 	for(ll i=0; i<len;i++)
	// 	{
	// //		cout<<s[i].suf<<" index "<<s[i].index<<" rank "<<indexarr[s[i].index]<<" first "<<s[i].p.first<<" second "<<s[i].p.second<<endl;
	// 	}
	//	cout<<"======================"<<endl;
		ll next = pow(2,k);
		//cout<<next<<endl;
	// 	for(ll i=0; i<len;i++)
	// 	{
	// //		cout<<i<<" "<<indexarr[i]<<endl;
	// 	}
	//	cout<<"======================"<<endl;
		for(ll i=0;i<len;i++)
		{
			if(s[i].index+next >= len)
			{
				s[i].p.first = indexarr[s[i].index];
				s[i].p.second = -1;
			}
			else
			{
				s[i].p.first = indexarr[s[i].index];
				s[i].p.second = indexarr[s[i].index+next];
			}
		}
	// 	for(ll i=0; i<len;i++)
	// 	{
	// //		cout<<s[i].suf<<" "<<s[i].index<<" "<<s[i].p.first<<" "<<s[i].p.second<<endl;
	// 	}
	//	cout<<"======================"<<endl;
		loopcount--;
		k++;
	}
	//cout<<len<<endl;
// 	for(ll i=0; i<len;i++)
// 	{
// //		cout<<s[i].suf<<" "<<s[i].index<<endl;
// 	}

 //    for(ll i=0; i<len;i++)
	// {
	//  	cout<<s[i].suf<<" "<<s[i].index<<" "<<endl;
	// }

	ll slen=0;
	string str;
	for(ll i=0; i<len;i++)
	{
	//	cout<<"ehre"<<endl;
		string temp = s[i].suf;
	//	cout<<"temp "<<temp<<endl;
		ll tlen = s[i].suf.length();
		ll count = 1;
		for(ll j = 0; j<len;j++)
		{
			if( j == i)
				continue;
			else
			{
				ll tlen2 = s[j].suf.length();
				if(tlen <= tlen2)
				{
					string temp2 = s[j].suf.substr(0,tlen);
					if(strcmp(temp.c_str(), temp2.c_str()) == 0)
					{
				//		cout<<"temp2 "<<temp2<<endl;
						count++;
					}
				}
			}
		}
		if(count >= m && slen < tlen)
		{
			str = s[i].suf;
			slen  = tlen;
		}
	}

	if(m==1)
		cout<<st<<endl;
	else
		cout<<str<<endl;
}

int main()
{
	ll n;
	cin>>n;
	ll k;
	cin>>k;
	string st;
	cin>>st;
	if(n != st.length())
	{
		cout<<"Length mismatch"<<endl;
	}
	else
		suffixarray(st,k);
	return 0;
}
