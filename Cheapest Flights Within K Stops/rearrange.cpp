#include<iostream>
#include<vector>
using namespace std;

int count_rearrange(vector<int>&arr,int n){
    //Sorting the array for further implementation:
    sort(arr.begin(),arr.end());

    //assigning the two pointers left and right:
    int left=0;
    //Assigning the right pointer, pointing to the element which is just greater than the element at left using the upper_bound function.
    int right=upper_bound(arr.begin(),arr.end(),arr[left])-arr.begin();

    //Initialising the count variable which will count the greater elements and returns the answer:
    int count=0;

    //Now counting the elements that are greater than the elements at the left:
    if(right>=n){
        return count;
    }
    while(right<n){
        if(arr[right]>arr[left]){
            count++;
            left++;
        }
        right++;
    }

    //Returning the answer:
    return count;
}
 
int main(){
    //Taking the size of array from user:
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    //Taking array from the user :
    vector<int>arr(n);
    cout<<"Enter the array : "<<endl;
    for(int i=0;i<n;i++){
        int inp;
        cin>>inp;
        arr[i]=inp;
    }

    int ans=count_rearrange(arr,n);

    cout<<"The maximum possible greatness which can be achieved by rearrangement is : "<<ans<<endl;

return 0;
}