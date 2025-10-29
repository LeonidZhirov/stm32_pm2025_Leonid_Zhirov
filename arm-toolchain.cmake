# arm-toolchain-fixed.cmake
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR ARM)

set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/arm-none-eabi-gcc.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/arm-none-eabi-g++.exe")
set(CMAKE_ASM_COMPILER "C:/msys64/mingw64/bin/arm-none-eabi-gcc.exe")

# Критически важно для embedded
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# Явно указываем что это не Windows
set(CMAKE_C_COMPILER_ID GNU)
set(CMAKE_C_COMPILER_FRONTEND_VARIANT GNU)