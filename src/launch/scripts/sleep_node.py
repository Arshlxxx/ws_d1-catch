#!/usr/bin/env python

import rospy
import time

if __name__ == "__main__":
    rospy.init_node('sleep_node')
    duration = rospy.get_param('~duration', 10)  # 默认等待5秒
    rospy.loginfo(f"Sleeping for {duration} seconds...")
    time.sleep(duration)
    rospy.loginfo("Sleep finished.")
