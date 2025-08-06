#ifndef THHET_CONFIG_H
#define THHET_CONFIG_H

#define ONESHOT_TIMEOUT 5000

// How long before a key press becomes a hold
// Setting this to ≤100 makes home-row mods very hard to use since I end up
// holding a key naturally for 100 ms sometimes (especially with my LH).
// However, having it at the default makes modifier keys and the mouse a little
// harder to use since QMK isn't aware of keys pressed on the mouse.
#define TAPPING_TERM 160

// I hold some keys for a just a bit too long (especially "S" for some reason),
// so this lets me increase the tapping term on those keys.
#define TAPPING_TERM_PER_KEY

// I hold some keys for a just a bit too long (especially "S" for some reason),
// so this lets me increase the tapping term on those keys.
#define PERMISSIVE_HOLD

// Holding and releasing a dual-function key without pressing another key will result in nothing happening.
// With retro tapping enabled, releasing the key without pressing another will send the original keycode
// even if it is outside the tapping term.
#define RETRO_TAPPING

// Some common bigrams should have lower COMBO_TERMs so that I only activate the
// combo when I really mean to.
#define COMBO_TERM_PER_COMBO

#endif
