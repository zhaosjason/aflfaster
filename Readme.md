#AFLFast
Power schedules implemented by Marcel Böhme \<marcel.boehme@acm.org\>. 
AFLFast is an extension of AFL which is written and maintained by 
Michal Zalewski \<lcamtuf@google.com\>.

AFLFast is a fork of AFL that has been shown to outperform AFL by an **order of magnitude**! It helped in the success of Team Codejitsu at the finals of the DARPA Cyber Grand Challenge where their bot Galactica took **2nd place** in terms of #POVs proven (see red bar at https://www.cybergrandchallenge.com/event#results). AFLFast exposed several previously unreported CVEs that could not be exposed by AFL in 24 hours and otherwise exposed vulnerabilities significantly faster than AFL while generating orders of magnitude more unique crashes. 

Essentially, we observed that most generated inputs exercise the same few “high-frequency” paths and developed strategies to explore significantly more paths with the same number of inputs by gravitating towards low-frequency paths. We implemented several *power schedules* that decide how long a seed should be fuzzed and *search strategies* that decide in which order the seeds should be fuzzed. Technically, we modified the computation of a seed's performance score, which seed is marked as favourite, and which seed is chosen next from the circular queue. We implemented the following schedules (in the order of their effectiveness, best first):

| AFL flag | Power Schedule             | 
| ------------- | -------------------------- |
| `-p fast` | ![FAST](http://latex.codecogs.com/gif.latex?p(i)=\\min\\left(\\frac{\\alpha(i)}{\\beta}\\cdot\\frac{2^{s(i)}}{f(i)},M\\right))  |
| `-p coe` | ![COE](http://latex.codecogs.com/gif.latex?p%28i%29%3D%5Cbegin%7Bcases%7D%200%20%26%20%5Ctext%7B%20if%20%7D%20f%28i%29%20%3E%20%5Cmu%5C%5C%20%5Cmin%5Cleft%28%5Cfrac%7B%5Calpha%28i%29%7D%7B%5Cbeta%7D%5Ccdot%202%5E%7Bs%28i%29%7D%2C%20M%5Cright%29%20%26%20%5Ctext%7B%20otherwise.%7D%20%5Cend%7Bcases%7D) |
| `-p explore` | ![EXPLORE](http://latex.codecogs.com/gif.latex?p%28i%29%3D%5Cfrac%7B%5Calpha%28i%29%7D%7B%5Cbeta%7D) |
| `-p quad` | ![QUAD](http://latex.codecogs.com/gif.latex?p%28i%29%20%3D%20%5Cmin%5Cleft%28%5Cfrac%7B%5Calpha%28i%29%7D%7B%5Cbeta%7D%5Ccdot%5Cfrac%7Bs%28i%29%5E2%7D%7Bf%28i%29%7D%2CM%5Cright%29) |
| `-p lin` | ![LIN](http://latex.codecogs.com/gif.latex?p%28i%29%20%3D%20%5Cmin%5Cleft%28%5Cfrac%7B%5Calpha%28i%29%7D%7B%5Cbeta%7D%5Ccdot%5Cfrac%7Bs%28i%29%7D%7Bf%28i%29%7D%2CM%5Cright%29) |
| `-p exploit` | ![LIN](http://latex.codecogs.com/gif.latex?p%28i%29%20%3D%20%5Calpha%28i%29) |
where *α(i)* is the performance score that AFL uses to compute for the seed input *i*, *β(i)>1* is a constant, *s(i)* is the number of times that seed *i* has been chosen from the queue, *f(i)* is the number of generated inputs that exercise the same path as seed *i*, and *μ* is the average number of generated inputs exercising a path.
  
More details can be found in our paper that was recently accepted at the [23rd ACM Conference on Computer and Communications Security (CCS'16)](https://www.sigsac.org/ccs/CCS2016/accepted-papers/).

Copyright 2013, 2014, 2015, 2016 Google Inc. All rights reserved.
Released under terms and conditions of Apache License, Version 2.0.
