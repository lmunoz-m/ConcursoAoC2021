## Day 2: Dive! [https://adventofcode.com/2021/day/1](https://adventofcode.com/2021/day/1)

Now, you need to figure out how to pilot this thing.

## Part One
It seems like the submarine can take a series of commands like <code>forward 1</code>, <code>down 2 </code>, or <code>up 3</code>:

forward X increases the horizontal position by X units.
down X increases the depth by X units.
up X decreases the depth by X units.
Note that since you're on a submarine, down and up affect your depth, and so they have the opposite result of what you might expect.

The submarine seems to already have a planned course (your puzzle input). You should probably figure out where it's going. For example:

	forward 5
	down 5
	forward 8
	up 3
	down 8
	forward 2

Your horizontal position and depth both start at 0. The steps above would then modify them as follows:

<code>forward 5 </code> adds 5 to your horizontal position, a total of 5.
<code>down 5 </code> adds 5 to your depth, resulting in a value of 5.
<code>forward 8 </code> adds 8 to your horizontal position, a total of 13.
<code>up 3 </code> decreases your depth by 3, resulting in a value of 2.
<code>down 8 </code> adds 8 to your depth, resulting in a value of 10.
<code>forward 2 </code> adds 2 to your horizontal position, a total of 15.

After following these instructions, you would have a horizontal position of 15 and a depth of 10. (Multiplying these together produces 150.)

Calculate the horizontal position and depth you would have after following the planned course. 

#### What do you get if you multiply your final horizontal position by your final depth?

	199
	200
	208
	210
	200
	207
	240
	269
	260
	263


This report indicates that, scanning outward from the submarine, the sonar sweep found depths of <code>199</code>, <code>200</code>, <code>208</code>, <code>210</code>, and so on.

The first order of business is to figure out how quickly the depth increases, just so you know what you're dealing with - you never know if the keys will get carried into deeper water by an ocean current or a fish or something.

To do this, count <em>the number of times a depth measurement increases</em> from the previous measurement. (There is no measurement before the first measurement.) In the example above, the changes are as follows:


	199 (N/A - no previous measurement)
	200 (increased)
	208 (increased)
	210 (increased)
	200 (decreased)
	207 (increased)
	240 (increased)
	269 (increased)
	260 (decreased)
	263 (increased)

In this example, there are <code>7</code> measurements that are larger than the previous measurement.

#### How many measurements are larger than the previous measurement?


## Part Two
Considering every single measurement isn't as useful as you expected: there's just too much noise in the data.

Instead, consider sums of a <em>three-measurement sliding window</em>.  Again considering the above example:

	199  A      
	200  A B    
	208  A B C  
	210    B C D
	200  E   C D
	207  E F   D
	240  E F G  
	269    F G H
	260      G H
	263        H

Start by comparing the first and second three-measurement windows. The measurements in the first window are marked <code>A</code> (<code>199</code>, <code>200</code>, <code>208</code>); their sum is <code>199 + 200 + 208 = 607</code>. The second window is marked <code>B</code> (<code>200</code>, <code>208</code>, <code>210</code>); its sum is <code>618</code>. The sum of measurements in the second window is larger than the sum of the first, so this first comparison <em>increased</em>.

Your goal now is to count <em>the number of times the sum of measurements in this sliding window increases</em> from the previous sum. So, compare <code>A</code> with <code>B</code>, then compare <code>B</code> with <code>C</code>, then <code>C</code> with <code>D</code>, and so on. Stop when there aren't enough measurements left to create a new three-measurement sum.

In the above example, the sum of each three-measurement window is as follows:

	A: 607 (N/A - no previous sum)
	B: 618 (increased)
	C: 618 (no change)
	D: 617 (decreased)
	E: 647 (increased)
	F: 716 (increased)
	G: 769 (increased)
	H: 792 (increased)


In this example, there are <em><code>5</code></em> sums that are larger than the previous sum.

Consider sums of a three-measurement sliding window. 

#### How many sums are larger than the previous sum?
