# GraphicsEngine
My exploration of creating my own graphics engine

## Pre-requisites

I am making this tutorial for Ubuntu machines, therefore the libraries will be installed via `apt`

#### Installing Dependencies
```
sudo apt update

sudo apt install -y cmake pkg-config
sudo apt install -y mesa-utils libglu1-mesa-dev freeglut3-dev mesa-common-dev
sudo apt install -y libglew-dev libglfw3-dev libglm-dev
sudo apt install -y libao-dev libmpg123-dev
sudo apt install -y libxinerama-dev libxi-dev libxcursor-dev
sudo apt install -y doxygen 
```

#### GLFW Setup
```
cd /usr/local/lib/
git clone https://github.com/glfw/glfw.git
cd glfw
cmake .
make
sudo make install
```

#### GLAD Setup

1. Head to https://glad.dav1d.de/
2. Set language to C++
3. Select gl version >3.3 and set profile to *Core* and select *Generate a Loader*
4. Click Generate
5. Download zip
6. Copy folders inside `include` i.e. `cp -R include/* /usr/include`
7. Copy `glad.c` to `src` (This is done but you should probably update this with whatever version you are using)


## Compile

```bash
mkdir build
cd build
cmake .. && make
```

## Run

```bash
$PROJECT_ROOT/build/release/bin/gameEngine
```
