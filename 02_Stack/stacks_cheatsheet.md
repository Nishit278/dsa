## Stack Monotonic Patterns Cheatsheet (Arrays + Stacks)

### Types: `int`, `size_t`, and `static_cast`
- **`size_t`**:
  - Used by STL for `.size()`, `.capacity()`, `sizeof`, etc.
  - Unsigned and usually wider than `int` (e.g. 64‑bit on 64‑bit systems).
  - “Correct” type for sizes and indices because they are never negative.
- **`int` in DSA / CP code**:
  - Convenient and enough for typical constraints (up to about \(10^7\)–\(10^8\)).
  - You’ll often see loops like `for (int i = 0; i < n; ++i)` and we treat `n` as an `int`.
- **Why `static_cast<int>(...)` sometimes**:
  - `vector.size()` returns `size_t`, assigning directly to `int` is a narrowing conversion.
  - `int n = static_cast<int>(v.size());` says explicitly: *“I know I’m converting from size_t to int and I’m okay with it for these constraints.”*
  - This avoids/clarifies signed–unsigned warnings and keeps loops using `int` consistent.
- **Practical rule for you**:
  - In your DSA code, it’s fine to use `int` for sizes and loop counters and either:
    - Accept the implicit conversion, **or**
    - Use `static_cast<int>(...)` when you want to be explicit and silence warnings.
  - For very large data or production code, prefer `size_t` for sizes/indices and keep everything in that type.

### 1. Next Greater Element (NGE) to Right
- **Goal**: For each index \(i\), find the first element to its right that is strictly greater, or \(-1\) if none.
- **Pattern**: **Monotonic decreasing stack** (store values or indices, traverse from right to left).
- **Core idea**:
  - While stack top \(\leq\) current element, pop.
  - Answer is top of stack (or \(-1\) if stack empty).
- **Complexity**: \(O(n)\) time, \(O(n)\) space.

### 2. Next Greater to Left (NGL)
- **Goal**: For each index \(i\), first greater element on the **left**.
- **Pattern**: **Monotonic decreasing stack**, traverse left to right.
- **Core idea**:
  - While stack top \(\leq\) current element, pop.
  - Answer is top of stack (or \(-1\) if empty).
- **Same logic as NGE-right, just reversed direction**.

### 3. Next Smaller to Left (NSL)
- **Goal**: For each index \(i\), first smaller element on the **left**.
- **Pattern**: **Monotonic increasing stack**, traverse left to right.
- **Core idea**:
  - While stack top \(\geq\) current element, pop.
  - Answer is top (or \(-1\)).

### 4. Next Smaller to Right (NSR)
- **Goal**: For each index \(i\), first smaller element on the **right**.
- **Pattern**: **Monotonic increasing stack**, traverse right to left.
- **Core idea**:
  - While stack top \(\geq\) current element, pop.
  - Answer is top (or \(-1\)).

### 5. Largest Rectangle in Histogram
- **Goal**: Given bar heights, find max area rectangle in histogram.
- **Pattern**: Use **NSL/NSR indices** implicitly with a stack of indices.
- **Core idea**:
  - Iterate \(i = 0..n\) (extra step at end with sentinel).
  - While current bar is **lower or equal** than height at stack top:
    - Pop index; height = that bar.
    - Width = `i` if stack empty, else `i - st.top() - 1`.
    - Update `maxArea = max(maxArea, height * width)`.
  - Push current index.
- **Complexity**: \(O(n)\).

### 6. Stock Span
- **Goal**: For each day \(i\), count consecutive days (including today) with price \(\leq\) today’s price going backwards.
- **Pattern**: **Monotonic decreasing stack of (price, span)**.
- **Core idea**:
  - Start span = 1.
  - While stack top price \(\leq\) current price:
    - Add its span to current span and pop.
  - Push (current price, span).

### 7. Daily Temperatures
- **Goal**: For each day, number of days until a **warmer** temperature (or 0 if none).
- **Pattern**: **Next Greater to Right on values**, but return **distance (index difference)**.
- **Core idea**:
  - Traverse from right to left with stack of (temperature, index).
  - Pop while top temp \(\leq\) current.
  - If stack not empty, answer is `top.index - i`, else 0.

### 8. Car Fleet
- **Goal**: Number of car fleets that reach target, given positions and speeds.
- **Pattern**: Sort by position, process times as a **monotonic non-increasing sequence**.
- **Core idea**:
  - Compute time to target for each car: `(target - pos[i]) / speed[i]`.
  - Sort cars by position descending (process nearest to target first).
  - Walk from nearest to farthest, tracking `currMaxTime`:
    - If `time > currMaxTime`, new fleet and update `currMaxTime`.
    - Otherwise, car joins existing fleet.
- **This is conceptually like a monotonic stack on times**, but can be implemented with a single pass and running maximum.

### General Tips
- **When to think “monotonic stack”**:
  - Questions of “next/previous greater/smaller element”.
  - Range problems where each element wants its nearest bigger/smaller neighbor.
  - Histogram / range-maximum / subarray bound questions.
- **Implementation choices**:
  - Store **indices** when you need distances or widths.
  - Store **values** when you only need the neighbor value.
  - Store **(value, extraInfo)** (like span) to aggregate results in one pass.

