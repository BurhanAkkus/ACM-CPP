#!/usr/bin/env python3
"""Verify f(S) for the ARC->CRA rewriting problem.

Usage:
    python3 verify.py STRING
    echo STRING | python3 verify.py
"""
import sys


def f(s: str) -> int:
    s = list(s)
    count = 0
    i = 0
    n = len(s)
    while i <= n - 3:
        if s[i] == 'A' and s[i + 1] == 'R' and s[i + 2] == 'C':
            s[i], s[i + 1], s[i + 2] = 'C', 'R', 'A'
            count += 1
            # a new ARC can only start at or before i, so step back
            i = max(i - 2, 0)
        else:
            i += 1
    return count


def main():
    if len(sys.argv) > 1:
        s = sys.argv[1]
    else:
        s = sys.stdin.readline().strip()

    s = s.strip()
    if not (1 <= len(s) <= 100):
        print(f"WARNING: length {len(s)} is outside [1, 100]", file=sys.stderr)
    if any(c not in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' for c in s):
        print("WARNING: string contains non-uppercase-letter characters", file=sys.stderr)

    result = f(s)
    print(result)


if __name__ == "__main__":
    main()
