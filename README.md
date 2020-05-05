# ray_caster

A 3D first-person labyrinth game using [ray-casting](https://en.wikipedia.org/wiki/Ray_casting). (macOS)

![Image description](https://i.ibb.co/s674nbx/screen.png)

## Usage

```bash
make

# choose a map as argument
./ray_caster maps/map
```

### Options

- --save : save a screenshoot of the first rendering of the game at the root of the program

```bash
./ray_caster maps/map --save
```

## Map Configuration

![Image description](https://i.ibb.co/HBm9nGM/map.png)

- SO : Texture of the south walls.
- EA : Texture of the east walls.
- NO : Texture of the north walls.
- WE : Texture of the west walls.
- S : Texture of sprite object.
- F : Texture of floor.
- C : Texture of ceiling.
- R : Screen resolution.
- Map

## Ray Casting

![Recordit GIF](https://upload.wikimedia.org/wikipedia/commons/e/e7/Simple_raycasting_with_fisheye_correction.gif)

Ray casting is a rendering technique used in computer graphics and computational geometry. It is capable of creating a three-dimensional perspective in a two-dimensional map. Developed by scientists at the Mathematical Applications Group in the 1960s, it is considered one of the most basic graphics-rendering algorithms.
