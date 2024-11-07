#include<iostream>
#include<algorithm>
using namespace std;

class Jobs
{

	public: int id;
	        int profit;
			int deadline;	
};

bool cmp(Jobs val1 , Jobs val2)
{
	return (val1.profit > val2.profit);
}

int solution(vector<Jobs>&arr , int n)
{
	sort(arr.begin() , arr.end() , cmp);
	
	int total = 0;
	int max_deadline = arr[0].deadline;
	
	for(int i=1; i<n; i++)
	{
		max_deadline = max(max_deadline , arr[i].deadline);
	}
	
	int hash[max_deadline + 1];
	
	for(int i=0; i<=max_deadline; i++)
	{
		hash[i] = -1;
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=arr[i].deadline; j>=1; j--)
		{
			if(hash[j] == -1)
			{
				hash[j] = arr[i].id;
				total += arr[i].profit;
				break;
			}
		}	
	} 
	
	return total;
}


int main()
{
	vector<Jobs> arr;
	
	cout<<"enter 5 jobs details"<<endl;
	for(int i=0; i<8; i++)
	{
		Jobs a;
		cout<<"enter id"<<endl;
		cin>>a.id;
		
		cout<<"enter profit"<<endl;
		cin>>a.profit;
		
		cout<<"enter deadline"<<endl;
		cin>>a.deadline;
		
		arr.push_back(a);
	}
	
	int ans = solution(arr , 8);
	
	cout<<"maximun profit is "<<ans<<endl;
	
	
	
	return 0;
}
