#include "dusk.h"
#include "scenes.h"

#define NUM_DEMOS 4

int main() {
    dusk_init_all();

    Scene demos[NUM_DEMOS] = {
        autumn_scene,
        fountain_scene,
        logo_scene,
        randbit_scene
    };
    int demo_ix = 0;

    dusk_scene_set(demos[demo_ix]);

    while (TRUE) {
        key_poll(); // update input
        if (key_hit(KEY_START)) {
            demo_ix = (demo_ix + 1) % NUM_DEMOS;
            dusk_scene_set(demos[demo_ix]);
        }

        dusk_scene_update();
    }
}