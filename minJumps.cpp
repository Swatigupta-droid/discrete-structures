// Given an array of N integers arr[] where each element represents the max length of the jump that can be made forward from that element.Find the minimum number of jumps to reach the end of the array(starting from the first element).If an element is 0, then you cannot move through that element.

#include <iostream>

using namespace std;

int minJumps(int arr[], int n)
{
  if (n <= 1)
    return 0;

  if (arr[0] == 0)
    return -1;

  int jump = 1;

  int subArrEndIndex = arr[0];

  int i = 1;

  int subArrFistHalfMaxSteps = 0;

  int subArrSecondHalfMaxSteps = 0;

  // Start traversing array
  for (i = 1; i < n;)
  {

    subArrEndIndex = i + subArrEndIndex;

    if (subArrEndIndex >= n)
      return jump;

    int firstHalfMaxStepIndex = 0;

    for (; i < subArrEndIndex; i++)
    {
      int stepsCanCover = arr[i] + i;
      if (subArrFistHalfMaxSteps < stepsCanCover)
      {
        subArrFistHalfMaxSteps = stepsCanCover;
        subArrSecondHalfMaxSteps = 0;
        firstHalfMaxStepIndex = i;
      }
      else if (subArrSecondHalfMaxSteps < stepsCanCover)
      {
        subArrSecondHalfMaxSteps = stepsCanCover;
      }
    }
    if (i > subArrFistHalfMaxSteps)
      return -1;
    jump++;

    subArrEndIndex = arr[firstHalfMaxStepIndex];
    subArrFistHalfMaxSteps = subArrSecondHalfMaxSteps;
  }

  return -1;
}

// Driver program to test above function
int main()
{
  int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
  int size = sizeof(arr) / sizeof(int);

  cout << ("Minimum number of jumps to reach end is %d ",
           minJumps(arr, size));
  return 0;
}