/* Buy the ticket
You want to buy a ticket for a well-known concert which is happening in your city.
But the number of tickets available is limited. Hence the sponsors of the concert decided to sell tickets
to customers based on some priority.
A queue is maintained for buying the tickets and every person is attached with a priority
(an integer, 1 being the lowest priority).
The tickets are sold in the following manner -
1. The first person (pi) in the queue requests for the ticket.
2. If there is another person present in the queue who has higher priority than pi, 
then ask pi to move at end of the queue without giving him the ticket.
3. Otherwise, give him the ticket (and don't make him stand in queue again).
Giving a ticket to a person takes exactly 1 minute and it takes no time for removing and adding a person
to the queue. And you can assume that no new person joins the queue.
Given a list of priorities of N persons standing in the queue and the index of your priority
(indexing starts from 0). Find and return the time it will take until you get the ticket.
Input: 3
3 9 4
2
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

void buyTicket(int* arr, int n, int k){
	queue<int> q;
	int time = 0;
	priority_queue<int> pq;
	for(int i = 0; i < n; i++){
		pq.push(arr[i]);
		q.push(i);
	}
	while(1){
		if(arr[q.front()] == pq.top()){
			int ans = q.front();
			q.pop();
			pq.pop();
			time++;
			if(ans == k) break;
		}
		else if(arr[q.front()] < pq.top()){
			int ans = q.front();
			q.pop();
			q.push(ans);
		}
	}
	cout<<time;
}

int main(){
	int n, k;
	cout<<"Enter the size of an array: ";
	cin>>n;
	int* arr = new int[n];
	cout<<"Enter the elements: ";
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<"Enter the value of k: ";
	cin>>k;
	buyTicket(arr, n, k);
	return 0;
}