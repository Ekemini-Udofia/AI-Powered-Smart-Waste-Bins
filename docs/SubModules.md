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


---

## 🧠 ProximityLidController Module

The `ProximityLidController` handles smart lid automation for the AI-powered waste bin. It detects nearby humans using an ultrasonic sensor and opens the lid via a servo. It integrates with the `SmartSortEngine` to trigger waste recognition and with `FillLevelMonitor` to avoid opening when the bin is full.

---

### 🚀 Features

* **Ultrasonic-based proximity detection**
* **Servo-based lid control**
* **Auto-close mechanism**
* **Bin full detection + buzzer alert**
* **Automatic handoff to waste sorting**

---

### 🔧 Functions

#### `void PLCInit();`

Initializes the ultrasonic sensor, servo motor, buzzer, and allocates PWM timers.

#### `void senseProximity();`

Continuously monitors for nearby movement. Opens the lid and triggers sorting if the bin isn't full. Plays a warning beep if full.

---

### 🧠 Internal Logic

* If a person is detected within `DIST_TO_OPEN_LID`:

  * If bin is **full**, plays a double beep.
  * Else, opens the lid briefly and calls `SSETrigger()` to run waste classification.

---

### ⚠️ Notes

* Requires `config.hpp` to define pin mappings and thresholds.
* Relies on `SSETrigger()` from `SmartSortEngine` and `binFull()` from `FillLevelMonitor`.

---