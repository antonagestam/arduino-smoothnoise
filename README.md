# arduino-smoothnoise

Generates random values and then generates interpolated values 
between them using a cubic curve.

```c++
#include "SmoothNoise.h"

int steps = 50; // number of interpolated values
SmoothNoise n = SmoothNoise(steps);

println(n.next());
```
