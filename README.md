\# JokrPushBack - VEX V5 Robot Project

PROS project for VEX V5 robotics competition.

## Prerequisites

This project requires the PROS toolchain and build system. Setup instructions differ between platforms.

### macOS Setup

1. Install PROS CLI:
   ```bash
   brew tap osx-cross/arm
   brew install arm-gcc-bin
   pip3 install pros-cli
   ```

2. Verify installation:
   ```bash
   pros --version
   ```

### Windows Setup

1. **Install PROS CLI for Windows:**
   - Download the PROS CLI installer from [pros.cs.purdue.edu](https://pros.cs.purdue.edu/v5/getting-started/index.html)
   - Run the installer which includes:
     - PROS CLI
     - ARM toolchain (arm-none-eabi-gcc)
     - Python with required packages
     - Make and other build tools

2. **Important:** Use the PROS integrated terminal or Git Bash for all commands, NOT Command Prompt or PowerShell.

3. **Verify installation:**
   ```bash
   pros --version
   arm-none-eabi-gcc --version
   make --version
   ```

### Linux Setup

1. Install dependencies:
   ```bash
   sudo apt-get install gcc-arm-none-eabi binutils-arm-none-eabi
   pip3 install pros-cli
   ```

2. Verify installation:
   ```bash
   pros --version
   ```

## Building the Project

### Quick Start

```bash
# Clone the repository
git clone https://github.com/Zoonoodle/JokrPushBack.git
cd JokrPushBack

# Standard optimized build (recommended)
make

# Fast development build (faster compilation, no optimization)
make fast

# Upload to robot
pros upload
```

### Build Targets

This project includes several optimized build configurations:

| Command | Speed | Optimization | Use Case |
|---------|-------|--------------|----------|
| `make` or `make quick` | Fast | O2, parallel | Default - best balance for development |
| `make fast` | Fastest | O0, parallel | Rapid iteration during active development |
| `make all` | Medium | O2, parallel | Clean build from scratch |
| `make help` | - | - | Show all available build targets |

### Build Optimizations

The project is configured with several optimizations for fast builds:

✅ **Automatic parallel compilation** - Uses all CPU cores automatically  
✅ **Debug symbols disabled** - Faster compilation (can re-enable with `-g` if needed)  
✅ **Incremental builds** - Only recompiles changed files  
✅ **Hot/cold linking** - Faster iteration on your code vs libraries  
✅ **Optional ccache support** - Even faster rebuilds if installed  

#### Performance Tips

1. **Use `make fast` during development** - Compiles 20-30% faster for rapid iteration
2. **Use `make` for final builds** - Better optimized code for competition
3. **Install ccache for even faster rebuilds:**
   ```bash
   # macOS
   brew install ccache
   
   # Linux
   sudo apt-get install ccache
   ```

#### Typical Build Times

- **Full build (clean):** ~2-3 seconds
- **Incremental build:** ~1-2 seconds  
- **With ccache (rebuild):** ~0.5-1 second

### Clean Build

```bash
make clean
# or
pros make clean
```

## Common Issues

### Windows: "command not found" errors
- **Solution:** Make sure you're using the PROS integrated terminal or Git Bash, not Command Prompt/PowerShell
- The PROS installer adds the ARM toolchain and make to the PATH, but only for certain shells

### Line Ending Issues
- **Solution:** The `.gitattributes` file ensures proper line endings (LF) for all source files
- If you still have issues, run: `git config core.autocrlf false` and re-clone

### Build Errors After Fresh Clone
- **Solution:** Try cleaning and rebuilding:
  ```bash
  make clean
  pros make
  ```

### "arm-none-eabi-gcc: not found"
- **macOS:** Reinstall ARM toolchain: `brew reinstall arm-gcc-bin`
- **Windows:** Reinstall PROS CLI from the official website
- **Linux:** `sudo apt-get install gcc-arm-none-eabi`

## Project Structure

```
.
├── include/          # Header files
│   ├── api.h
│   ├── autons.h
│   ├── intakeControl.h
│   ├── movement.h
│   └── robotConfigs.h
├── src/              # Source files
│   ├── main.cpp
│   ├── autons.cpp
│   ├── intakeControl.cpp
│   ├── movement.cpp
│   └── robotConfigs.cpp
├── firmware/         # PROS firmware files
└── Makefile          # Build configuration
```

## Development

### IDE Recommendations

- **Visual Studio Code** with the PROS extension (recommended for all platforms)
- **CLion** with Makefile project support

### Adding New Files

1. Add source files (`.cpp`) to `src/`
2. Add header files (`.h` or `.hpp`) to `include/`
3. The build system will automatically detect and compile them

## License

[Add your license here]

## Contributors

[Add contributors here]

