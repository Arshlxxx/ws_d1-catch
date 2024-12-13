import math

# 输入的关节位置（以弧度表示）

joint_positions_radians = [5.069390981285612e-05, 0.15702451616864546, -0.6396740030820319, -4.101991978598407e-05, 0.4825154594005756, 2.245114689663003e-05]

# 转换弧度到角度
joint_positions_degrees = [math.degrees(radian) for radian in joint_positions_radians]

print("Joint positions in degrees:", joint_positions_degrees)
