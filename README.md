# Enterprise add

Have you noticed how companies shove AI into ***EVERYTHING***? I find it very annoying. But why not roleplay as them?

This program, written in pure C99 uses machine learning to predict `a + b` because why the fuck not! Maybe companies
will adopt this enterprise add and incorporate it into their products because it's ✨ AI ✨

Watch how this two-neuron single-layer model was developed in 30 minutes on YouTube (live time): <https://www.youtube.com/watch?v=6md1n5KaHMo>

## Dependencies

- A C compiler
- GNU make
- OpenSSL
- A computer which can run thousands of passes of gradient descent and some extra

This could have absolutely no dependencies, but it's *enterprise*. You wouldn't get it.

## Licensing

Enterprise add is licensed under GPL-3.0-only by Ari Archer \<ari@ari.lt\>

## Running

For best 🚀 performance 🚀 run it like this:

```sh
export STRIP=llvm-strip
export STRIPFLAGS='--strip-debug --strip-sections --strip-unneeded -T --remove-section=.note.gnu.gold-version --remove-section=.note --strip-all --discard-locals --remove-section=.gnu.version --remove-section=.eh_frame --remove-section=.note.gnu.build-id --remove-section=.note.ABI-tag --strip-symbol=__gmon_start__ --strip-all-gnu --remove-section=.comment --remove-section=.eh_frame_ptr --discard-all'
export CC=clang
export CFLAGS='-Wpedantic -flto=full -fno-trapping-math -fstrict-aliasing -fno-math-errno -fno-stack-check -fno-strict-overflow -funroll-loops -fno-stack-protector -fvisibility-inlines-hidden -mfancy-math-387 -fomit-frame-pointer -fstrict-overflow -Wshadow -fno-exceptions -D_FORTIFY_SOURCE=0 -Wall -Wextra -fno-signed-zeros -fno-strict-aliasing -pedantic -Ofast -fvisibility=hidden -ffast-math -funsafe-math-optimizations -std=c99 -fno-asynchronous-unwind-tables -Werror -fdiscard-value-names -femit-all-decls -fmerge-all-constants -fno-use-cxa-atexit -fno-use-init-array -march=native -mtune=native -pedantic-errors'
make -j12
make strip
```

## Performance

The performance is very fast. It can add 2 + 3 with amazing accuracy only after 300 thousand epochs and a very miniscule precision loss of 0.03 but who cares about that - it's AI ✨:

    2.000000000000000 + 3.000000000000000 = ~4.977217190454309

It is a huge leap in the industry of adding two numbers together.
