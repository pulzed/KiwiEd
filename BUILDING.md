## Building

### Linux
Build release: `./build.sh release`
Build debug: `./build.sh debug`

To generate compile_commands.json for clangd (you need this for autocompletion) add -c to build command:
`./build.sh debug -c` or `./build.sh release -c`

### Windows:
Run `build.bat`
