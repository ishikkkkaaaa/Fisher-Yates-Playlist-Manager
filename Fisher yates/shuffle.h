class Solution
{
private
    int[] nums; // array to be shuffled
private
    Random random; // random number generator

public
    Solution(int[] nums) // constructor
    {
        this.nums = nums;           // initialize the array
        this.random = new Random(); // initialize the random number generator
    }
public
    int[] reset() // reset the array to its original configuration and return it.
    {
        return nums;
    }
public
    int[] shuffle() // shuffle the array and return it.
    {
        int[] copy = nums.clone();               // clone the array
        for (int i = nums.legth - 1; i > 0; i--) // loop from the last element to the first
        {
            int j = random.nextInt(i + 1); // generate a random number from 0 to i
            //swap(copy,i,j); // swap the elements
            int t = copy[i];
            copy[i] = copy[j];
            copy[j] = t;
        }
        return copy;
    }
};