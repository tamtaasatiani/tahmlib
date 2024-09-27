# tahmlib
tahmlib is a simple C++ library for making video games.

tahmlib is inspired by Love2D, and is a bare-bones way of programming games: no fancy interface, no level editor. Just pick your favorite code editor and program away

Currently tested for Windows 10.

<br/>

## How to run
tahmlib was made with Visual Studio 2022. It uses the "Desktop Development with C++" module. Install those and run Visual Studio. Afterwards, click on "Clone a Repository". <br/>
![image](https://github.com/user-attachments/assets/6cb6219f-1023-4eef-953f-354b717218d2)


Copy the repository location and choose a desired path on your PC. <br/>
![image](https://github.com/user-attachments/assets/8d2f069d-c400-4b49-8b4f-1e57391fb934)<br/>


Click on "clone" and you're all set, **code away!**<br/>
note: MAKE SURE TO SET THE CONFIGURATION TO x86 IF IT'S NOT ALREADY SET TO THAT, AS TAHMLIB HAS ONLY BEEN SET UP FOR 32 BIT AT THE MOMENT

<br/>

## Required libraries
ALL of the required libraries are included in the source code, no need to download/set them up.
- [SDL](https://github.com/libsdl-org/SDL) : window management, rendering, input, audio.
- [SDL_ttf](https://github.com/libsdl-org/SDL_ttf) : font management.

<br/>

## Guidelines
- **DO NOT** edit any of the files included in the "tahm" subfolder, the engine.cpp, or the engine.h file
- **DO NOT** delete any of the functions included by default in the main.cpp file
- **DO** edit the contents of functions included in the main.cpp, or add your own
- **DO** add your own code files
- **IT IS RECOMMENDED** to put your additional code files into a separate folder. I put them in a folder called "src" and put it in the same folder as the "main.cpp" file

<br/>

## How to use
Open up the main.cpp file, you'll see this code

<br/>

```cpp
#include "engine.h"

void start()
{
	
}

void keypressed(Event event)
{
	
}

void update()
{

}

void draw()
{
	
}
```

<br/>

Inside the "start" function, call the "create" method to create a window of the desired title, width, and height.<br/>
note: the create method is optional. If it's not called, tahm will assign default values.

<br/>

```cpp
void start()
{
	tahm.window->create("Test", 1280, 720);
}
```

<br/>

If you run the code, you should see something like this.<br/>
![image](https://github.com/user-attachments/assets/cdab830d-0b18-4e6c-b047-633b14aecc7a)

<br/>

At the start of the file (outside of functions), create a Player struct with parameters x, y, width, and height, and a constructor to pass in those parameters.<br/>
Create a player object.<br/>
Then in the draw function, set the active color and call the "rect" method to draw a rectangle with the player parameters.

<br/>

```cpp
#include "engine.h"

struct Player
{
	Player (int x, int y, int width, int height)
	{
		this->x = x;
		this->y = y;

		this->width = width;
		this->height = height;
	}

	int x, y, width, height;
};

Player player(200, 200, 20, 20);

void draw()
{
	tahm.graphics->setColor(255, 255, 255);
	tahm.graphics->draw->rect(player.x, player.y, player.width, player.height);
}
```

<br/>

You should get something like:<br/>
![image](https://github.com/user-attachments/assets/c354bfb9-6e61-42d3-94cb-bd3fcb72e2a3)

<br/>

Almost there! Now just update the player x position whenever we press the D key.<br/>
```cpp
void update()
{
	if (tahm.input->keyPressed[KEYCODE_D])
	{
		player.x += 10;
	}
}
```
<br/>

**Done!** You just made your very first game in tahmlib.

<br/>

## Example projects
- [pong++](https://github.com/tamtaasatiani/pong-plusplus) : Atari's 1972 Pong clone.

<br/>



---

# Linux

## Pre-requisites

```bash
# Arch Linux
sudo pacman -S meson sdl2 sdl2_ttf base-devel
```

```bash
chmod +x run.sh
./run.sh
```