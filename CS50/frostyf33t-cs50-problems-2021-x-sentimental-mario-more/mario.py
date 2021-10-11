import cs50


# create base value for the floors
floors = 0

# creates loop do make sure number of floors between 1 and 8
while True:
    floors = cs50.get_int("Height:  ")
    if (floors > 0) and (floors < 9):
        break

# symbols used in print statement
spaces = " "
stair = "#"

# loop creating pyraminds
for i in range(1, (floors + 1)):
    print(((spaces * (floors - i)) + (i * stair)+(spaces * 2) + (i * stair)))

