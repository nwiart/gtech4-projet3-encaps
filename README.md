# Encapsulation project

Authors : Nathanaël VOGT, Noah WIART

## How to build

- Open the solution in Visual Studio 2022
- Select either `Debug_SDL` or `Debug_Raylib` configuration
	Note : The only difference is the default backend used if you don't specify any when running (see [Command parameters](#command-parameters)).
- Build `Game`. Its dependencies will be compiled automatically.

## How to run

- Navigate to `x64\Debug_SDL` or `x64\Debug_Raylib`
- Run either from the explorer by double-clicking `Game.exe`, or by running it from the command line.

### Command parameters

You can use `--sdl` or `--rl` to force the use of a specific backend.
If you don't, the configuration's default will be used.