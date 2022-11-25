// x^(e) mod n = y
#include <bits/stdc++.h>
#include <sstream>
#define ll long long int
using namespace std;

ll power(ll, ll, ll);
string multiply(string, string);
ll mod(string, ll);
string LongToString(ll);

string xx, ress, temp;

// Driver Code
int main()
{
	ll n;
	string e, message;
	ll mtoi[100];

	cin>>n;
	cin>>e;
	cin>>message;
	
	for(int i=0;i<message.length();i++)
		mtoi[i] = message[i];
	
	ll remainderE = 0;
	
	// Reduce the number e to a small number
	// using Fermat Little
	for (int i = 0; i < e.length(); i++)
		remainderE = (remainderE * 10 +
					e[i] - '0') % (n - 1);

	for(int i = 0; i < message.length(); i++)
	{
		cout << power(mtoi[i], remainderE, n);
		if(i!=message.length()-1)
			cout << ",";
	}
	return 0;
}

// Function to find power
ll power(ll x, ll y, ll p)
{
	ll res = 1; // Initialize result
	// Update x if it is more than or
	// equal to p
	x = x % p;

	while (y > 0) {
		if(x>2147483647 || res>2147483647)
		{
			xx = LongToString(x);
			ress = LongToString(res);
			if (y & 1)
			res = mod(multiply(ress, xx), p);
			//res = (res * x) % p;

			// y must be even now
			y = y >> 1; // y = y/2
		
			x = mod(multiply(xx, xx), p);
			// If y is odd, multiply x
			// with the result
		}
		else
		{
			if (y & 1)
				res = (res * x) % p;

			// y must be even now
			y = y >> 1; // y = y/2
		
			x = (x * x) % p;
		}
	}
	return res;
}
string multiply(string nums1, string nums2) {
   int n = nums1.size();
   int m = nums2.size();
   string ans(n + m, '0');
   for(int i = n - 1; i>=0; i--){
      for(int j = m - 1; j >= 0; j--){
         int p = (nums1[i] - '0') * (nums2[j] - '0') + (ans[i + j + 1] - '0');
         ans[i+j+1] = p % 10 + '0';
         ans[i+j] += p / 10 ;
      }
   }
   for(int i = 0; i < m + n; i++){
      if(ans[i] !='0')
	  	return ans.substr(i);
   }
   return "0";
}

ll mod(string num, ll a)
{
    // Initialize result
    ll res = 0;
 	
    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + num[i] - '0') % a;
 
    return res;
}

string LongToString(ll long_num)
{
    stack<char> stringStack;
    string signValue = "";
  
    // if long number is negative store the negative sign to
    // the signValue variable
    if (long_num < 0) {
        signValue = "-";
        long_num = -long_num;
    }
  
    // while number is greate than 0, get last digit from it
    // and convert it to character by adding '0' to it, and
    // push to the stack.
    while (long_num > 0) {
        char convertedDigit = long_num % 10 + '0';
        stringStack.push(convertedDigit);
        long_num /= 10;
    }
  
    string long_to_string = "";
  
    // while stack is not empty pop the character one by one
    // and append to the resultant string.
    while (!stringStack.empty()) {
        long_to_string += stringStack.top();
        stringStack.pop();
    }
  
    // return the resulatant string value by appending
    // singValue to it.
    return signValue + long_to_string;
}

