from an array of integers, return a shuffled version of the array. [its design problem]
<br>
All permutation of the array should be equally likely as a result of the shuffling.

implementation of the <b>SOLUTION</b> class.

* <b> Solution(int[] nums) </b>: Its a constructor, which initializes the object with the integer array nums.
<br>
* <b> int[] shuffle() </b>: Returns a shuffled version of the array.
<br>
* <b> int[] reset() </b>: Resets the array to its original configuration and returns it.
<br>
* <b> int[] debug() </b>: Returns the current configuration of the array.
<br>

`Class Solution{
    Solution(Array input[]);
    Array shuffle();
    Array reset();
}`

<h3>In Fisher Yates Algorithm</h3>
We will be creating two arrays, one suffled and second unshuffled.