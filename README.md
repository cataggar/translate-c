# cataggar/translate-c

A GitHub source mirror of
[codeberg.org/ziglang/translate-c](https://codeberg.org/ziglang/translate-c).

## Branches

- `main` mirrors upstream `main`, preserving its original commits and history.
  It currently targets Zig 0.18 development; it is not the Zig 0.17 release pin.
- `mirror` is the default, orphan branch containing only mirror automation and
  documentation.

For Zig 0.17, translate-c 2.0.0 is pinned at
`0da7a16c3235b935b82421646076e0657cda21f6`. Its Aro dependency is preserved on
[`cataggar/arocc`'s `zig17` branch](https://github.com/cataggar/arocc/tree/zig17).
Source mirroring does not rewrite dependency URLs inside upstream commits.

## Synchronization

Upstream `main` is synchronized daily at 5:35 AM Central Time
(`America/Chicago`, including daylight saving time).

To synchronize manually:

```sh
gh workflow run sync-main.yml --repo cataggar/translate-c --ref mirror
```

The workflow can create `main` on its first run. It uses Git protocol v0, a
bounded fetch, job-scoped write permissions, and an explicit destination lease
to refuse overwriting a concurrent update. Fetch failures fail the job; they are
not reported as successful synchronization.
