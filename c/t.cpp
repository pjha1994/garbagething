#include<iostream>
#include<vector>
using namespace std;
int gcd(int m, int n){ return n == 0 ? m : gcd(n, m%n); }
vector< vector<int> > getAllSubsets(vector<int> set)
{
    vector< vector<int> > subset;
    vector<int> empty;
    subset.push_back( empty );

    for (int i = 0; i < set.size(); i++)
    {
        vector< vector<int> > subsetTemp = subset;

        for (int j = 0; j < subsetTemp.size(); j++)
            subsetTemp[j].push_back( set[i] );

        for (int j = 0; j < subsetTemp.size(); j++)
            subset.push_back( subsetTemp[j] );
    }
    return subset;
}
int main()
{
vector <int> a;
int test_cases,n,x;
cout<<"ENter the number fo test cases\n";
cin>>test_cases;
  for(int i=0;i<test_cases;i++)
      {
       cin>>n;
         for(int j=0;j<n;j++)
            {cin>>x;a.push_back(x);}
       }
vector<vector<int>>x=getAllSubsets(a);
return 0;
}
