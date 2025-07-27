## 🧱 FillLevelMonitor Module

This module handles trash bin fill-level detection using an ultrasonic sensor. It provides a simple interface to check whether the bin is full and can be extended to trigger alerts (e.g., buzzer or LED).

### 📦 Functions

#### `void binInit();`

Initializes the ultrasonic sensor and buzzer pins.
**Call this once in `setup()`.**

#### `bool binFull();`

Measures the distance to the trash and returns `true` if the bin is full (based on `TRASH_FULL_LEVEL` from `config.hpp`).
**Call this after sorting each waste item.**

---

### 🛠️ Usage Example

```cpp
#include "FillLevelMonitor.hpp"

void setup() {
    binInit();
}

void loop() {
    if (binFull()) {
        // Optional: beep or display warning
    }
}
```
---