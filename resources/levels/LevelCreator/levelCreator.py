from PIL import Image
from random import randrange

im = Image.open("newLevel.png") #Can be many different formats.
pix = im.load()


# Read from Image
# Asteroids, 22 (RGB: 155 173 163) light Grey
# Scout    , 27 (RGB: 172 50 50)   Red

Obstacles = []
Enemies = []

w, h = im.size #Get the width and hight of the image for iterating over
for y in range(0, h):
	for x in range(0, w):
		if pix[x, y] == 22 :
			Obstacles.append([x / 10.0, 32 * abs(y - h + 1)]);
		elif pix[x, y] == 27 :
			Enemies.append([x / 10.0, 32 * abs(y - h + 1)]);

# write to new newLevel.yaml
file = open("newLevel.yaml", "w")

# Add background info
file.write("background:\n   file: bg.png\n   scroll_speed: 30.0\n");

# Add ScrollSpeed (What?)
file.write("scroll_speed: 50.0\n");

# Add Boss
file.write("boss:\n   type: big_asteroid\n");

# Add Obstacles header
file.write("obstacles:\n");

for pos in Obstacles:
	file.write("   - type: asteroid\n");	
	file.write("     level_offset: " + str(round(pos[1], 2)) + "\n");
 	file.write("     start_x_pos: " + str(pos[0]) + "\n");
 	file.write("     rotation: " + str(50 - randrange(100)) + "\n");
 	file.write("     speed: [0.0, 50.0]\n");

# Add Obstacles header
file.write("enemies:\n");

for pos in Enemies:
	file.write("   - type: scout\n");	
	file.write("     ai: shoot_at_player\n");
	file.write("     level_offset: " + str(round(pos[1], 2)) + "\n");
 	file.write("     start_x_pos: " + str(pos[0]) + "\n");
 	file.write("     speed: [0.0, 50.0]\n");

file.close()
