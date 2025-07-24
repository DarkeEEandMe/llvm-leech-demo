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
