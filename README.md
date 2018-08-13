
# Quantum Adapter for CoolQ

## Build Instruction

### Prerequisite

- Visual Studio 15 2017 (MSVC)
- Protobuf (vcpkg recommended: `vcpkg install protobuf protobuf:x64-windows`)

### Building

```batch
md build
cd build
cmake .. [cmake definitions to include protobuf]
cmake --build . --target INSTALL --config Release
```

note for self: `-DCMAKE_TOOLCHAIN_FILE=X:\usr\vcpkg\scripts\buildsystems\vcpkg.cmake`
