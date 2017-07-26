#include<bits/stdc++.h>
using namespace std ;
class generate_array{
	public:
		static void space_separated(int n )
		{
			int i ;
			for(i=1;i<=n;i++)
			{
				printf("%d ",rand());
			}
			printf("\n");
		}
		static void new_line(int n )
		{
			int i ;
			for(i=1;i<=n;i++)
			{
				printf("%d\n",rand());
			}
		}
		static void distint_space_separated(int n , int l , int r)
		{
			set< int >s ;
			while(1)
			{
				int ele = l+ rand()%(r-l+1);
				if(s.find(ele)!=s.end())
				{
					continue ;
				}
				else
				{
					s.insert( ele );
				}
				if(s.size()==n)
					break;
			}
			for(set<int>::iterator it = s.begin();it!=s.end();it++)
			{
				printf("%d ",*it);
			}
			printf("\n");

		}
		static void range_space_separated(int n , int l , int r)
		{
			int i ;
			int arr[ n+2 ] = {0} ;
			for(i=1;i<=n;i++)
			{
				int ele = l + rand()%(r-l+1);
				arr[i] = ele ;
				printf("%d ",ele);
			}
			printf("\n");

			// ---------------------------------------- validating code 
			for(i=1;i<=n;i++)
			{
				assert(arr[i] >=l && arr[i]<=r);
			}
			//-----------------------------------------
		}
		static void range_space_separated(int n , int x )
		{
			int i ;
			int arr[ n+2 ] = {0} ;
			for(i=1;i<=n;i++)
			{
				int ele =  rand()%(x) + 1;
				arr[i] = ele ;
				printf("%d ",ele);
			}
			printf("\n");

			// ---------------------------------------- validating code 
			for(i=1;i<=n;i++)
			{
				assert(arr[i]<=x);
			}
			//-----------------------------------------
		}


};
