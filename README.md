# LLVM LEECH: Weaponized CI Edition

This project demonstrates a weaponized LLVM plugin (`leech_pass.so`) that injects a malicious payload (`leech_payload`) into binaries during CI builds using GitHub Actions.

**Key Capabilities**:
- Zero-source-modification IR injection
- Payload executes at the entry of `main()`
- Sends a beacon to remote IP
- CI chain RCE simulation

To trigger:
- Push to this repo, or submit a PR using GitHub Actions

**Note**: For demonstration and educational use only.

# LLVM DIR for CMake

When building locally, set LLVM_DIR for your installed version:

    cmake -DLLVM_DIR=/usr/lib/llvm-18/lib/cmake/llvm ../src

Replace 18 with your local LLVM version as needed.
---

# LLVM_DIR Debug Build Note

During CI/CD setup, use the debug workflow to print every possible LLVMConfig.cmake path.  
Set LLVM_DIR to the directory containing LLVMConfig.cmake as printed in your build logs.

Example CMake call for LLVM 18:
    cmake -DLLVM_DIR=/usr/lib/llvm-18/lib/cmake/llvm ../src
