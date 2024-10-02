# 42 So Long Project

# mahmoud map
<p align="center">
  <img src="so_long1.jpg" alt="Libft Logo" style="max-width: 100%; height: auto;">
</p>

# snake map
<p align="center">
  <img src="so_long2.jpg" alt="Libft Logo" style="max-width: 100%; height: auto;">
</p>

## Project Overview

<p>
The **So Long** project is a graphical game developed using the MiniLibX library, aimed at mastering the fundamentals of 2D game development in C. The project requires creating a player character that navigates a predefined map, collecting items and avoiding obstacles, enhancing skills in graphics, input handling, and game logic.
</p>

## Features

<ul>
  <li>2D graphics rendering using the MiniLibX library.</li>
  <li>Player movement with keyboard controls.</li>
  <li>Map generation with collectibles and obstacles.</li>
  <li>Collision detection and game state management.</li>
</ul>

## Installation

<p>To install and run this project:</p>

<pre>
git clone https://github.com/your_username/so_long.git
cd so_long
make
</pre>

## Usage

<p>Here’s how to start the So Long game:</p>

<pre>
#include "so_long.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        ft_printf("Usage: ./so_long <map_file>\n");
        return (1);
    }
    start_game(argv[1]);
    return (0);
}
</pre>

## License

<p>This project is licensed under the MIT License.</p>

## Contact

<p>For any questions or collaborations, please reach out:</p>
<ul>
  <li>Email: your_email@example.com</li>
  <li>GitHub: <a href="https://github.com/your_username">your_username</a></li>
</ul>