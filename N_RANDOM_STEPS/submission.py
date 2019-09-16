#!/usr/bin/env python

import random
from math import sqrt

import numpy

trials = 1000
steps = 100

# right, up, left, down
move_x = [1.0, 0.0, -1.0,  0.0]
move_y = [0.0, 1.0,  0.0, -1.0]

distance_sum = 0.0
for trial in range(trials):
    # problem did not specified if we continued from last point,
    # or if we start from 0,0 on every trial. So I'll assume
    # I will always start from the origin on every new trial
    x_location = 0.0
    y_location = 0.0
    for step in range(steps):
        direction = random.randint(0, 3)
        x_location = (x_location + move_x[direction])
        y_location = (y_location + move_y[direction])
    distance_sum = (distance_sum + sqrt((x_location * x_location) + (y_location * y_location)))

# get average distance
distance_sum = (distance_sum / (trials * 1.0))

print(distance_sum)

