#!/usr/bin/env python
import time
from flyt_python import api
drone = api.navigation(timeout=120000) # instance of flyt droneigation class
# at least 3sec sleep time for the drone interface to initialize properly
time.sleep(3)
print ' drone taking off at hight of 10 m at oringin point A of triangle ABC'
drone.take_off(10.0)
print ' moving towards point B at side length of 10 m of triangle ABC'
drone.position_set(8, 6, 0, relative=True)
print ' moving towards point c at side length of 10 m of triangle ABC'
drone.position_set(-8, 6, 0, relative=True)
print ' moving towards origin point A at side length of 10 m of triangle ABC'
drone.position_set(0, -10, 0, relative=True)
print 'Landing'
drone.land(async=False)
# shutdown the instance
drone.disconnect()
